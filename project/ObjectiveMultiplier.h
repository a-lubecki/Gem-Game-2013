// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "AbstractObjective.h"

class ObjectiveMultiplier : public AbstractObjective
{
public:
    ObjectiveMultiplier(int objectiveValue);
    virtual ~ObjectiveMultiplier();

    virtual void addCellsAsValue(const Play &play, const QSet<Cell *> &cells);

    virtual QString getExplanationText() const;

    AbstractObjective *clone() const;
};
