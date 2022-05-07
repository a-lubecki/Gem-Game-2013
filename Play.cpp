// Copyright Aurelien Lubecki 2012

#include "Play.h"
#include "ui_Play.h"
#include "Grid.h"
#include "CellCounter.h"
#include "Cell.h"
#include "CellPure.h"
#include "AbstractObjective.h"

bool operator<(const Play::BundleScore &b1, const Play::BundleScore &b2)
{
    if (b1._level != b2._level)
    {
        return (b1._level < b2._level);
    }

    if (b1._score != b2._score)
    {
        return (b1._score < b2._score);
    }

    if (b1._totalTime != b2._totalTime)
    {
        return (b1._totalTime > b2._totalTime);
    }

    return (b1._date > b2._date);
}

bool operator>(const Play::BundleScore &b1, const Play::BundleScore &b2)
{
    if (b1._level != b2._level)
    {
        return (b1._level > b2._level);
    }

    if (b1._score != b2._score)
    {
        return (b1._score > b2._score);
    }

    if (b1._totalTime != b2._totalTime)
    {
        return (b1._totalTime < b2._totalTime);
    }

    return (b1._date < b2._date);
}

bool operator==(const Play::BundleScore &b1, const Play::BundleScore &b2)
{
    return (b1._name == b2._name &&
            b1._level == b2._level &&
            b1._score == b2._score &&
            b1._totalTime == b2._totalTime &&
            b1._date == b2._date);
}

bool operator!=(const Play::BundleScore &b1, const Play::BundleScore &b2)
{
    return !(b1 == b2);
}

QDataStream &operator<<(QDataStream &s, const Play::BundleScore &x)
{
    s << x._name
      << x._level
      << x._score
      << x._totalTime
      << x._date;

    return s;
}

QDataStream &operator>>(QDataStream &s, Play::BundleScore &x)
{
    s >> x._name >> x._level >> x._score >> x._totalTime >> x._date;

    return s;
}

Play::Play(QWidget *parent) : QMainWindow(parent),
                              ui(new Ui::Play),
                              _grid(00),
                              _cellCounters(),
                              _totalScore(0),
                              _currentLevel(-1),
                              _timer(),
                              _elapsedTimer(),
                              _elapsedAdded(0),
                              _maxTime(-1),
                              _isPaused(false),
                              _levelsObjectives(),
                              _currentObjective(00),
                              _maxTimeFirstLevel(),
                              _maxTimeLastLevel(),
                              _canScoreCells(false),
                              _multiplier(1),
                              _timerMultiplierDown(),
                              _canDownMultiplier(false),
                              _totalTime(),
                              _lastScore()
{
    ui->setupUi(this);

    setScore(0);

    setWindowState(windowState() | Qt::WindowFullScreen);

    ui->widgetMenu->hide();
    ui->widgetPlay->hide();
    ui->widgetTrophies->hide();
    ui->widgetHelp->hide();

    _timer.setSingleShot(false);
    _timer.setInterval(100);
    connect(&_timer, SIGNAL(timeout()),
            this, SLOT(updateBarTime()), Qt::UniqueConnection);

    _timerMultiplierDown.setSingleShot(false);
    _timerMultiplierDown.setInterval(5000);
    connect(&_timerMultiplierDown, SIGNAL(timeout()),
            this, SLOT(downMultiplier()), Qt::UniqueConnection);

    ui->labelEndMessage->hide();

    ui->tableWidget->setRowCount(MAX_NB_SCORES);
    QStringList heads;
    heads << "Joueur"
          << "Niveau"
          << "Score"
          << "Temps (min)"
          << "Date";
    ui->tableWidget->setColumnCount(heads.size());
    ui->tableWidget->setHorizontalHeaderLabels(heads);
    ui->tableWidget->setEnabled(false);

    _animatedTextMultiplier.setParent(this);
    _animatedTextLevel.setParent(this);
    _animatedTextTrophies.setParent(this);
}

Play::~Play()
{
    delete ui;

    if (_currentObjective != 00)
    {
        delete _currentObjective;
        _currentObjective = 00;
    }

    foreach (const QVector<const AbstractObjective *> &objectives, _levelsObjectives)
    {
        foreach (const AbstractObjective *obj, objectives)
        {
            assert(obj != 00);
            delete obj;
        }
    }
}

