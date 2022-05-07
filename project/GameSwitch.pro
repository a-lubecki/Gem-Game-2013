#-------------------------------------------------
#
# Project created by QtCreator 2013-02-27T18:48:03
#
#-------------------------------------------------

QT       += core gui\
    widgets

TARGET = GameSwitch
TEMPLATE = app


SOURCES += main.cpp\
    Grid.cpp \
    Cell.cpp \
    Play.cpp \
    CellCounter.cpp \
    CellPure.cpp \
    AnimatedImage.cpp \
    CellLaser.cpp \
    CellUltrasound.cpp \
    CellTime.cpp \
    AbstractObjective.cpp \
    ObjectiveCellType.cpp \
    ObjectiveCellCategory.cpp \
    ObjectiveScore.cpp \
    ObjectiveCellName.cpp \
    CellDynamite.cpp \
    AnimatedText.cpp \
    CellMultiplier.cpp \
    ObjectiveMultiplier.cpp \
    WidgetHelper.cpp \
    WidgetTrophies.cpp \
    Trophy.cpp \
    TrophyCellName.cpp \
    TrophyCommon.cpp \
    LevelResult.cpp

HEADERS  += \
    stdafx.h \
    Grid.h \
    Cell.h \
    Play.h \
    CellCounter.h \
    CellPure.h \
    AnimatedImage.h \
    CellLaser.h \
    CellUltrasound.h \
    CellTime.h \
    AbstractObjective.h \
    ObjectiveCellType.h \
    ObjectiveCellCategory.h \
    ObjectiveScore.h \
    ObjectiveCellName.h \
    CellDynamite.h \
    AnimatedText.h \
    CellMultiplier.h \
    ObjectiveMultiplier.h \
    WidgetHelper.h \
    WidgetTrophies.h \
    Trophy.h \
    TrophyCellName.h \
    TrophyCommon.h \
    LevelResult.h

FORMS    += Play.ui \
    CellCounter.ui \
    AnimatedText.ui \
    WidgetHelper.ui \
    WidgetTrophies.ui \
    Trophy.ui

RESOURCES += \
    resources.qrc
