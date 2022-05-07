// Copyright Aurelien Lubecki 2012

#include "CellCounter.h"
#include "ui_CellCounter.h"
#include "Cell.h"

CellCounter::CellCounter(const Cell &cell, QWidget *parent) : QWidget(parent),
                                                              ui(new Ui::CellCounter),
                                                              _labelCount(00),
                                                              _nbCells(0)
{
    ui->setupUi(this);

    Cell *cloned = cell.clone();
    ui->widget->layout()->addWidget(cloned);
    ui->widget->setContentsMargins(-9, -9, -9, -9);
    cloned->setAttribute(Qt::WA_TransparentForMouseEvents);
    cloned->show();

    ui->labelName->setText(cell.getName());
    ui->labelScore->setText(QString::number(cell.getScore()));

    _labelCount = new QLabel(this);
    _labelCount->show();
    _labelCount->move(0, 10);
    _labelCount->resize(30, 20);
    _labelCount->setAlignment(Qt::AlignCenter);
    _labelCount->raise();

    _labelCount->setStyleSheet("QLabel {"
                               "font-weight:bold;"
                               "font-size:14px;"
                               "color:rgb(255, 255, 255);"
                               "background-color:rgba(0, 50, 80, 100);"
                               "border-radius:7px;"
                               "}");

    setNbCells(0);
}

CellCounter::~CellCounter()
{
    delete ui;
}

void CellCounter::setNbCells(int nb)
{
    _nbCells = nb;
    if (nb < 0)
    {
        _nbCells = 0;
    }

    _labelCount->setText("x" % QString::number(_nbCells));
}

int CellCounter::getNbCells() const
{
    return _nbCells;
}
