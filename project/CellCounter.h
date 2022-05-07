// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"
class Cell;

namespace Ui {
class CellCounter;
}

class CellCounter : public QWidget
{
    Q_OBJECT

    Ui::CellCounter *ui;

    QLabel* _labelCount;

    int _nbCells;

public:
    explicit CellCounter(const Cell& cell, QWidget *parent = 0);
    virtual ~CellCounter();

    void setNbCells(int nb);
    int getNbCells() const;
};
