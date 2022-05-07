// Copyright Aurelien Lubecki 2012

#include "CellUltrasound.h"
#include "Grid.h"

CellUltrasound::CellUltrasound(int score, int appearanceFrequency)
    : Cell(score, PATH_RESOURCES "ultrasound.png", "Ultrasons", CELL_TYPE_ULTRASOUND, appearanceFrequency)
{
}

CellUltrasound::~CellUltrasound()
{
}

Cell *CellUltrasound::clone() const
{
    return new CellUltrasound(getScore(), getAppearanceFrequency());
}

bool CellUltrasound::resolveEffect()
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

    int nbw = _grid->getGridSize().width();
    int nbh = _grid->getGridSize().height();

    int nbIter = 200;
    int i = 0;
    Cell *chosenCell = 00;
    while (chosenCell == 00 || chosenCell->getType() < 0)
    {
        chosenCell = _grid->getCell(QRandomGenerator::global()->bounded(nbw), QRandomGenerator::global()->bounded(nbh));
        i++;

        if (i > nbIter)
        {
            assert(false);
            _grid->deleteOneCell(*this);
            _grid->resolveGrid();
            return true;
        }
    }

    QSet<Cell *> cellsToDelete;

    for (int y = 0; y < nbh; y++)
    {
        for (int x = 0; x < nbw; x++)
        {
            Cell *cell = _grid->getCell(x, y);
            if (cell != 00 && cell->getType() == chosenCell->getType())
            {
                cellsToDelete.insert(cell);
            }
        }
    }

    cellsToDelete.insert(this);

    _isDeletedManually = true;

    _grid->deleteCells(cellsToDelete);
    _grid->resolveGrid();

    return true;
}