void Play::init(const QList<const Cell *> &initialCells,
                const QVector<QList<const AbstractObjective *> > &levelsObjectives,
                int maxTimeFirstLevel, int maxTimeLastLevel,
                const QList<Trophy *> &trophiesList)
{
    assert(_cellCounters.size() <= 0);

    foreach (const Cell *cell, initialCells)
    {
        assert(cell != 00);
        addInitialCellCopy(*cell);
    }

    _grid = new Grid(*this, QSize(10, 10), initialCells, this);
    ui->widgetGrid->layout()->addWidget(_grid);

    connect(ui->buttonStart, SIGNAL(pressed()),
            this, SLOT(startPlay()), Qt::UniqueConnection);
    connect(ui->buttonHelp, SIGNAL(pressed()),
            this, SLOT(showHelp()), Qt::UniqueConnection);
    connect(ui->buttonTrophies, SIGNAL(pressed()),
            this, SLOT(showTrophies()), Qt::UniqueConnection);
    connect(ui->buttonGiveUp, SIGNAL(pressed()),
            this, SLOT(giveUp()), Qt::UniqueConnection);
    connect(ui->widgetHelp, SIGNAL(closed()),
            this, SLOT(showMenu()), Qt::UniqueConnection);
    connect(ui->widgetTrophies, SIGNAL(closed()),
            this, SLOT(showMenu()), Qt::UniqueConnection);

    connect(ui->lineEditPlayerName, SIGNAL(textChanged(QString)),
            this, SLOT(updateStartButton()), Qt::UniqueConnection);
    connect(ui->lineEditPlayerName, SIGNAL(editingFinished()),
            this, SLOT(savePlayerName()), Qt::UniqueConnection);

    connect(_grid, SIGNAL(isReady()),
            this, SLOT(startTime()), Qt::UniqueConnection);

    loadPlayerName();
    loadAllScores();

    assert(levelsObjectives.size() > 0);

    _levelsObjectives.resize(levelsObjectives.size());
    int i = 0;
    foreach (const QList<const AbstractObjective *> &objectives, levelsObjectives)
    {
        assert(objectives.size() > 0);
        _levelsObjectives[i].resize(objectives.size());
        int j = 0;
        foreach (const AbstractObjective *obj, objectives)
        {
            assert(obj != 00);
            _levelsObjectives[i][j] = obj->clone();
            j++;
        }
        i++;
    }

    assert(maxTimeFirstLevel > maxTimeLastLevel);

    assert(maxTimeFirstLevel > 0);
    _maxTimeFirstLevel = maxTimeFirstLevel;
    assert(maxTimeLastLevel > 0);
    _maxTimeLastLevel = maxTimeLastLevel;

    ui->widgetHelp->init();
    ui->widgetTrophies->init(trophiesList);

    showMenu();
}

void Play::enableInterface(bool enable)
{
    ui->buttonGiveUp->setEnabled(enable);
    ui->buttonHelp->setEnabled(enable);
    ui->buttonStart->setEnabled(enable);
    ui->buttonTrophies->setEnabled(enable);

    ui->widgetHelp->enableInterface(enable);
    ui->widgetTrophies->enableInterface(enable);
}

void Play::addInitialCellCopy(const Cell &cellToAdd)
{
    CellCounter *counter = new CellCounter(cellToAdd, this);
    counter->show();

    const QString &name = cellToAdd.getName();
    assert(!_cellCounters.contains(name));
    _cellCounters.insert(name, counter);

    if (cellToAdd.getType() >= 0)
    {
        // normal cell
        const CellPure *cellPureToAdd = dynamic_cast<const CellPure *>(&cellToAdd);
        if (cellPureToAdd == 00)
        {
            // normal cell
            assert(ui->widgetCristals != 00);
            assert(ui->widgetCristals->layout() != 00);

            ui->widgetCristals->layout()->addWidget(counter);
        }
        else
        {
            // pure cell
            assert(ui->widgetPureCristals != 00);
            assert(ui->widgetPureCristals->layout() != 00);

            ui->widgetPureCristals->layout()->addWidget(counter);
        }
    }
    else
    {
        // special cell
        if (ui->widgetItems1->layout()->count() <= ui->widgetItems2->layout()->count())
        {
            ui->widgetItems1->layout()->addWidget(counter);
        }
        else
        {
            ui->widgetItems2->layout()->addWidget(counter);
        }
    }
}

