// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"

namespace Ui
{
    class WidgetHelper;
}

class WidgetHelper : public QFrame
{
    Q_OBJECT

public:
    struct Help
    {
        QString _title;
        QString _imageName;
        QString _explanation;
    };

private:
    Ui::WidgetHelper *ui;

    QVector<Help> _helpList;
    QStandardItemModel _model;

    void selectHelp(int pos);

public:
    explicit WidgetHelper(QWidget *parent = 0);
    virtual ~WidgetHelper();

    void init();
    void enableInterface(bool enable);

    virtual void setVisible(bool visible);

private slots:
    void helpSelected(QModelIndex index);
    void stopHelp();

signals:
    void closed();
};
