// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "AbstractObjective.h"

class ObjectiveCellCategory : public AbstractObjective
{
public:
    enum Category
    {
        Item,
        Gem,
        NormalGem,
        PureGem
    };

private:
    Category _category;

public:
    ObjectiveCellCategory(int objectiveValue, Category category);
    virtual ~ObjectiveCellCategory();

    virtual void addCellsAsValue(const Play& play, const QSet<Cell*>& cells);

    virtual QString getExplanationText() const;

    virtual AbstractObjective* clone() const;
};
