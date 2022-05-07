// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "AbstractObjective.h"
class Cell;

class ObjectiveCellType : public AbstractObjective
{
    Cell* _cellType;

public:
    ObjectiveCellType(int objectiveValue, Cell& cellType);
    virtual ~ObjectiveCellType();

    virtual void addCellsAsValue(const Play& play, const QSet<Cell*>& cells);

    virtual QString getExplanationText() const;

    AbstractObjective* clone() const;
};
