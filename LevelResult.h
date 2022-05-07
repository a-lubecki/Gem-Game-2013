// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
class Cell;

class LevelResult
{
    QMap<QString, int> _nbCells;//<name, nb cells>
    int _score;

    bool _hasWon;
    bool _hasLosed;
    bool _hasGaveUp;

    int _time;//ms

public:
    LevelResult();
    virtual ~LevelResult();

    int getNbCells(const Cell& cell) const;
    int getScore() const;
    bool hasWon() const;
    bool hasLosed() const;
    bool hasGaveUp() const;
    int getTime() const;

    void addCell(const Cell& cell);
    void addScore(int score);
    void win();
    void lose();
    void giveUp();
    void addTime(int time);

    void clearData();
};
