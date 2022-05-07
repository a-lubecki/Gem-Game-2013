// Copyright Aurelien Lubecki 2012�lien Lubecki 2012

#include "WidgetTrophy.h"
#include "ui_WidgetTrophy.h"
#include "Trophy.h"

WidgetTrophy::WidgetTrophy(QWidget *parent) : QFrame(parent),
                                              ui(new Ui::WidgetTrophy)
{
    ui->setupUi(this);
}

WidgetTrophy::~WidgetTrophy()
{
    delete ui;
}

void WidgetTrophy::setTrophy(const Trophy &trophy)
{

    trophy.set
}
