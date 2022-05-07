// Copyright Aurelien Lubecki 2012

#include "Trophy.h"
#include "ui_Trophy.h"
#include "AbstractObjective.h"
#include "WidgetTrophies.h"

Trophy::Trophy(const QString &name, const QVector<int> &objectiveValues) : QWidget(00),
                                                                           ui(new Ui::Trophy),
                                                                           _x(0),
                                                                           _y(0),
                                                                           _name(),
                                                                           _objectiveValues(objectiveValues),
                                                                           _currentValue(0),
                                                                           _isIncreasing(false),
                                                                           _widgetTrophies(00)
{
    ui->setupUi(this);

    hide();

    setCursor(QCursor(Qt::PointingHandCursor));

    setName(name);

    assert(_objectiveValues.size() == NB_TROPHY_IMPORTANCES);
    assert(_objectiveValues.size() > 2);

    _isIncreasing = (_objectiveValues[0] < _objectiveValues[1]);

    int lastValue = _objectiveValues[0];
    int nb = _objectiveValues.size() - 1;
    for (int i = 1; i < nb; i++)
    {
        int val = _objectiveValues[i];
        assert(val > 0);
        if (_isIncreasing)
        {
            assert(val > lastValue);
        }
        else
        {
            assert(val < lastValue);
        }
        lastValue = val;
    }

    _labelObtained = new QLabel("Obtenu !", this);
    _labelObtained->setAlignment(Qt::AlignCenter);
    _labelObtained->hide();
    _labelObtained->setStyleSheet(
        "QLabel {"
        "color:rgb(50, 200, 50);"
        "background-color:rgba(255, 255, 255, 200);"
        "border:2px solid rgb(50, 200, 50);"
        "border-radius:15px;"
        "font-weight:bold;"
        "font-size:12px;"
        "}");
    _labelObtained->resize(70, 30);
    _labelObtained->move(width() / 2. - _labelObtained->width() / 2.,
                         height() / 2. - _labelObtained->height() / 2.);

    init(0);
}

Trophy::~Trophy()
{
    delete ui;
}

void Trophy::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    _widgetTrophies->selectTrophy(_x, _y);
}

void Trophy::enterEvent(QEnterEvent *event)
{
    QWidget::enterEvent(event);

    _widgetTrophies->hoverTrophy(_x, _y);
}

void Trophy::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);

    _widgetTrophies->unhoverCurrentTrophy();
}

void Trophy::setName(const QString &name)
{
    _name = name;
    ui->labelName->setText(name);
}

void Trophy::setNumber(int number)
{
    assert(number > 0);
    _number = number;
    ui->labelNum->setText(QString::number(number));
}

void Trophy::setWidgetTrophies(WidgetTrophies &parent)
{
    _widgetTrophies = &parent;
    setParent(_widgetTrophies);
}

