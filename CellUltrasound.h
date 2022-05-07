// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "Cell.h"

class CellUltrasound : public Cell
{

public:
    CellUltrasound(int score, int appearanceFrequency);
    virtual ~CellUltrasound();

    virtual bool resolveEffect();

    virtual Cell* clone() const;

};
