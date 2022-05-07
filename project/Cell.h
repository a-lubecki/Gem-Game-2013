// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
class Grid;

#define CELL_MOVE_DURATION (int(200))
#define CELL_SIZE (int(40))
#define CELL_SPACING (int(CELL_SIZE + 10))

namespace Ui {
class Cell;
}

class Cell : public QWidget
{
    Q_OBJECT

    int _score;

    QString _imagePath;
    QImage _image;

    QString _name;
    int _type;
    int _appearanceFrequency;
    QString _typeName;

    bool _canBeClicked;
    bool _aboutToDelete;

    QPoint _locationInGrid;
    QPropertyAnimation _anim;
    void moveInTime(int x, int y);
    void moveInTime(const QPoint& point);

protected:
    QLabel* _labelImage;
    Grid* _grid;

    bool _isDeletedManually;

public:
    explicit Cell(int score, const QString& imagePath, const QString& name,
                  int type, int appearanceFrequency, const QString& typeName = "");
    virtual ~Cell();

    const QString& getImagePath() const;
    const QString& getName() const;
    int getType() const;
    int getAppearanceFrequency() const;
    const QString& getTypeName() const;
    int getScore() const;

    void setGrid(Grid* grid);
    const Grid* getGrid() const;
    void setLocationInGrid(const QPoint& point);
    const QPoint& getLocationInGrid() const;

    void setCanBeClicked(bool canBeClicked);
    void setAboutToDelete();

    bool isDeletedManually() const;

    virtual bool resolveEffect();

    virtual Cell* clone() const;

protected slots:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void enterEvent(QEnterEvent* event);
    virtual void leaveEvent(QEvent* event);

private slots:
    void endMoveInTime();
};
