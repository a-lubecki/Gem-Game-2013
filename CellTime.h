// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "Cell.h"

class CellTime : public Cell
{
    int _timePercentage;

    QLabel* _labelPercentage;

public:
    CellTime(int timePercentage, int score, int appearanceFrequency);
    virtual ~CellTime();

    virtual bool resolveEffect();

    virtual Cell* clone() const;

};
