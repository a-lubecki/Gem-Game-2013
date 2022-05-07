// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "Cell.h"

class CellDynamite : public Cell
{

public:
    CellDynamite(int score, int appearanceFrequency);
    virtual ~CellDynamite();

    virtual bool resolveEffect();

    virtual Cell *clone() const;
};