void Play::setScore(int score)
{
    _totalScore = score;
    if (_totalScore < 0)
    {
        _totalScore = 0;
    }

    ui->labelTotalScore->setText(QString::number(_totalScore));
}

bool Play::scoreDeletedCells(const QSet<Cell *> &cells)
{
    if (!_canScoreCells)
    {
        return false;
    }

    int score = 0;
    int nbCellsScored = 0;

    foreach (Cell *cell, cells)
    {
        assert(cell != 00);

        if (cell->getType() < 0 && !cell->isDeletedManually())
        {
            continue;
        }

        _result.addCell(*cell);

        TEST(_grid->getCell(cell->getLocationInGrid()) != 00);
        const QString &name = cell->getName();

        TEST(_cellCounters.contains(name));

        CellCounter *counter = _cellCounters[name];
        TEST(counter != 00);

        counter->setNbCells(counter->getNbCells() + 1);

        int cellScore = cell->getScore();
        if (cellScore < 0)
        {
            score += cellScore;
        }
        else
        {
            score += _multiplier * cellScore;
        }

        nbCellsScored++;
    }

    int lastScore = _totalScore;
    setScore(_totalScore + score);
    _result.addScore(_totalScore - lastScore);

    assert(_currentObjective != 00);
    if (_currentObjective != 00)
    {
        _currentObjective->addCellsAsValue(*this, cells);
        ui->progressBarGoal->setValue(_currentObjective->getCurrentValue());

        if (_currentObjective->isObjectiveReached())
        {
            _canScoreCells = false;

            _timer.stop();
            if (_elapsedTimer.isValid())
            {
                _totalTime = _totalTime.addMSecs(_elapsedTimer.elapsed());
                qDebug() << "add 1 : " << _elapsedTimer.elapsed() << " = " << _totalTime.toString("hh:mm:ss.zzz");
            }

            _elapsedTimer.invalidate();

            _currentLevel++;

            if (_currentLevel >= _levelsObjectives.size())
            {
                QTimer::singleShot(1, this, SLOT(win()));
            }
            else
            {
                ui->widgetTrophies->addLevelResult(_result);
                _result.clearData();

                QTimer::singleShot(1, this, SLOT(startCurrentLevel()));
            }
        }
    }

    return true;
}

void Play::addTimePercentage(int timePercentage)
{
    if (!_elapsedTimer.isValid() || timePercentage <= 0)
    {
        return;
    }

    _timer.stop();

    int elapsed = _elapsedTimer.elapsed();
    _elapsedTimer.invalidate();

    if (timePercentage > 100)
    {
        assert(false);
        timePercentage = 100;
    }

    int rest = _maxTime - _elapsedAdded - elapsed + (_maxTime * timePercentage / 100.);
    if (rest > _maxTime)
    {
        rest = _maxTime;
    }

    _elapsedAdded = _maxTime - rest;

    _totalTime = _totalTime.addMSecs(elapsed);
    qDebug() << "add 2 : " << elapsed << " = " << _totalTime.toString("hh:mm:ss.zzz");

    _elapsedTimer.start();
    _timer.start();

    updateBarTime();
}

void Play::pauseTime()
{
    if (_isPaused)
    {
        assert(!_elapsedTimer.isValid());
        return;
    }

    _timer.stop();
    if (_elapsedTimer.isValid())
    {
        int elapsed = _elapsedTimer.elapsed();
        _elapsedTimer.invalidate();

        int rest = _maxTime - _elapsedAdded - elapsed;
        if (rest > _maxTime)
        {
            rest = _maxTime;
        }

        _elapsedAdded = _maxTime - rest;

        _totalTime = _totalTime.addMSecs(elapsed);
        qDebug() << "add 3 : " << elapsed << " = " << _totalTime.toString("hh:mm:ss.zzz");
    }

    _isPaused = true;
}

void Play::resumeTime()
{
    if (!_isPaused)
    {
        return;
    }

    _isPaused = false;

    _elapsedTimer.start();
    _timer.start();
}

void Play::downMultiplier()
{
    setMultiplier(getMultiplier() - 1);
    if (_canDownMultiplier)
    {
    }
    else
    {
        _canDownMultiplier = true;
    }
}

