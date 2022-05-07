// Copyright Aurelien Lubecki 2012

#include "CellDynamite.h"
#include "Grid.h"

CellDynamite::CellDynamite(int score, int appearanceFrequency)
    : Cell(score, PATH_RESOURCES "dynamite.png", "Dynamite", CELL_TYPE_DYNAMITE, appearanceFrequency)
{
}

CellDynamite::~CellDynamite()
{
}

Cell *CellDynamite::clone() const
{
    return new CellDynamite(getScore(), getAppearanceFrequency());
}

bool CellDynamite::resolveEffect()
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
    locationsToAdd.append(QPoint(loc.x() - 1, loc.y() - 1));
    locationsToAdd.append(QPoint(loc.x(), loc.y() - 1));
    locationsToAdd.append(QPoint(loc.x() + 1, loc.y() - 1));
    locationsToAdd.append(QPoint(loc.x() - 1, loc.y()));
    locationsToAdd.append(loc);
    locationsToAdd.append(QPoint(loc.x() + 1, loc.y()));
    locationsToAdd.append(QPoint(loc.x() - 1, loc.y() + 1));
    locationsToAdd.append(QPoint(loc.x(), loc.y() + 1));
    locationsToAdd.append(QPoint(loc.x() + 1, loc.y() + 1));

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
