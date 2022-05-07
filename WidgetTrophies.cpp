//Copyright Aurelien Lubecki 2012

#include "WidgetTrophies.h"
#include "ui_WidgetTrophies.h"
#include "TrophyCommon.h"

WidgetTrophies::WidgetTrophies(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::WidgetTrophies),
    _trophies(),
    _selectedTrophy(00),
    _hoveredTrophy(00)
{
    ui->setupUi(this);

    enableInterface(false);
}

WidgetTrophies::~WidgetTrophies()
{
    delete ui;
}

void WidgetTrophies::init(const QList<Trophy*>& trophiesList)
{
    connect(ui->buttonReturn, SIGNAL(pressed()),
            this, SLOT(closeTrophies()), Qt::UniqueConnection);

    QLayout* layout = ui->widgetAllTrophies->layout();
    assert(layout != 00);
    QGridLayout* grid = dynamic_cast<QGridLayout*>(layout);
    assert(grid != 00);

    int NB_COLUMNS = 5;

    int NB_ROWS = trophiesList.size() / float(NB_COLUMNS);
    if(trophiesList.size() % NB_COLUMNS != 0)
    {
        NB_ROWS++;
    }

    QList<Trophy*>::const_iterator it(trophiesList.constBegin());

    int num = 1;
    _trophies.resize(NB_ROWS);
    for(int y=0;y<NB_ROWS;y++)
    {
        _trophies[y].resize(NB_COLUMNS);

        for(int x=0;x<NB_COLUMNS;x++)
        {
            if(it == trophiesList.constEnd())
            {
                break;
            }

            Trophy* trophy = (*it);
            assert(trophy != 00);
            TrophyNbTrophies* tnt = dynamic_cast<TrophyNbTrophies*>(trophy);
            if(tnt != 00)
            {
                foreach(Trophy* t, trophiesList)
                {
                    assert(t != 00);
                    if(t != tnt)
                    {
                        connect(t, SIGNAL(trophyWon(int)),
                            tnt, SLOT(addTrophy(int)), Qt::UniqueConnection);
                    }
                }
            }

            trophy->setNumber(num++);
            trophy->setWidgetTrophies(*this);
            trophy->show();
            trophy->setPos(x, y);

            _trophies[y][x] = trophy;
            grid->addWidget(trophy, y, x);

            ++it;
        }

        if(it == trophiesList.constEnd())
        {
            break;
        }
    }

    updateNbTotalTrophies();
}

void WidgetTrophies::updateNbTotalTrophies()
{
    int bronze = 0;
    int silver = 0;
    int gold = 0;
    int platinum = 0;

    int nbTotal = 0;
    int nbTotalObtained = 0;

    foreach(const QVector<Trophy*>& rows, _trophies)
    {
        foreach(const Trophy* trophy, rows)
        {
            if(trophy == 00)
            {
                continue;
            }

            nbTotal++;

            if(trophy->isObjectiveReached(Trophy::Bronze))
            {
                bronze++;
                nbTotalObtained++;
            }
            if(trophy->isObjectiveReached(Trophy::Silver))
            {
                silver++;
                nbTotalObtained++;
            }
            if(trophy->isObjectiveReached(Trophy::Gold))
            {
                gold++;
                nbTotalObtained++;
            }
            if(trophy->isObjectiveReached(Trophy::Platinum))
            {
                platinum++;
                nbTotalObtained++;
            }
        }
    }

    ui->labelNbBronze->setText(QString::number(bronze));
    ui->labelNbSilver->setText(QString::number(silver));
    ui->labelNbGold->setText(QString::number(gold));
    ui->labelNbPlatinum->setText(QString::number(platinum));

    ui->labelNbTotal->setText("Total : " % QString::number(nbTotal) %
                              "      Complété : " % QString::number(int(100 * nbTotalObtained / qreal(nbTotal*4))) % "%");

    QMap<Trophy::TrophyImportance, int> mapNb;
    mapNb.insert(Trophy::Bronze, bronze);
    mapNb.insert(Trophy::Silver, silver);
    mapNb.insert(Trophy::Gold, gold);
    mapNb.insert(Trophy::Platinum, platinum);
    emit trophiesNumberChanged(mapNb);
}

