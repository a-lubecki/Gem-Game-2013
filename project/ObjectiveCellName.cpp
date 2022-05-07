// Copyright Aurelien Lubecki 2012

#include "ObjectiveCellName.h"
#include "Cell.h"

ObjectiveCellName::ObjectiveCellName(int objectiveValue, Cell &cellType)
    : AbstractObjective(objectiveValue), _cellType(cellType.clone())
{
    assert(_cellType != 00);
}

ObjectiveCellName::~ObjectiveCellName()
{
    if (_cellType != 00)
    {
        delete _cellType;
    }
}

void ObjectiveCellName::addCellsAsValue(const Play &play, const QSet<Cell *> &cells)
{
    foreach (Cell *cell, cells)
    {
        assert(cell != 00);

        if (QString::compare(cell->getName(), _cellType->getName()) == 0)
        {
            addValue(1);
        }
    }
}

QString ObjectiveCellName::getExplanationText() const
{
    int nb = getObjectiveValue();
    if (_cellType->getType() < 0)
    {
        return "Utiliser " % QString::number(nb) % " fois l'Item nommé \"" % _cellType->getName() % "\".";
    }

    QString plural("");
    if (nb != 1)
    {
        plural = "s";
    }
    return "Obtenir " % QString::number(nb) % " Gemme" % plural % " nommée" % plural % " \"" % _cellType->getName() % "\".";
}

AbstractObjective *ObjectiveCellName::clone() const
{
    return new ObjectiveCellName(getObjectiveValue(), *_cellType);
}
