//Copyright Aurelien Lubecki 2012

#include "ObjectiveCellCategory.h"
#include "Cell.h"
#include "CellPure.h"

ObjectiveCellCategory::ObjectiveCellCategory(int objectiveValue, Category category)
    : AbstractObjective(objectiveValue), _category(category)
{
}

ObjectiveCellCategory::~ObjectiveCellCategory()
{
}

void ObjectiveCellCategory::addCellsAsValue(const Play& play, const QSet<Cell*>& cells)
{
    if(_category == Item)
    {
        foreach(Cell* cell, cells)
        {
            assert(cell != 00);
            if(cell->getType() < 0)
            {
                addValue(1);
            }
        }
    }
    else if(_category == Gem)
    {
        foreach(Cell* cell, cells)
        {
            assert(cell != 00);
            if(cell->getType() >= 0)
            {
                addValue(1);
            }
        }
    }
    else
    {
        if(_category == NormalGem)
        {
            foreach(Cell* cell, cells)
            {
                assert(cell != 00);

                const CellPure* cellPure = dynamic_cast<const CellPure*>(cell);
                if(cell->getType() >= 0 && cellPure == 00)
                {
                    addValue(1);
                }
            }
        }
        else
        {
            assert(_category == PureGem);

            foreach(Cell* cell, cells)
            {
                assert(cell != 00);

                const CellPure* cellPure = dynamic_cast<const CellPure*>(cell);
                if(cell->getType() >= 0 && cellPure != 00)
                {
                    addValue(1);
                }
            }
        }
    }
}

QString ObjectiveCellCategory::getExplanationText() const
{
    int nb = getObjectiveValue();
    QString plural("");
    if(nb != 1)
    {
        plural = "s";
    }

    if(_category == Item)
    {
        return "Utiliser " % QString::number(nb) % " Item" % plural % ".";
    }

    if(_category == Gem)
    {
        return "Obtenir " % QString::number(nb) % " Gemme" % plural % ".";
    }

    if(_category == NormalGem)
    {
        return "Obtenir " % QString::number(nb) % " Gemme" % plural % " Normale" % plural % ".";
    }

    assert(_category == PureGem);

    return "Obtenir " % QString::number(nb) % " Gemme" % plural % " Pure" % plural % ".";
}

AbstractObjective* ObjectiveCellCategory::clone() const
{
    return new ObjectiveCellCategory(getObjectiveValue(), _category);
}
