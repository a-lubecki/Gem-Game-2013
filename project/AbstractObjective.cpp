//Copyright Aurelien Lubecki 2012

#include "AbstractObjective.h"

AbstractObjective::AbstractObjective(int objectiveValue)
   : _objectiveValue(objectiveValue), _currentValue(0)
{
    assert(_objectiveValue > 0);
}

AbstractObjective::~AbstractObjective()
{
}

void AbstractObjective::addValue(int value)
{
    if(value <= 0)
    {
        return;
    }
    _currentValue += value;
}

void AbstractObjective::clearCurrentValue()
{
    _currentValue = 0;
}

bool AbstractObjective::isObjectiveReached() const
{
    return (_currentValue >= _objectiveValue);
}

int AbstractObjective::getObjectiveValue() const
{
    return _objectiveValue;
}

int AbstractObjective::getCurrentValue() const
{
    return _currentValue;
}
