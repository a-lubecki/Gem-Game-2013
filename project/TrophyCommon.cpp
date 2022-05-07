// Copyright Aurelien Lubecki 2012

#include "TrophyCommon.h"
#include "Cell.h"
#include "LevelResult.h"
#include "WidgetTrophies.h"

TrophyNbTrophies::TrophyNbTrophies(const QVector<int> &objectiveValues, Trophy::TrophyImportance importance)
    : Trophy("", objectiveValues),
      _importance(importance)
{
    if (_importance == Trophy::Bronze)
    {
        setName("Bronzage");
    }
    else if (_importance == Trophy::Silver)
    {
        setName("Argenterie");
    }
    else if (_importance == Trophy::Gold)
    {
        setName("Dorures");
    }
    else if (_importance == Trophy::Platinum)
    {
        setName("Platinator");
    }
    else
    {
        assert(false);
    }
}

TrophyNbTrophies::~TrophyNbTrophies()
{
}

QString TrophyNbTrophies::getExplanationText(TrophyImportance importance) const
{
    QString imp;
    if (_importance == Bronze)
    {
        imp = "de Bronze";
    }
    else if (_importance == Silver)
    {
        imp = "d'Argent";
    }
    else if (_importance == Gold)
    {
        imp = "d'Or";
    }
    else if (_importance == Platinum)
    {
        imp = "de Platine";
    }
    else
    {
        assert(false);
    }

    return "Obtenir un total de " % QString::number(getObjectiveValue(importance)) % " Trophées " % imp % ".";
}

void TrophyNbTrophies::addTrophy(int importance)
{
    if (importance == _importance)
    {
        addValue(1);
    }
}

///////////////////////////////////////////////////

TrophyTotalScore::TrophyTotalScore(const QVector<int> &objectiveValues)
    : Trophy("Accumulation de points", objectiveValues)
{
}

TrophyTotalScore::~TrophyTotalScore()
{
}

void TrophyTotalScore::addLevelResult(const LevelResult &result)
{
    addValue(result.getScore());
}

QString TrophyTotalScore::getExplanationText(TrophyImportance importance) const
{
    return "Obtenir un score total de " % QString::number(getObjectiveValue(importance)) % " points.";
}

///////////////////////////////////////////////////

TrophyUpperScore::TrophyUpperScore(const QVector<int> &objectiveValues)
    : Trophy("High-score", objectiveValues)
{
}

TrophyUpperScore::~TrophyUpperScore()
{
}

void TrophyUpperScore::addLevelResult(const LevelResult &result)
{
    if (result.getScore() > getCurrentValue())
    {
        init(result.getScore());
    }
}

QString TrophyUpperScore::getExplanationText(TrophyImportance importance) const
{
    return "Obtenir un score minimum de " % QString::number(getObjectiveValue(importance)) % " points.";
}

///////////////////////////////////////////////////

TrophyMinimumTime::TrophyMinimumTime(const QVector<int> &objectiveValues)
    : Trophy("Un train à prendre", objectiveValues)
{
}

TrophyMinimumTime::~TrophyMinimumTime()
{
}

void TrophyMinimumTime::addLevelResult(const LevelResult &result)
{
    if (result.hasLosed() || result.hasWon())
    {
        if (result.getTime() < getCurrentValue() * 60000)
        {
            init(result.getTime() / 60000.);
        }
    }
}

QString TrophyMinimumTime::getExplanationText(TrophyImportance importance) const
{
    return "Gagner une partie en moins de " % QString::number(getObjectiveValue(importance)) % " minutes.";
}

///////////////////////////////////////////////////

TrophyTotalTime::TrophyTotalTime(const QVector<int> &objectiveValues)
    : Trophy("Accro aux jeux-vidéos", objectiveValues),
      _currentTime(0)
{
}

TrophyTotalTime::~TrophyTotalTime()
{
}

void TrophyTotalTime::addLevelResult(const LevelResult &result)
{
    if (result.hasLosed() || result.hasWon())
    {
        _currentTime += result.getTime();
        if (_currentTime > getCurrentValue())
        {
            init(_currentTime / 60000.);
        }
    }
}

QString TrophyTotalTime::getExplanationText(TrophyImportance importance) const
{
    return "Totaliser " % QString::number(getObjectiveValue(importance)) % " minutes de jeu.";
}

///////////////////////////////////////////////////

TrophyNbPlayedPlays::TrophyNbPlayedPlays(const QVector<int> &objectiveValues)
    : Trophy("Acharné", objectiveValues)
{
}

TrophyNbPlayedPlays::~TrophyNbPlayedPlays()
{
}

void TrophyNbPlayedPlays::addLevelResult(const LevelResult &result)
{
    if (result.hasWon() || (result.hasLosed() && !result.hasGaveUp()))
    {
        addValue(1);
    }
}

QString TrophyNbPlayedPlays::getExplanationText(TrophyImportance importance) const
{
    return "Totaliser " % QString::number(getObjectiveValue(importance)) % " parties jouées.";
}

///////////////////////////////////////////////////

TrophyNbWonPlays::TrophyNbWonPlays(const QVector<int> &objectiveValues)
    : Trophy("Maîtrise Suprême", objectiveValues)
{
}

TrophyNbWonPlays::~TrophyNbWonPlays()
{
}

void TrophyNbWonPlays::addLevelResult(const LevelResult &result)
{
    if (result.hasWon())
    {
        addValue(1);
    }
}

QString TrophyNbWonPlays::getExplanationText(TrophyImportance importance) const
{
    return "Gagner un total de " % QString::number(getObjectiveValue(importance)) % " parties.";
}

///////////////////////////////////////////////////

TrophyNbWonFollowedPlays::TrophyNbWonFollowedPlays(const QVector<int> &objectiveValues)
    : Trophy("Hardcore Gamer", objectiveValues),
      _counter(0)
{
}

TrophyNbWonFollowedPlays::~TrophyNbWonFollowedPlays()
{
}

void TrophyNbWonFollowedPlays::addLevelResult(const LevelResult &result)
{
    if (result.hasWon())
    {
        _counter++;
        if (_counter > getCurrentValue())
        {
            init(_counter);
        }
    }
    else
    {
        _counter = 0;
    }
}

QString TrophyNbWonFollowedPlays::getExplanationText(TrophyImportance importance) const
{
    return "Gagner " % QString::number(getObjectiveValue(importance)) % " parties d'affilée.";
}

///////////////////////////////////////////////////

TrophyNbWonLevels::TrophyNbWonLevels(const QVector<int> &objectiveValues)
    : Trophy("Level Up", objectiveValues)
{
}

TrophyNbWonLevels::~TrophyNbWonLevels()
{
}

void TrophyNbWonLevels::addLevelResult(const LevelResult &result)
{
    if (!result.hasGaveUp())
    {
        addValue(1);
    }
}

QString TrophyNbWonLevels::getExplanationText(TrophyImportance importance) const
{
    return "Terminer " % QString::number(getObjectiveValue(importance)) % " niveaux.";
}
