// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
class Cell;
class Play;

class Grid : public QWidget
{
    Q_OBJECT

    Play* _play;

    QSize _gridSize;
    QVector<QVector<Cell*> > _grid;

    QMap<const Cell*, int> _initialCells;

    Cell* _selectedCell;
    QWidget* _widgetSelectedCell;
    Cell* _hoveredCell;
    QWidget* _widgetHoveredCell;

    Cell* _swappedCell1;
    Cell* _swappedCell2;

    QList<QPoint> _cellsToInit;
    QTimer _timerInitCells;

    QTimer _timerResolving;

    bool moveCell(Cell& cell, const QPoint& nextLocation);
    void getNearbyCells(QSet<Cell*>& nearbyCells, Cell& cellRef, bool searchHorizontally) const;
    void getAllNearbyCellsToDelete(QSet<Cell*>& cells);
    Cell* getNextUpperCell(const QPoint& currentLocation) const;
    const Cell* getRandomInitialCell(const QSet<int>& forbiddenTypes = QSet<int>()) const;

    void activateCellsClic(bool canClick) const;

public:
    Grid(Play& play, const QSize& size, const QList<const Cell*>& initialCells, QWidget* parent = 00);
    virtual ~Grid();

    const QSize& getGridSize() const;

    void initGrid();

    void resolveGrid();
    void clearGrid();

    Cell* getCell(const QPoint& loc) const;
    Cell* getCell(int x, int y) const;

    Cell* getCellUp(const Cell& cell) const;
    Cell* getCellDown(const Cell& cell) const;
    Cell* getCellLeft(const Cell& cell) const;
    Cell* getCellRight(const Cell& cell) const;

    void mousePressedOnCell(Cell& cell);

    void setSelectedCell(Cell* cell);
    Cell* getSelectedCell() const;

    void setHoveredCell(Cell* cell);

    bool swapCells(Cell& cell1, Cell& cell2);

    void deleteCells(const QSet<Cell*>& cellsToDelete);
    void deleteOneCell(Cell& cell);

    void addTimePercentageInPlay(int timePercentage);
    void addMultiplierInPlay(int nbMultiplier);

private slots:
    void initOneCell();
    void endSwapCells();
    void resolveOneSituation();
    void endResolving();

signals:
    void isReady();
};
