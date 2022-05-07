// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "AbstractObjective.h"

class ObjectiveScore : public AbstractObjective
{
public:
    ObjectiveScore(int objectiveValue);
    virtual ~ObjectiveScore();

    virtual void addCellsAsValue(const Play &play, const QSet<Cell *> &cells);

    virtual QString getExplanationText() const;

    AbstractObjective *clone() const;
};
