// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "Trophy.h"
class Cell;

class TrophyCellName : public Trophy
{
    Q_OBJECT

    Cell *_cell;

public:
    TrophyCellName(const QVector<int> &objectiveValues, const Cell &cell);
    virtual ~TrophyCellName();

    void addLevelResult(const LevelResult &result);

    virtual QString getExplanationText(TrophyImportance importance) const;
};