void Play::setMultiplier(int multiplier)
{
    _timerMultiplierDown.stop();

    int lastMultiplier = _multiplier;

    _multiplier = multiplier;
    if (_multiplier < 1)
    {
        _multiplier = 1;
    }
    else if (_multiplier > MAX_MULTIPLIER)
    {
        _multiplier = MAX_MULTIPLIER;
    }

    ui->labelMultiplier->setText("x" % QString::number(_multiplier));
    ui->labelMultiplier->setStyleSheet("QLabel {"
                                       "color:rgb(" %
                                       QString::number(255 * _multiplier / qreal(MAX_MULTIPLIER)) % ", 0, 0);"
                                                                                                    "font-size:" %
                                       QString::number(12 + _multiplier * 3) % "px;"
                                                                               "}");

    if (_multiplier > 1)
    {
        _canDownMultiplier = false;
        _timerMultiplierDown.start();
    }

    int diff = multiplier - lastMultiplier;
    if (diff != 0)
    {
        if (_multiplier <= 1)
        {
            _animatedTextMultiplier.showText("Multiplicateur Min");
        }
        else if (_multiplier >= MAX_MULTIPLIER)
        {
            _animatedTextMultiplier.showText("Multiplicateur Max");
        }
        else
        {
            if (diff > 0)
            {
                _animatedTextMultiplier.showText("Multiplicateur +" % QString::number(diff));
            }
            else
            {
                _animatedTextMultiplier.showText("Multiplicateur " % QString::number(diff));
            }
        }
    }
}

int Play::getMultiplier() const
{
    return _multiplier;
}

void Play::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    int y = 0.15 * height();

    _animatedTextMultiplier.move(QPoint(0.2 * width() - _animatedTextMultiplier.width() / 2., y - _animatedTextMultiplier.height() / 2.));
    _animatedTextLevel.move(QPoint(0.5 * width() - _animatedTextLevel.width() / 2., y - _animatedTextLevel.height() / 2.));
    _animatedTextTrophies.move(QPoint(0.8 * width() - _animatedTextTrophies.width() / 2., y - _animatedTextTrophies.height() / 2.));
}

void Play::startCurrentLevel()
{
    _timer.stop();
    _elapsedTimer.invalidate();
    _elapsedAdded = 0;

    ui->buttonGiveUp->setEnabled(false);

    _grid->clearGrid();

    _animatedTextMultiplier.hide();
    _animatedTextLevel.hide();
    _animatedTextTrophies.hide();

    assert(_currentLevel >= 0);
    assert(_currentLevel < _levelsObjectives.size());

    ui->labelLevel->setText("Niveau " % QString::number(_currentLevel) % "/" % QString::number(_levelsObjectives.size()));

    _maxTime = _maxTimeFirstLevel + (_maxTimeLastLevel - _maxTimeFirstLevel) * (_currentLevel / qreal(_levelsObjectives.size()));
    assert(_maxTime <= _maxTimeFirstLevel);
    assert(_maxTime >= _maxTimeLastLevel);

    ui->progressBarTime->setRange(0, _maxTime);
    ui->progressBarTime->setValue(_maxTime);
    updateBarTime();

    if (_currentObjective != 00)
    {
        delete _currentObjective;
        _currentObjective = 00;
    }
    const AbstractObjective *chosen = _levelsObjectives[_currentLevel][QRandomGenerator::global()->bounded(_levelsObjectives[_currentLevel].size())];
    assert(chosen != 00);
    _currentObjective = chosen->clone();

    ui->labelTextGoal->setText(_currentObjective->getExplanationText());
    ui->progressBarGoal->setRange(0, _currentObjective->getObjectiveValue());
    ui->progressBarGoal->setValue(0);

    _grid->initGrid();

    _canScoreCells = true;

    setMultiplier(0);

    if (_currentLevel > 0)
    {
        _animatedTextLevel.showText("Niveau Suivant");
    }
}

void Play::startTime()
{
    _elapsedTimer.start();
    _timer.start();

    if (_currentLevel <= 0)
    {
        _totalTime.setHMS(0, 0, 0);
    }
    _elapsedAdded = 0;
    _isPaused = false;

    ui->buttonGiveUp->setEnabled(true);
}

