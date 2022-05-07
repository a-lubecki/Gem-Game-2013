// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "Trophy.h"
class WidgetTrophies;
class LevelResult;

class TrophyNbTrophies : public Trophy
{
    Q_OBJECT

    Trophy::TrophyImportance _importance;

public:
    TrophyNbTrophies(const QVector<int> &objectiveValues, Trophy::TrophyImportance importance);
    virtual ~TrophyNbTrophies();

    virtual QString getExplanationText(TrophyImportance importance) const;

public slots:
    void addTrophy(int importance);
};

///////////////////////////////////////////////////

class TrophyTotalScore : public Trophy
{
    Q_OBJECT

public:
    TrophyTotalScore(const QVector<int> &objectiveValues);
    virtual ~TrophyTotalScore();

    void addLevelResult(const LevelResult &result);

    virtual QString getExplanationText(TrophyImportance importance) const;
};

///////////////////////////////////////////////////

class TrophyUpperScore : public Trophy
{
    Q_OBJECT

public:
    TrophyUpperScore(const QVector<int> &objectiveValues);
    virtual ~TrophyUpperScore();

    void addLevelResult(const LevelResult &result);

    virtual QString getExplanationText(TrophyImportance importance) const;
};

///////////////////////////////////////////////////

class TrophyMinimumTime : public Trophy
{
    Q_OBJECT

public:
    TrophyMinimumTime(const QVector<int> &objectiveValues);
    virtual ~TrophyMinimumTime();

    void addLevelResult(const LevelResult &result);

    virtual QString getExplanationText(TrophyImportance importance) const;
};

///////////////////////////////////////////////////

class TrophyTotalTime : public Trophy
{
    Q_OBJECT

    int _currentTime;

public:
    TrophyTotalTime(const QVector<int> &objectiveValues);
    virtual ~TrophyTotalTime();

    void addLevelResult(const LevelResult &result);

    virtual QString getExplanationText(TrophyImportance importance) const;
};

///////////////////////////////////////////////////

class TrophyNbPlayedPlays : public Trophy
{
    Q_OBJECT

public:
    TrophyNbPlayedPlays(const QVector<int> &objectiveValues);
    virtual ~TrophyNbPlayedPlays();

    void addLevelResult(const LevelResult &result);

    virtual QString getExplanationText(TrophyImportance importance) const;
};

///////////////////////////////////////////////////

class TrophyNbWonPlays : public Trophy
{
    Q_OBJECT

public:
    TrophyNbWonPlays(const QVector<int> &objectiveValues);
    virtual ~TrophyNbWonPlays();

    void addLevelResult(const LevelResult &result);

    virtual QString getExplanationText(TrophyImportance importance) const;
};

///////////////////////////////////////////////////

class TrophyNbWonFollowedPlays : public Trophy
{
    Q_OBJECT

    int _counter;

public:
    TrophyNbWonFollowedPlays(const QVector<int> &objectiveValues);
    virtual ~TrophyNbWonFollowedPlays();

    void addLevelResult(const LevelResult &result);

    virtual QString getExplanationText(TrophyImportance importance) const;
};

///////////////////////////////////////////////////

class TrophyNbWonLevels : public Trophy
{
    Q_OBJECT

public:
    TrophyNbWonLevels(const QVector<int> &objectiveValues);
    virtual ~TrophyNbWonLevels();

    void addLevelResult(const LevelResult &result);

    virtual QString getExplanationText(TrophyImportance importance) const;
};
