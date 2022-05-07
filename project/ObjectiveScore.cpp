// Copyright Aurelien Lubecki 2012

#include "ObjectiveScore.h"
#include "Cell.h"
#include "Play.h"

ObjectiveScore::ObjectiveScore(int objectiveValue)
    : AbstractObjective(objectiveValue)
{
    assert(getObjectiveValue() > 1);
}

ObjectiveScore::~ObjectiveScore()
{
}

void ObjectiveScore::addCellsAsValue(const Play &play, const QSet<Cell *> &cells)
{
    foreach (Cell *cell, cells)
    {
        assert(cell != 00);

        addValue(cell->getScore() * play.getMultiplier());
    }
}

QString ObjectiveScore::getExplanationText() const
{
    return "Obtenir un score de " % QString::number(getObjectiveValue()) % " points.";
}

AbstractObjective *ObjectiveScore::clone() const
{
    return new ObjectiveScore(getObjectiveValue());
}