void Play::updateStartButton()
{
    ui->buttonStart->setEnabled(ui->lineEditPlayerName->text().size() > 0);
}

void Play::loadPlayerName()
{
    QFile f("./player");

    if (!f.open(QFile::ReadOnly))
    {
        return;
    }

    QTextStream in(&f);
    QString name;
    in >> name;

    f.close();

    ui->lineEditPlayerName->setText(name);
}

void Play::savePlayerName()
{
    QFile f("./player");

    if (!f.open(QFile::WriteOnly))
    {
        assert(false);
        return;
    }

    QTextStream out(&f);
    out << ui->lineEditPlayerName->text();

    f.close();
}

void Play::sortAllScores()
{
    if (_allScores.size() < 2)
    {
        return;
    }

    QList<BundleScore>::iterator it(_allScores.begin());
    while (it != _allScores.end() - 1)
    {
        QList<BundleScore>::iterator it2(it + 1);
        while (it2 != _allScores.end())
        {
            if (*it < *it2)
            {
                qSwap(*it, *it2);
            }

            ++it2;
        }

        ++it;
    }
}

void Play::updateAllScores()
{
    ui->tableWidget->clearSelection();

    int y = 0;
    foreach (const BundleScore &score, _allScores)
    {
        int x = 0;
        QTableWidgetItem *newItem;

        newItem = new QTableWidgetItem(score._name);
        ui->tableWidget->setItem(y, x++, newItem);

        newItem = new QTableWidgetItem(QString::number(score._level));
        ui->tableWidget->setItem(y, x++, newItem);

        newItem = new QTableWidgetItem(QString::number(score._score));
        ui->tableWidget->setItem(y, x++, newItem);

        newItem = new QTableWidgetItem(score._totalTime.toString("m:ss"));
        ui->tableWidget->setItem(y, x++, newItem);

        newItem = new QTableWidgetItem(score._date.toString("dd/MM/yyyy - hh:mm:ss"));
        ui->tableWidget->setItem(y, x++, newItem);

        if (score == _lastScore)
        {
            ui->tableWidget->selectRow(y);
        }

        y++;
    }

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->tableWidget->horizontalHeader()->resizeSection(0, 60);
    ui->tableWidget->horizontalHeader()->resizeSection(1, 60);
    ui->tableWidget->horizontalHeader()->resizeSection(2, 60);
    ui->tableWidget->horizontalHeader()->resizeSection(3, 90);
}

void Play::loadAllScores()
{
    QFile f("./scores");

    if (!f.open(QFile::ReadOnly))
    {
        updateAllScores();
        return;
    }

    QDataStream in(&f);
    in.setVersion(QDataStream::Qt_4_8);
    in >> _allScores;

    f.close();

    updateAllScores();
}

void Play::saveAllScores()
{
    QFile f("./scores");

    if (!f.open(QFile::WriteOnly))
    {
        assert(false);
        return;
    }

    QDataStream out(&f);
    out.setVersion(QDataStream::Qt_4_8);
    out << _allScores;

    f.close();
}

void Play::showMenu()
{
    enableInterface(false);

    ui->widgetPlay->hide();
    ui->widgetHelp->hide();
    ui->widgetTrophies->hide();

    ui->widgetMenu->show();

    ui->buttonHelp->setEnabled(true);
    ui->buttonTrophies->setEnabled(true);
    ui->buttonStart->setEnabled(true);
}

void Play::showPlay()
{
    enableInterface(false);

    ui->widgetMenu->hide();
    ui->widgetHelp->hide();
    ui->widgetTrophies->hide();

    ui->widgetPlay->show();
}

void Play::showHelp()
{
    enableInterface(false);

    ui->widgetMenu->hide();
    ui->widgetTrophies->hide();
    ui->widgetPlay->hide();

    ui->widgetHelp->show();

    ui->widgetHelp->enableInterface(true);
}

void Play::showTrophies()
{
    enableInterface(false);

    ui->widgetMenu->hide();
    ui->widgetHelp->hide();
    ui->widgetPlay->hide();

    ui->widgetTrophies->show();

    ui->widgetTrophies->enableInterface(true);
}

void Play::startPlay()
{
    showPlay();

    setScore(0);

    foreach (CellCounter *counter, _cellCounters)
    {
        assert(counter != 00);
        counter->setNbCells(0);
    }

    _currentLevel = 0;
    startCurrentLevel();
}

