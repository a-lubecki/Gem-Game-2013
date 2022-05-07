//Copyright Aurelien Lubecki 2012

#include <QtWidgets/QApplication>
#include "Play.h"
#include "Cell.h"
#include "CellPure.h"
#include "CellMultiplier.h"
#include "CellTime.h"
#include "CellDynamite.h"
#include "CellLaser.h"
#include "CellUltrasound.h"
#include "AbstractObjective.h"
#include "ObjectiveScore.h"
#include "ObjectiveCellCategory.h"
#include "ObjectiveCellType.h"
#include "ObjectiveCellName.h"
#include "ObjectiveMultiplier.h"
#include "Trophy.h"
#include "TrophyCommon.h"
#include "TrophyCellName.h"

#include <time.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Play play;

    Cell* amber = new Cell(1,       PATH_RESOURCES "amber.png",    "Ambre",     CELL_TYPE_AMBER,    100);
    Cell* quartz = new Cell(2,      PATH_RESOURCES "quartz.png",   "Quartz",    CELL_TYPE_QUARTZ,   100);
    Cell* emerald = new Cell(4,     PATH_RESOURCES "emerald.png",  "Emeraude",  CELL_TYPE_EMERALD,  80);
    Cell* saphire = new Cell(6,     PATH_RESOURCES "saphire.png",  "Saphir",    CELL_TYPE_SAPHIR,   80);
    Cell* ruby = new Cell(10,       PATH_RESOURCES "ruby.png",     "Rubis",     CELL_TYPE_RUBY,     50);
    Cell* gold = new Cell(20,       PATH_RESOURCES "gold.png",     "Or",        CELL_TYPE_GOLD,     40);
    Cell* diamond = new Cell(40,    PATH_RESOURCES "diamond.png",  "Diamant",   CELL_TYPE_DIAMOND,  10);

    Cell* pureAmber = new CellPure(4,       PATH_RESOURCES "amber.png",    "Ambre Pur",     CELL_TYPE_AMBER,   60, "Ambre");
    Cell* pureQuartz = new CellPure(6,      PATH_RESOURCES "quartz.png",   "Quartz Pur",     CELL_TYPE_QUARTZ,  60, "Quartz");
    Cell* pureEmerald = new CellPure(10,    PATH_RESOURCES "emerald.png",  "Emeraude Pure",  CELL_TYPE_EMERALD, 50, "Emeraude");
    Cell* pureSaphire = new CellPure(20,    PATH_RESOURCES "saphire.png",  "Saphir Pur",     CELL_TYPE_SAPHIR,  40, "Saphir");
    Cell* pureRuby = new CellPure(30,       PATH_RESOURCES "ruby.png",     "Rubis Pur",      CELL_TYPE_RUBY,    25, "Rubis");
    Cell* pureGold = new CellPure(40,       PATH_RESOURCES "gold.png",     "Or Pur",         CELL_TYPE_GOLD,    10, "Or");
    Cell* pureDiamond = new CellPure(60,    PATH_RESOURCES "diamond.png",  "Diamant Pur",    CELL_TYPE_DIAMOND, 5,  "Diamant");

    Cell* mul1 = new CellMultiplier(1, -100, 7);
    Cell* mul2 = new CellMultiplier(2, -200, 3);
    Cell* time25 = new CellTime(25, -10, 10);
    Cell* time50 = new CellTime(50, -30, 5);
    Cell* dynamite = new CellDynamite(-100, 5);
    //Cell* amber = new CellDigger(-150, 4);
    //Cell* amber = new CellEarthquake(-250, 4);
    Cell* laser = new CellLaser(-250, 3);
    Cell* ultrasound = new CellUltrasound(-300, 2);


    QList<const Cell*> initialCells;

    initialCells.append(amber);
    initialCells.append(quartz);
    initialCells.append(emerald);
    initialCells.append(saphire);
    initialCells.append(ruby);
    initialCells.append(gold);
    initialCells.append(diamond);

    initialCells.append(pureAmber);
    initialCells.append(pureQuartz);
    initialCells.append(pureEmerald);
    initialCells.append(pureSaphire);
    initialCells.append(pureRuby);
    initialCells.append(pureGold);
    initialCells.append(pureDiamond);

    initialCells.append(mul1);
    initialCells.append(mul2);
    initialCells.append(time25);
    initialCells.append(time50);
    initialCells.append(dynamite);
    //initialCells.append(digger);
    //initialCells.append(earthquake);
    initialCells.append(laser);
    initialCells.append(ultrasound);


    int nbLevels = 10;

    QVector<QList<const AbstractObjective*> > levelPossibilities;
    levelPossibilities.resize(nbLevels);

    int level = 0;
    levelPossibilities[level].append(new ObjectiveScore(250));
    levelPossibilities[level].append(new ObjectiveScore(300));
    levelPossibilities[level].append(new ObjectiveScore(350));
    levelPossibilities[level].append(new ObjectiveCellCategory(5, ObjectiveCellCategory::Item));
    levelPossibilities[level].append(new ObjectiveCellCategory(50, ObjectiveCellCategory::Gem));
    levelPossibilities[level].append(new ObjectiveCellCategory(40, ObjectiveCellCategory::NormalGem));
    levelPossibilities[level].append(new ObjectiveCellCategory(20, ObjectiveCellCategory::PureGem));
    levelPossibilities[level].append(new ObjectiveCellType(30, *amber));
    levelPossibilities[level].append(new ObjectiveCellType(1, *pureDiamond));

    level = 1;
    levelPossibilities[level].append(new ObjectiveScore(700));
    levelPossibilities[level].append(new ObjectiveCellType(20, *emerald));
    levelPossibilities[level].append(new ObjectiveCellName(4, *time25));

    level = 2;
    levelPossibilities[level].append(new ObjectiveScore(1000));
    levelPossibilities[level].append(new ObjectiveCellType(1, *pureDiamond));
    levelPossibilities[level].append(new ObjectiveCellType(7, *time25));
    levelPossibilities[level].append(new ObjectiveMultiplier(5));

    level = 3;
    levelPossibilities[level].append(new ObjectiveCellCategory(6, ObjectiveCellCategory::Item));
    levelPossibilities[level].append(new ObjectiveCellCategory(30, ObjectiveCellCategory::PureGem));
    levelPossibilities[level].append(new ObjectiveCellType(25, *pureAmber));
    levelPossibilities[level].append(new ObjectiveCellName(20, *pureAmber));

    level = 4;
    levelPossibilities[level].append(new ObjectiveCellCategory(6, ObjectiveCellCategory::Item));
    levelPossibilities[level].append(new ObjectiveCellCategory(30, ObjectiveCellCategory::PureGem));
    levelPossibilities[level].append(new ObjectiveCellType(30, *amber));
    levelPossibilities[level].append(new ObjectiveCellType(2, *pureDiamond));
    levelPossibilities[level].append(new ObjectiveCellName(20, *pureQuartz));

    level = 5;
    levelPossibilities[level].append(new ObjectiveCellCategory(30, ObjectiveCellCategory::PureGem));
    levelPossibilities[level].append(new ObjectiveCellType(20, *amber));
    levelPossibilities[level].append(new ObjectiveCellName(20, *pureEmerald));
    levelPossibilities[level].append(new ObjectiveMultiplier(10));

    level = 6;
    levelPossibilities[level].append(new ObjectiveCellCategory(8, ObjectiveCellCategory::Item));
    levelPossibilities[level].append(new ObjectiveCellCategory(30, ObjectiveCellCategory::PureGem));
    levelPossibilities[level].append(new ObjectiveCellType(40, *amber));
    levelPossibilities[level].append(new ObjectiveCellType(4, *pureDiamond));
    levelPossibilities[level].append(new ObjectiveCellName(2, *pureDiamond));
    levelPossibilities[level].append(new ObjectiveCellName(20, *pureSaphire));

    level = 7;
    levelPossibilities[level].append(new ObjectiveCellCategory(60, ObjectiveCellCategory::NormalGem));
    levelPossibilities[level].append(new ObjectiveCellName(40, *amber));
    levelPossibilities[level].append(new ObjectiveCellType(20, *pureRuby));
    levelPossibilities[level].append(new ObjectiveMultiplier(15));

    level = 8;
    levelPossibilities[level].append(new ObjectiveCellCategory(60, ObjectiveCellCategory::Gem));
    levelPossibilities[level].append(new ObjectiveCellCategory(40, ObjectiveCellCategory::PureGem));
    levelPossibilities[level].append(new ObjectiveCellType(40, *pureAmber));
    levelPossibilities[level].append(new ObjectiveCellType(20, *pureGold));

    level = 9;
    levelPossibilities[level].append(new ObjectiveCellCategory(12, ObjectiveCellCategory::Item));
    levelPossibilities[level].append(new ObjectiveCellCategory(30, ObjectiveCellCategory::PureGem));
    levelPossibilities[level].append(new ObjectiveCellType(5, *pureDiamond));
    levelPossibilities[level].append(new ObjectiveCellName(4, *pureDiamond));
    levelPossibilities[level].append(new ObjectiveMultiplier(25));



    QList<Trophy*> trophiesList;
    trophiesList.append(new TrophyNbPlayedPlays(QVector<int>() << 15 << 50 << 150 << 500));
    trophiesList.append(new TrophyNbWonLevels(QVector<int>() << 10 << 50 << 200 << 500));
    trophiesList.append(new TrophyNbWonPlays(QVector<int>() << 2 << 5 << 20 << 50));
    trophiesList.append(new TrophyNbWonFollowedPlays(QVector<int>() << 2 << 3 << 4 << 5));
    trophiesList.append(new TrophyTotalTime(QVector<int>() << 10 << 20 << 40 << 60));
    trophiesList.append(new TrophyMinimumTime(QVector<int>() << 10 << 7 << 5 << 4));
    trophiesList.append(new TrophyTotalScore(QVector<int>() << 1000 << 10000 << 100000 << 1000000));
    trophiesList.append(new TrophyUpperScore(QVector<int>() << 5000 << 10000 << 30000 << 50000));
    trophiesList.append(new TrophyCellName(QVector<int>() << 100 << 300 << 1000 << 3000, *amber));
    trophiesList.append(new TrophyCellName(QVector<int>() << 50 << 150 << 500 << 1000, *pureAmber));
    trophiesList.append(new TrophyCellName(QVector<int>() << 100 << 300 << 1000 << 3000, *quartz));
    trophiesList.append(new TrophyCellName(QVector<int>() << 50 << 150 << 500 << 1000, *pureQuartz));
    trophiesList.append(new TrophyCellName(QVector<int>() << 70 << 200 << 700 << 2000, *emerald));
    trophiesList.append(new TrophyCellName(QVector<int>() << 40 << 100 << 300 << 700, *pureEmerald));
    trophiesList.append(new TrophyCellName(QVector<int>() << 70 << 200 << 700 << 2000, *saphire));
    trophiesList.append(new TrophyCellName(QVector<int>() << 40 << 100 << 300 << 700, *pureSaphire));
    trophiesList.append(new TrophyCellName(QVector<int>() << 50 << 150 << 500 << 1000, *ruby));
    trophiesList.append(new TrophyCellName(QVector<int>() << 30 << 70 << 200 << 500, *pureRuby));
    trophiesList.append(new TrophyCellName(QVector<int>() << 50 << 150 << 500 << 1000, *gold));
    trophiesList.append(new TrophyCellName(QVector<int>() << 30 << 70 << 200 << 500, *pureGold));
    trophiesList.append(new TrophyCellName(QVector<int>() << 50 << 150 << 500 << 1000, *diamond));
    trophiesList.append(new TrophyCellName(QVector<int>() << 30 << 70 << 200 << 500, *pureDiamond));
    trophiesList.append(new TrophyCellName(QVector<int>() << 100 << 300 << 1000 << 3000, *mul1));
    trophiesList.append(new TrophyCellName(QVector<int>() << 70 << 200 << 700 << 2000, *mul2));
    trophiesList.append(new TrophyCellName(QVector<int>() << 100 << 300 << 1000 << 3000, *time25));
    trophiesList.append(new TrophyCellName(QVector<int>() << 70 << 200 << 700 << 2000, *time50));
    trophiesList.append(new TrophyCellName(QVector<int>() << 70 << 200 << 700 << 2000, *dynamite));
    trophiesList.append(new TrophyCellName(QVector<int>() << 50 << 150 << 500 << 1000, *laser));
    trophiesList.append(new TrophyCellName(QVector<int>() << 30 << 70 << 200 << 500, *ultrasound));



    QVector<int> objectivesNbTrophies(4);
    int nbTrophies = trophiesList.size();
    objectivesNbTrophies[0] = nbTrophies * 0.3;
    objectivesNbTrophies[1] = nbTrophies * 0.5;
    objectivesNbTrophies[2] = nbTrophies * 0.7;
    objectivesNbTrophies[3] = nbTrophies;

    trophiesList.prepend(new TrophyNbTrophies(objectivesNbTrophies, Trophy::Platinum));
    trophiesList.prepend(new TrophyNbTrophies(objectivesNbTrophies, Trophy::Gold));
    trophiesList.prepend(new TrophyNbTrophies(objectivesNbTrophies, Trophy::Silver));
    trophiesList.prepend(new TrophyNbTrophies(objectivesNbTrophies, Trophy::Bronze));


    int maxTimeFirstLevel = 30000;
    int maxTimeLastLevel = 10000;
    play.init(initialCells, levelPossibilities, maxTimeFirstLevel, maxTimeLastLevel, trophiesList);

    qDeleteAll(initialCells);

    foreach(const QList<const AbstractObjective*>& objectives, levelPossibilities)
    {
        foreach(const AbstractObjective* obj, objectives)
        {
            assert(obj != 00);
            delete obj;
        }
    }

    play.show();

    return a.exec();
}
