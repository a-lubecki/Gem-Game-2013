// Copyright Aurelien Lubecki 2012

#include "ObjectiveCellType.h"
#include "Cell.h"

ObjectiveCellType::ObjectiveCellType(int objectiveValue, Cell &cellType)
    : AbstractObjective(objectiveValue), _cellType(cellType.clone())
{
    assert(_cellType != 00);
}

ObjectiveCellType::~ObjectiveCellType()
{
    if (_cellType != 00)
    {
        delete _cellType;
    }
}

void ObjectiveCellType::addCellsAsValue(const Play &play, const QSet<Cell *> &cells)
{
    foreach (Cell *cell, cells)
    {
        assert(cell != 00);

        if (cell->getType() == _cellType->getType())
        {
            addValue(1);
        }
    }
}

QString ObjectiveCellType::getExplanationText() const
{
    int nb = getObjectiveValue();
    if (_cellType->getType() < 0)
    {
        return "Utiliser " % QString::number(nb) % " fois un Item de type " % _cellType->getTypeName() % ".";
    }

    QString plural("");
    if (nb != 1)
    {
        plural = "s";
    }
    return "Obtenir " % QString::number(nb) % " Gemme" % plural % " de type " % _cellType->getTypeName() % ".";
}

AbstractObjective *ObjectiveCellType::clone() const
{
    return new ObjectiveCellType(getObjectiveValue(), *_cellType);
}
