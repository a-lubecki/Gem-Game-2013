//Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include <QtWidgets/QMainWindow>
#include "AnimatedText.h"
#include "LevelResult.h"
class Grid;
class CellCounter;
class Cell;
class CellPure;
class AbstractObjective;
class Trophy;

namespace Ui {
class Play;
}

#define MAX_MULTIPLIER (int(10))
#define MAX_NB_SCORES (int(10))

class Play : public QMainWindow
{
    Q_OBJECT

public:
    struct BundleScore
    {
        QString _name;
        qint32 _level;
        qint32 _score;
        QTime _totalTime;
        QDateTime _date;

        friend bool operator <(const BundleScore& b1, const BundleScore& b2);
        friend bool operator >(const BundleScore& b1, const BundleScore& b2);

        friend bool operator ==(const BundleScore& b1, const BundleScore& b2);
        friend bool operator !=(const BundleScore& b1, const BundleScore& b2);

        friend QDataStream& operator <<(QDataStream& s, const BundleScore& x);
        friend QDataStream& operator >>(QDataStream& s, BundleScore& x);
    };

private:
    Ui::Play *ui;

    Grid* _grid;

    QMap<QString, CellCounter*> _cellCounters;
    int _totalScore;
    int _currentLevel;

    QTimer _timer;
    QElapsedTimer _elapsedTimer;
    int _elapsedAdded;
    int _maxTime;
    bool _isPaused;


    QVector<QVector<const AbstractObjective*> > _levelsObjectives;
    AbstractObjective* _currentObjective;
    int _maxTimeFirstLevel;
    int _maxTimeLastLevel;

    bool _canScoreCells;

    int _multiplier;
    QTimer _timerMultiplierDown;
    bool _canDownMultiplier;

    QList<BundleScore> _allScores;

    QTime _totalTime;

    BundleScore _lastScore;

    AnimatedText _animatedTextMultiplier;
    AnimatedText _animatedTextLevel;
    AnimatedText _animatedTextTrophies;

    LevelResult _result;

    void enableInterface(bool enable);

    void addInitialCellCopy(const Cell& cellToAdd);

    void setScore(int score);

    void loadPlayerName();

    void updateAllScores();
    void loadAllScores();
    void saveAllScores();

    void lose();
    void addNewScore();

    void sortAllScores();

public:
    explicit Play(QWidget *parent = 0);
    virtual ~Play();

    void init(const QList<const Cell*>& initialCells,
              const QVector<QList<const AbstractObjective*> >& objectives,
              int maxTimeFirstLevel, int maxTimeLastLevel,
              const QList<Trophy*>& trophiesList);

    bool scoreDeletedCells(const QSet<Cell*>& cells);

    void addTimePercentage(int timePercentage);

    void pauseTime();
    void resumeTime();

    void setMultiplier(int multiplier);
    int getMultiplier() const;

protected:
    void resizeEvent(QResizeEvent* event);

private slots:
    void win();
    void giveUp();
    void startCurrentLevel();

    void updateStartButton();
    void savePlayerName();

    void startPlay();
    void startTime();
    void stopPlay();

    void updateBarTime();
    void downMultiplier();


    void showMenu();
    void showPlay();
    void showHelp();
    void showTrophies();
};
