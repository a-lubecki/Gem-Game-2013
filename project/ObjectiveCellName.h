// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "AbstractObjective.h"
class Cell;

class ObjectiveCellName : public AbstractObjective
{
    Cell* _cellType;

public:
    ObjectiveCellName(int objectiveValue, Cell& cellType);
    virtual ~ObjectiveCellName();

    virtual void addCellsAsValue(const Play& play, const QSet<Cell*>& cells);

    virtual QString getExplanationText() const;

    AbstractObjective* clone() const;
};
