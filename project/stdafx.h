// Copyright Aurelien Lubecki 2012

#pragma once

#include <QObject>

#include <QString>
#include <QStringBuilder>

#include <QVector>
#include <QList>
#include <QMap>

#include <QDateTime>

#include <QTimer>
#include <QElapsedTimer>

#include <QRandomGenerator>

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QtWidgets/QLabel>

#include <QtWidgets/QWidget>
#include <QtWidgets/QProgressBar>

#include <QMouseEvent>

#include <QPropertyAnimation>

#include <QModelIndex>
#include <QStandardItem>
#include <QStandardItemModel>

#include <QDebug>
#include <math.h>
#include <assert.h>

#define TEST(cond)         \
    {                      \
        if (!(cond))       \
        {                  \
            assert(false); \
            return 0;      \
        }                  \
    }

#define PATH_RESOURCES ":/resources/"
#define PATH_RESOURCES_HELP PATH_RESOURCES "help/"

#define CELL_TYPE_MULTIPLIER -12
#define CELL_TYPE_TIME -10
#define CELL_TYPE_DYNAMITE -8
#define CELL_TYPE_LASER -5
#define CELL_TYPE_ULTRASOUND -1

#define CELL_TYPE_AMBER 0
#define CELL_TYPE_QUARTZ 1
#define CELL_TYPE_EMERALD 2
#define CELL_TYPE_SAPHIR 3
#define CELL_TYPE_RUBY 4
#define CELL_TYPE_GOLD 5
#define CELL_TYPE_DIAMOND 6
