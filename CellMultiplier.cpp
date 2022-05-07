// Copyright Aurelien Lubecki 2012

#include "CellMultiplier.h"
#include "Grid.h"

CellMultiplier::CellMultiplier(int multiplier, int score, int appearanceFrequency)
    : Cell(score, PATH_RESOURCES "multiplier.png", "Multiplicateur +" % QString::number(multiplier),
           CELL_TYPE_MULTIPLIER, appearanceFrequency, "Mutiplicateur"),
      _multiplier(multiplier),
      _labelMultiplier(00)
{
    assert(multiplier > 0);

    _labelMultiplier = new QLabel("+" % QString::number(multiplier), this);
    _labelMultiplier->setAlignment(Qt::AlignCenter);
    _labelMultiplier->setStyleSheet("QLabel {"
                                    "color:rgb(255, 255, 255);"
                                    "font-weight:bold;"
                                    "font-size:8px;"
                                    "background-color:rgb(0, 0, 0);"
                                    "border-radius:7px;"
                                    "}");
    _labelMultiplier->resize(15, 15);

    int side = 30; //(CELL_SPACING - CELL_SIZE)/2. + 1;
    _labelMultiplier->move(side, side);
    _labelMultiplier->show();
    _labelMultiplier->raise();
}

CellMultiplier::~CellMultiplier()
{
}

int CellMultiplier::getMultiplier() const
{
    return _multiplier;
}

Cell *CellMultiplier::clone() const
{
    return new CellMultiplier(_multiplier, getScore(), getAppearanceFrequency());
}

bool CellMultiplier::resolveEffect()
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

    _grid->addMultiplierInPlay(_multiplier);

    _isDeletedManually = true;

    _grid->deleteOneCell(*this);
    _grid->resolveGrid();

    return true;
}