void Trophy::init(int value)
{
    bool canHaveNextImportance = true;
    TrophyImportance lastImportance = NB_TROPHY_IMPORTANCES;
    if (isObjectiveReached(Platinum))
    {
        canHaveNextImportance = false;
        lastImportance = Platinum;
    }
    else if (isObjectiveReached(Gold))
    {
        lastImportance = Gold;
    }
    else if (isObjectiveReached(Silver))
    {
        lastImportance = Silver;
    }
    else if (isObjectiveReached(Bronze))
    {
        lastImportance = Bronze;
    }

    _currentValue = value;
    if (_currentValue < 0)
    {
        _currentValue = 0;
    }
    else if (_currentValue > getObjectiveValue(Platinum))
    {
        _currentValue = getObjectiveValue(Platinum);
    }

    bool mustUpdate = false;
    if (canHaveNextImportance)
    {
        if (lastImportance == NB_TROPHY_IMPORTANCES)
        {
            if (isObjectiveReached(Bronze) ||
                isObjectiveReached(Silver) ||
                isObjectiveReached(Gold) ||
                isObjectiveReached(Platinum))
            {
                mustUpdate = true;
            }
        }
        else if (lastImportance == Bronze)
        {
            if (isObjectiveReached(Silver) ||
                isObjectiveReached(Gold) ||
                isObjectiveReached(Platinum))
            {
                mustUpdate = true;
            }
        }
        else if (lastImportance == Silver)
        {
            if (isObjectiveReached(Gold) ||
                isObjectiveReached(Platinum))
            {
                mustUpdate = true;
            }
        }
        else if (lastImportance == Gold)
        {
            if (isObjectiveReached(Platinum))
            {
                mustUpdate = true;
            }
        }
    }

    if (mustUpdate)
    {
        _widgetTrophies->updateTrophy(getX(), getY());

        if (isObjectiveReached(Platinum))
        {
            emit trophyWon(Platinum);
        }
        else if (isObjectiveReached(Gold))
        {
            emit trophyWon(Gold);
        }
        else if (isObjectiveReached(Silver))
        {
            emit trophyWon(Silver);
        }
        else if (isObjectiveReached(Bronze))
        {
            emit trophyWon(Bronze);
        }
    }

    int numerator = 0;
    int denominator = 0;
    foreach (int obj, _objectiveValues)
    {
        int val = _currentValue;
        if (val > obj)
        {
            val = obj;
        }
        numerator += val;
        denominator += obj;
    }

    ui->labelPercentage->setText(QString::number(int((numerator * 100) / qreal(denominator))) % "%");

    if (!isObjectiveReached(Bronze))
    {
        ui->labelImage->setPixmap(QPixmap(PATH_RESOURCES "trophy_neutral.png"));
    }
    else if (!isObjectiveReached(Silver))
    {
        ui->labelImage->setPixmap(QPixmap(PATH_RESOURCES "trophy_bronze.png"));
    }
    else if (!isObjectiveReached(Gold))
    {
        ui->labelImage->setPixmap(QPixmap(PATH_RESOURCES "trophy_silver.png"));
    }
    else if (!isObjectiveReached(Platinum))
    {
        ui->labelImage->setPixmap(QPixmap(PATH_RESOURCES "trophy_gold.png"));
    }
    else
    {
        ui->labelImage->setPixmap(QPixmap(PATH_RESOURCES "trophy_platinum.png"));
    }
}

void Trophy::setPos(int x, int y)
{
    _x = x;
    assert(_x >= 0);
    _y = y;
    assert(_y >= 0);
}

void Trophy::addLevelResult(const LevelResult &result)
{
}

void Trophy::addValue(int value)
{
    if (value <= 0)
    {
        return;
    }
    init(_currentValue + value);
}

const QString &Trophy::getName() const
{
    return _name;
}

int Trophy::getNumber() const
{
    return _number;
}

bool Trophy::isObjectiveReached(TrophyImportance importance) const
{
    if (_isIncreasing)
    {
        return (_currentValue >= _objectiveValues[importance]);
    }
    if (_currentValue <= 0)
    {
        return false;
    }
    return (_currentValue <= _objectiveValues[importance]);
}

int Trophy::getObjectiveValue(TrophyImportance importance) const
{
    return _objectiveValues[importance];
}

int Trophy::getCurrentValue() const
{
    return _currentValue;
}

int Trophy::getX() const
{
    return _x;
}

int Trophy::getY() const
{
    return _y;
}

void Trophy::highlightTrophy(bool highlight)
{
    if (highlight)
    {
        ui->widget->setStyleSheet("#widget {"
                                  "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, "
                                  "stop:0 rgba(255, 255, 255, 200), "
                                  "stop:1 rgba(150, 150, 150, 100));"
                                  "}"
                                  "#labelName, #labelPercentage {"
                                  "background-color:qradialgradient(spread:pad, cx:0.5, cy:0, radius:1.5, fx:0.5, fy:0, "
                                  "stop:0 rgb(255, 255, 255),"
                                  "stop:1 rgb(50, 130, 150));"
                                  "border:1px solid rgb(0, 70, 100);"
                                  "color:rgb(0, 0, 0);"
                                  "}");
    }
    else
    {
        ui->widget->setStyleSheet("");
    }
}

void Trophy::showTextObtained(bool show)
{
    _labelObtained->setVisible(show);
}
