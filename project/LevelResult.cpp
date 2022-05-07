// Copyright Aurelien Lubecki 2012

#include "LevelResult.h"
#include "Cell.h"

LevelResult::LevelResult()
    : _nbCells(),
      _score(0),
      _hasWon(false),
      _hasLosed(false),
      _hasGaveUp(false),
      _time(0)
{
}

LevelResult::~LevelResult()
{
}

int LevelResult::getNbCells(const Cell &cell) const
{
    if (_nbCells.contains(cell.getName()))
    {
        return _nbCells[cell.getName()];
    }
    return 0;
}

int LevelResult::getScore() const
{
    return _score;
}

bool LevelResult::hasWon() const
{
    return _hasWon;
}

bool LevelResult::hasLosed() const
{
    return _hasLosed;
}

bool LevelResult::hasGaveUp() const
{
    return _hasGaveUp;
}

int LevelResult::getTime() const
{
    return _time;
}

void LevelResult::addCell(const Cell &cell)
{
    _nbCells[cell.getName()]++;
}

void LevelResult::addScore(int score)
{
    if (score > 0)
    {
        _score += score;
    }
}

void LevelResult::win()
{
    _hasWon = true;
    _hasLosed = false;
    _hasGaveUp = false;
}

void LevelResult::lose()
{
    _hasWon = false;
    _hasLosed = true;
    _hasGaveUp = false;
}

void LevelResult::giveUp()
{
    _hasWon = false;
    _hasLosed = true;
    _hasGaveUp = true;
}

void LevelResult::addTime(int time)
{
    if (time > 0)
    {
        _time += time;
    }
}

void LevelResult::clearData()
{
    _nbCells.clear();
    _score = 0;
    _hasWon = false;
    _hasLosed = false;
    _hasGaveUp = false;
    _time = 0;
}
