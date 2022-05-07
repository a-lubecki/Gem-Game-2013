// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "Cell.h"
class AnimatedImage;

class CellPure : public Cell
{
    AnimatedImage* _animatedImage;

public:
    CellPure(int score, const QString& imagePath, const QString& name,
             int type, int appearanceFrequency, const QString& typeName);
    virtual ~CellPure();

    virtual Cell* clone() const;

    virtual void setVisible(bool visible);

};
