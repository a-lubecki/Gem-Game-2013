// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "Cell.h"

class CellMultiplier : public Cell
{
    int _multiplier;

    QLabel* _labelMultiplier;

public:
    CellMultiplier(int multiplier, int score, int appearanceFrequency);
    virtual ~CellMultiplier();

    int getMultiplier() const;

    virtual bool resolveEffect();

    virtual Cell* clone() const;

};
