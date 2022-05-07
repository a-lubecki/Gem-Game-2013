// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "Cell.h"

class CellLaser : public Cell
{

public:
    CellLaser(int score, int appearanceFrequency);
    virtual ~CellLaser();

    virtual bool resolveEffect();

    virtual Cell* clone() const;

};
