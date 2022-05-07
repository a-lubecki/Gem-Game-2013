// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
class Cell;
class Play;

class AbstractObjective
{
    int _objectiveValue;

    int _currentValue;

protected:
    void addValue(int value);

public:
    AbstractObjective(int objectiveValue);
    virtual ~AbstractObjective();

    virtual void addCellsAsValue(const Play& play, const QSet<Cell*>& cells) = 0;

    void clearCurrentValue();

    bool isObjectiveReached() const;
    int getObjectiveValue() const;
    int getCurrentValue() const;

    virtual QString getExplanationText() const = 0;

    virtual AbstractObjective* clone() const = 0;
};