void Play::stopPlay()
{
    ui->buttonGiveUp->setEnabled(false);

    _timer.stop();
    if (_elapsedTimer.isValid())
    {
        _totalTime = _totalTime.addMSecs(_elapsedTimer.elapsed());
        qDebug() << "add 4 : " << _elapsedTimer.elapsed() << " = " << _totalTime.toString("hh:mm:ss.zzz");

        _elapsedTimer.invalidate();
    }

    _result.addTime(_totalTime.hour() * 3600000 +
                    _totalTime.minute() * 60000 +
                    _totalTime.second() * 1000 +
                    _totalTime.msec());

    _isPaused = false;

    setMultiplier(1);
    _timerMultiplierDown.stop();

    ui->labelEndMessage->hide();

    _animatedTextMultiplier.hide();
    _animatedTextTrophies.hide();
    _animatedTextLevel.showText("Jeu terminé");

    _grid->clearGrid();

    ui->widgetTrophies->addLevelResult(_result);
    _result.clearData();

    QTimer::singleShot(1500, this, SLOT(showMenu()));
}

void Play::updateBarTime()
{
    int rest = _maxTime - _elapsedAdded;

    if (_elapsedTimer.isValid())
    {
        rest -= _elapsedTimer.elapsed();

        if (rest < 0)
        {
            _canScoreCells = false;
            lose();
            return;
        }
    }
    else
    {
        if (rest < 0)
        {
            rest = 0;
        }
    }

    ui->progressBarTime->setValue(rest);

    if (rest >= 0.5 * _maxTime)
    {
        ui->progressBarTime->setStyleSheet("#progressBarTime::chunk {"
                                           "background-color: qradialgradient(spread:pad, cx:0.5, cy:0, radius:1.5, fx:0.5, fy:0,"
                                           "stop:0 rgb(100, 255, 100),"
                                           "stop:1 rgb(50, 150, 50));"
                                           "border:1px solid rgb(0, 70, 0);"
                                           "}");
    }
    else if (rest >= 0.25 * _maxTime)
    {
        ui->progressBarTime->setStyleSheet("#progressBarTime::chunk {"
                                           "background-color: qradialgradient(spread:pad, cx:0.5, cy:0, radius:1.5, fx:0.5, fy:0,"
                                           "stop:0 rgb(255, 255, 100),"
                                           "stop:1 rgb(150, 150, 50));"
                                           "border:1px solid rgb(70, 70, 0);"
                                           "}");
    }
    else
    {
        ui->progressBarTime->setStyleSheet("#progressBarTime::chunk {"
                                           "background-color: qradialgradient(spread:pad, cx:0.5, cy:0, radius:1.5, fx:0.5, fy:0,"
                                           "stop:0 rgb(255, 100, 100),"
                                           "stop:1 rgb(150, 50, 50));"
                                           "border:1px solid rgb(70, 0, 0);"
                                           "}");
    }
}

void Play::win()
{
    _result.win();
    stopPlay();

    ui->labelEndMessage->setText("Félicitation ! Vous avez terminé tous les niveaux");
    ui->labelEndMessage->setStyleSheet("QLabel {"
                                       "color:rgb(0, 150, 0);"
                                       "}");
    ui->labelEndMessage->show();

    addNewScore();
}

void Play::lose()
{
    _result.lose();
    stopPlay();

    ui->labelEndMessage->setText("Vous avez perdu au niveau " % QString::number(_currentLevel));
    ui->labelEndMessage->setStyleSheet("QLabel {"
                                       "color:rgb(150, 0, 0);"
                                       "}");
    ui->labelEndMessage->show();

    addNewScore();
}

void Play::giveUp()
{
    _result.giveUp();
    stopPlay();
}

void Play::addNewScore()
{
    _lastScore._name = ui->lineEditPlayerName->text();
    _lastScore._level = _currentLevel;
    _lastScore._score = _totalScore;
    _lastScore._totalTime = _totalTime;
    _lastScore._date = QDateTime::currentDateTime();
    _allScores.prepend(_lastScore);

    sortAllScores();

    if (_allScores.size() > MAX_NB_SCORES)
    {
        _allScores.removeLast();
    }

    updateAllScores();

    saveAllScores();
}
