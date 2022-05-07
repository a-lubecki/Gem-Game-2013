// Copyright Aurelien Lubecki 2012

#include "CellLaser.h"
#include "Grid.h"

CellLaser::CellLaser(int score, int appearanceFrequency)
    : Cell(score, PATH_RESOURCES "laser.png", "Laser", CELL_TYPE_LASER, appearanceFrequency)
{
}

CellLaser::~CellLaser()
{
}

Cell *CellLaser::clone() const
{
    return new CellLaser(getScore(), getAppearanceFrequency());
}

bool CellLaser::resolveEffect()
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

    const QPoint &loc = getLocationInGrid();
    QList<QPoint> locationsToAdd;

    int nbw = _grid->getGridSize().width();
    int nbh = _grid->getGridSize().height();
    for (int x = 0; x < nbw; x++)
    {
        locationsToAdd.append(QPoint(x, loc.y()));
    }
    for (int y = 0; y < nbh; y++)
    {
        locationsToAdd.append(QPoint(loc.x(), y));
    }

    QSet<Cell *> cellsToDelete;
    foreach (const QPoint &p, locationsToAdd)
    {
        Cell *cell = _grid->getCell(p);
        if (cell != 00)
        {
            cellsToDelete.insert(cell);
        }
    }
    assert(cellsToDelete.contains(this));

    _isDeletedManually = true;

    _grid->deleteCells(cellsToDelete);
    _grid->resolveGrid();

    return true;
}
