// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
class Play;
class Cell;
class WidgetTrophies;
class LevelResult;

namespace Ui
{
    class Trophy;
}

class Trophy : public QWidget
{
    Q_OBJECT

public:
    enum TrophyImportance
    {
        Bronze = 0,
        Silver,
        Gold,
        Platinum,
        NB_TROPHY_IMPORTANCES
    };

private:
    Ui::Trophy *ui;

    int _x;
    int _y;

    QString _name;
    int _number;

    QVector<int> _objectiveValues;

    int _currentValue;

    QLabel *_labelObtained;

    bool _isIncreasing;

protected:
    WidgetTrophies *_widgetTrophies;

    void addValue(int value);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void enterEvent(QEnterEvent *event);
    virtual void leaveEvent(QEvent *event);

    void setName(const QString &name);

    bool isIncreasing() const;

public:
    explicit Trophy(const QString &name, const QVector<int> &objectiveValues);
    virtual ~Trophy();

    void setNumber(int number);

    void setWidgetTrophies(WidgetTrophies &parent);
    void init(int value);
    void setPos(int x, int y);

    virtual void addLevelResult(const LevelResult &result);

    void clearCurrentValue();

    const QString &getName() const;
    int getNumber() const;

    bool isObjectiveReached(TrophyImportance importance) const;
    int getObjectiveValue(TrophyImportance importance) const;
    int getCurrentValue() const;

    int getX() const;
    int getY() const;

    void highlightTrophy(bool highlight);
    void showTextObtained(bool show);

    virtual QString getExplanationText(TrophyImportance importance) const = 0;

signals:
    void trophyWon(int importance);
};
