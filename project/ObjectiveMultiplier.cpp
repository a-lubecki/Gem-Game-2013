// Copyright Aurelien Lubecki 2012

#include "ObjectiveMultiplier.h"
#include "Cell.h"
#include "CellMultiplier.h"
#include "Play.h"

ObjectiveMultiplier::ObjectiveMultiplier(int objectiveValue)
    : AbstractObjective(objectiveValue)
{
    assert(getObjectiveValue() > 1);
}

ObjectiveMultiplier::~ObjectiveMultiplier()
{
}

void ObjectiveMultiplier::addCellsAsValue(const Play &play, const QSet<Cell *> &cells)
{
    int nbCellsToDelete = 0;

    foreach (Cell *cell, cells)
    {
        assert(cell != 00);
        if (cell->getType() < 0)
        {
            if (cell->isDeletedManually())
            {
                CellMultiplier *cellMultiplier = dynamic_cast<CellMultiplier *>(cell);
                if (cellMultiplier != 00)
                {
                    addValue(cellMultiplier->getMultiplier());
                    return;
                }
            }
            continue;
        }

        nbCellsToDelete++;
    }

    if (nbCellsToDelete > 3)
    {
        addValue(1);
    }
}

QString ObjectiveMultiplier::getExplanationText() const
{
    int value = getObjectiveValue();
    QString plural("");
    if (value != 1)
    {
        plural = "s";
    }
    return "Obtenir " % QString::number(value) % " multiplicateur" % plural % ".";
}

AbstractObjective *ObjectiveMultiplier::clone() const
{
    return new ObjectiveMultiplier(getObjectiveValue());
}
