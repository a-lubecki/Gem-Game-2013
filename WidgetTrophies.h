// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
#include "Trophy.h"
class LevelResult;

namespace Ui
{
    class WidgetTrophies;
}

class WidgetTrophies : public QFrame
{
    Q_OBJECT

    Ui::WidgetTrophies *ui;

    QVector<QVector<Trophy *> > _trophies;

    Trophy *_selectedTrophy;
    Trophy *_hoveredTrophy;

    void initProgressBar(QProgressBar *bar, int min, int max, int value);

public:
    explicit WidgetTrophies(QWidget *parent = 0);
    virtual ~WidgetTrophies();

    void init(const QList<Trophy *> &trophiesList);
    void enableInterface(bool enabled);

    virtual void setVisible(bool visible);

    void selectTrophy(int x, int y);
    void hoverTrophy(int x, int y);
    void unhoverCurrentTrophy();

    void updateNbTotalTrophies();

    void updateTrophy(int x, int y);

    void addLevelResult(const LevelResult &result);

private slots:
    void closeTrophies();

signals:
    void closed();
    void trophiesNumberChanged(const QMap<Trophy::TrophyImportance, int> &mapNb);
};