void WidgetTrophies::updateTrophy(int x, int y)
{
    assert(y >= 0 && y < _trophies.size());
    assert(x >= 0 && x < _trophies[y].size());

    _trophies[y][x]->showTextObtained(true);

    updateNbTotalTrophies();
}

void WidgetTrophies::addLevelResult(const LevelResult& result)
{
    foreach(const QVector<Trophy*>& rows, _trophies)
    {
        foreach(Trophy* trophy, rows)
        {
            if(trophy != 00)
            {
                trophy->addLevelResult(result);
            }
        }
    }
}

void WidgetTrophies::enableInterface(bool enabled)
{
    ui->widgetAllTrophies->setEnabled(enabled);
    ui->buttonReturn->setEnabled(enabled);
}

void WidgetTrophies::setVisible(bool visible)
{
    QFrame::setVisible(visible);

    if(isVisible())
    {
        assert(_trophies.size() > 0);
        assert(_trophies[0].size() > 0);
        selectTrophy(0, 0);
        ui->scrollArea->ensureVisible(0, 0);
    }
}

void WidgetTrophies::initProgressBar(QProgressBar* bar, int min, int max, int value)
{
    assert(bar != 00);

    if(value > max)
    {
        value = max;
    }

    bar->setRange(min, max);
    bar->setValue(value);

    if(value >= max)
    {
        bar->setStyleSheet(
                    "QProgressBar {"
                        "background-color:qradialgradient(spread:pad, cx:0.5, cy:0, radius:1.5, fx:0.5, fy:0, stop:0 rgb(255, 255, 255), stop:1 rgb(50, 130, 150));"
                    "}"
                    "QProgressBar::chunk {"
                        "background-color:transparent;"
                        "border:none;"
                    "}");
    }
    else
    {
        bar->setStyleSheet("");
    }
}

void WidgetTrophies::selectTrophy(int x, int y)
{
    assert(x >= 0);
    assert(y >= 0);


    Trophy* trophy = _trophies[y][x];
    assert(trophy != 00);

    if(_selectedTrophy != 00)
    {
        _selectedTrophy->highlightTrophy(false);
        _selectedTrophy->setCursor(QCursor(Qt::PointingHandCursor));
    }

    trophy->highlightTrophy(true);
    trophy->showTextObtained(false);
    trophy->unsetCursor();
    _selectedTrophy = trophy;

    ui->labelName->setText(QString::number(trophy->getNumber()) % " - " % trophy->getName());

    ui->labelExplBronze->setText(trophy->getExplanationText(Trophy::Bronze));
    ui->labelExplSilver->setText(trophy->getExplanationText(Trophy::Silver));
    ui->labelExplGold->setText(trophy->getExplanationText(Trophy::Gold));
    ui->labelExplPlatinum->setText(trophy->getExplanationText(Trophy::Platinum));

    initProgressBar(ui->progressBarBronze, 0, trophy->getObjectiveValue(Trophy::Bronze), trophy->getCurrentValue());
    initProgressBar(ui->progressBarSilver, 0, trophy->getObjectiveValue(Trophy::Silver), trophy->getCurrentValue());
    initProgressBar(ui->progressBarGold, 0, trophy->getObjectiveValue(Trophy::Gold), trophy->getCurrentValue());
    initProgressBar(ui->progressBarPlatinum, 0, trophy->getObjectiveValue(Trophy::Platinum), trophy->getCurrentValue());

}

void WidgetTrophies::hoverTrophy(int x, int y)
{
    assert(x >= 0);
    assert(y >= 0);


    Trophy* trophy = _trophies[y][x];
    assert(trophy != 00);

    unhoverCurrentTrophy();

    trophy->highlightTrophy(true);
    _hoveredTrophy = trophy;
}

void WidgetTrophies::unhoverCurrentTrophy()
{
    if(_hoveredTrophy != 00 && _hoveredTrophy != _selectedTrophy)
    {
        _hoveredTrophy->highlightTrophy(false);
    }

    _hoveredTrophy = 00;
}

void WidgetTrophies::closeTrophies()
{
    enableInterface(false);

    emit closed();
}
