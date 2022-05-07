// Copyright Aurelien Lubecki 2012

#include "CellTime.h"
#include "Grid.h"

CellTime::CellTime(int timePercentage, int score, int appearanceFrequency)
    : Cell(score, PATH_RESOURCES "time.png", "Temps +" % QString::number(timePercentage) % "%",
           CELL_TYPE_TIME, appearanceFrequency, "Temps"),
      _timePercentage(timePercentage),
      _labelPercentage(00)
{
    assert(_timePercentage > 0);
    assert(_timePercentage <= 100);

    _labelPercentage = new QLabel(QString::number(timePercentage), this);
    _labelPercentage->setAlignment(Qt::AlignCenter);
    _labelPercentage->setStyleSheet("QLabel {"
                                    "color:rgb(255, 255, 255);"
                                    "font-weight:bold;"
                                    "font-size:8px;"
                                    "background-color:rgb(0, 0, 0);"
                                    "border-radius:7px;"
                                    "}");
    _labelPercentage->resize(15, 15);

    int side = 30; //(CELL_SPACING - CELL_SIZE)/2. + 1;
    _labelPercentage->move(side, side);
    _labelPercentage->show();
    _labelPercentage->raise();
}

CellTime::~CellTime()
{
}

Cell *CellTime::clone() const
{
    return new CellTime(_timePercentage, getScore(), getAppearanceFrequency());
}

bool CellTime::resolveEffect()
{
    TEST(_grid != 00);

    Cell *selected = _grid->getSelectedCell();
    if (selected != 00 &&
        (selected == _grid->getCellUp(*this) ||
         selected == _grid->getCellDown(*this) ||
         selected == _grid->getCellRight(*this) ||
         selected == _grid->getCellLeft(*this)))
    {
        Cell::resolveEffect();
        return true;
    }

    _grid->setHoveredCell(00);
    _grid->setSelectedCell(00);

    _grid->addTimePercentageInPlay(_timePercentage);

    _isDeletedManually = true;

    _grid->deleteOneCell(*this);
    _grid->resolveGrid();

    return true;
}
