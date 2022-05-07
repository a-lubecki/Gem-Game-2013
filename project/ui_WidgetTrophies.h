/********************************************************************************
** Form generated from reading UI file 'WidgetTrophies.ui'
**
** Created: Sun 31. Mar 23:52:07 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETTROPHIES_H
#define UI_WIDGETTROPHIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetTrophies
{
public:
    QVBoxLayout *verticalLayout_12;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_6;
    QScrollArea *scrollArea;
    QWidget *widgetAllTrophies;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_11;
    QLabel *labelName;
    QFrame *widgetBronze;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *labelBronze;
    QProgressBar *progressBarBronze;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelExplBronze;
    QFrame *widgetSilver;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *labelSilver;
    QProgressBar *progressBarSilver;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelExplSilver;
    QFrame *widgetGold;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_9;
    QLabel *labelGold;
    QProgressBar *progressBarGold;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelExplGold;
    QFrame *widgetPlatinum;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_8;
    QLabel *labelPlatinum;
    QProgressBar *progressBarPlatinum;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelExplPlatinum;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *buttonReturn;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *labelNbBronze;
    QLabel *label_12;
    QLabel *labelNbSilver;
    QLabel *label_14;
    QLabel *labelNbGold;
    QLabel *label_16;
    QLabel *labelNbPlatinum;
    QLabel *labelNbTotal;

    void setupUi(QFrame *WidgetTrophies)
    {
        if (WidgetTrophies->objectName().isEmpty())
            WidgetTrophies->setObjectName(QString::fromUtf8("WidgetTrophies"));
        WidgetTrophies->resize(990, 443);
        WidgetTrophies->setStyleSheet(QString::fromUtf8("\n"
"#labelName\n"
"{\n"
"	font-weight:bold;\n"
"	font-size:20px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#labelBronze, #labelSilver, #labelGold, #labelPlatinum\n"
"{\n"
"	font-weight:bold;\n"
"	font-size:14px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#widgetBronze, #widgetSilver, #widgetGold, #widgetPlatinum\n"
"{\n"
"	border-radius:10px;\n"
"}\n"
"\n"
"#labelNbBronze, #labelNbSilver, #labelNbGold, #labelNbPlatinum, #labelNbTotal\n"
"{\n"
"	font-weight:bold;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#widgetAllTrophies, #scrollArea\n"
"{\n"
"	background-color:transparent;\n"
"}\n"
""));
        WidgetTrophies->setFrameShape(QFrame::StyledPanel);
        WidgetTrophies->setFrameShadow(QFrame::Raised);
        verticalLayout_12 = new QVBoxLayout(WidgetTrophies);
#ifndef Q_OS_MAC
        verticalLayout_12->setSpacing(6);
#endif
        verticalLayout_12->setContentsMargins(6, 6, 6, 6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        widget_12 = new QWidget(WidgetTrophies);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_6 = new QHBoxLayout(widget_12);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        scrollArea = new QScrollArea(widget_12);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(570, 400));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        widgetAllTrophies = new QWidget();
        widgetAllTrophies->setObjectName(QString::fromUtf8("widgetAllTrophies"));
        widgetAllTrophies->setGeometry(QRect(0, 0, 568, 398));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetAllTrophies->sizePolicy().hasHeightForWidth());
        widgetAllTrophies->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(widgetAllTrophies);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea->setWidget(widgetAllTrophies);

        horizontalLayout_6->addWidget(scrollArea);

        widget_2 = new QWidget(widget_12);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(400, 0));
        verticalLayout_11 = new QVBoxLayout(widget_2);
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        labelName = new QLabel(widget_2);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(labelName);

        widgetBronze = new QFrame(widget_2);
        widgetBronze->setObjectName(QString::fromUtf8("widgetBronze"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widgetBronze->sizePolicy().hasHeightForWidth());
        widgetBronze->setSizePolicy(sizePolicy2);
        widgetBronze->setMinimumSize(QSize(0, 70));
        widgetBronze->setFrameShape(QFrame::StyledPanel);
        widgetBronze->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(widgetBronze);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widgetBronze);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(40, 40));
        label->setMaximumSize(QSize(40, 40));
        label->setPixmap(QPixmap(QString::fromUtf8("resources/trophy_bronze.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        widget_3 = new QWidget(widgetBronze);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy4);
        verticalLayout_7 = new QVBoxLayout(widget_3);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        labelBronze = new QLabel(widget_3);
        labelBronze->setObjectName(QString::fromUtf8("labelBronze"));
        sizePolicy.setHeightForWidth(labelBronze->sizePolicy().hasHeightForWidth());
        labelBronze->setSizePolicy(sizePolicy);
        labelBronze->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(labelBronze);

        progressBarBronze = new QProgressBar(widget_3);
        progressBarBronze->setObjectName(QString::fromUtf8("progressBarBronze"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(progressBarBronze->sizePolicy().hasHeightForWidth());
        progressBarBronze->setSizePolicy(sizePolicy5);
        progressBarBronze->setMaximum(120);
        progressBarBronze->setValue(120);
        progressBarBronze->setAlignment(Qt::AlignCenter);
        progressBarBronze->setTextVisible(true);
        progressBarBronze->setInvertedAppearance(false);

        verticalLayout_7->addWidget(progressBarBronze);


        horizontalLayout->addWidget(widget_3);

        widget_8 = new QWidget(widgetBronze);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_3 = new QVBoxLayout(widget_8);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelExplBronze = new QLabel(widget_8);
        labelExplBronze->setObjectName(QString::fromUtf8("labelExplBronze"));
        sizePolicy.setHeightForWidth(labelExplBronze->sizePolicy().hasHeightForWidth());
        labelExplBronze->setSizePolicy(sizePolicy);
        labelExplBronze->setMinimumSize(QSize(0, 30));
        labelExplBronze->setWordWrap(true);

        verticalLayout_3->addWidget(labelExplBronze);


        horizontalLayout->addWidget(widget_8);


        verticalLayout_11->addWidget(widgetBronze);

        widgetSilver = new QFrame(widget_2);
        widgetSilver->setObjectName(QString::fromUtf8("widgetSilver"));
        sizePolicy2.setHeightForWidth(widgetSilver->sizePolicy().hasHeightForWidth());
        widgetSilver->setSizePolicy(sizePolicy2);
        widgetSilver->setMinimumSize(QSize(0, 70));
        widgetSilver->setFrameShape(QFrame::StyledPanel);
        widgetSilver->setFrameShadow(QFrame::Sunken);
        horizontalLayout_2 = new QHBoxLayout(widgetSilver);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(widgetSilver);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setMinimumSize(QSize(40, 40));
        label_4->setMaximumSize(QSize(40, 40));
        label_4->setPixmap(QPixmap(QString::fromUtf8("resources/trophy_silver.png")));
        label_4->setScaledContents(true);

        horizontalLayout_2->addWidget(label_4);

        widget_4 = new QWidget(widgetSilver);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy4.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy4);
        verticalLayout_10 = new QVBoxLayout(widget_4);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        labelSilver = new QLabel(widget_4);
        labelSilver->setObjectName(QString::fromUtf8("labelSilver"));
        labelSilver->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(labelSilver);

        progressBarSilver = new QProgressBar(widget_4);
        progressBarSilver->setObjectName(QString::fromUtf8("progressBarSilver"));
        sizePolicy5.setHeightForWidth(progressBarSilver->sizePolicy().hasHeightForWidth());
        progressBarSilver->setSizePolicy(sizePolicy5);
        progressBarSilver->setMaximum(360);
        progressBarSilver->setValue(360);
        progressBarSilver->setAlignment(Qt::AlignCenter);
        progressBarSilver->setTextVisible(true);
        progressBarSilver->setInvertedAppearance(false);

        verticalLayout_10->addWidget(progressBarSilver);


        horizontalLayout_2->addWidget(widget_4);

        widget_9 = new QWidget(widgetSilver);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        verticalLayout_6 = new QVBoxLayout(widget_9);
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        labelExplSilver = new QLabel(widget_9);
        labelExplSilver->setObjectName(QString::fromUtf8("labelExplSilver"));
        labelExplSilver->setMinimumSize(QSize(0, 30));
        labelExplSilver->setWordWrap(true);

        verticalLayout_6->addWidget(labelExplSilver);


        horizontalLayout_2->addWidget(widget_9);


        verticalLayout_11->addWidget(widgetSilver);

        widgetGold = new QFrame(widget_2);
        widgetGold->setObjectName(QString::fromUtf8("widgetGold"));
        sizePolicy2.setHeightForWidth(widgetGold->sizePolicy().hasHeightForWidth());
        widgetGold->setSizePolicy(sizePolicy2);
        widgetGold->setMinimumSize(QSize(0, 70));
        widgetGold->setFrameShape(QFrame::StyledPanel);
        widgetGold->setFrameShadow(QFrame::Sunken);
        horizontalLayout_5 = new QHBoxLayout(widgetGold);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(widgetGold);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);
        label_8->setMinimumSize(QSize(40, 40));
        label_8->setMaximumSize(QSize(40, 40));
        label_8->setPixmap(QPixmap(QString::fromUtf8("resources/trophy_gold.png")));
        label_8->setScaledContents(true);

        horizontalLayout_5->addWidget(label_8);

        widget_5 = new QWidget(widgetGold);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy4.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy4);
        verticalLayout_9 = new QVBoxLayout(widget_5);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        labelGold = new QLabel(widget_5);
        labelGold->setObjectName(QString::fromUtf8("labelGold"));
        labelGold->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(labelGold);

        progressBarGold = new QProgressBar(widget_5);
        progressBarGold->setObjectName(QString::fromUtf8("progressBarGold"));
        sizePolicy5.setHeightForWidth(progressBarGold->sizePolicy().hasHeightForWidth());
        progressBarGold->setSizePolicy(sizePolicy5);
        progressBarGold->setMaximum(1080);
        progressBarGold->setValue(480);
        progressBarGold->setAlignment(Qt::AlignCenter);
        progressBarGold->setTextVisible(true);
        progressBarGold->setInvertedAppearance(false);

        verticalLayout_9->addWidget(progressBarGold);


        horizontalLayout_5->addWidget(widget_5);

        widget_10 = new QWidget(widgetGold);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        verticalLayout_5 = new QVBoxLayout(widget_10);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        labelExplGold = new QLabel(widget_10);
        labelExplGold->setObjectName(QString::fromUtf8("labelExplGold"));
        labelExplGold->setMinimumSize(QSize(0, 30));
        labelExplGold->setWordWrap(true);

        verticalLayout_5->addWidget(labelExplGold);


        horizontalLayout_5->addWidget(widget_10);


        verticalLayout_11->addWidget(widgetGold);

        widgetPlatinum = new QFrame(widget_2);
        widgetPlatinum->setObjectName(QString::fromUtf8("widgetPlatinum"));
        sizePolicy2.setHeightForWidth(widgetPlatinum->sizePolicy().hasHeightForWidth());
        widgetPlatinum->setSizePolicy(sizePolicy2);
        widgetPlatinum->setMinimumSize(QSize(0, 70));
        widgetPlatinum->setFrameShape(QFrame::StyledPanel);
        widgetPlatinum->setFrameShadow(QFrame::Sunken);
        horizontalLayout_3 = new QHBoxLayout(widgetPlatinum);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(widgetPlatinum);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setMinimumSize(QSize(40, 40));
        label_6->setMaximumSize(QSize(40, 40));
        label_6->setPixmap(QPixmap(QString::fromUtf8("resources/trophy_platinum.png")));
        label_6->setScaledContents(true);

        horizontalLayout_3->addWidget(label_6);

        widget_7 = new QWidget(widgetPlatinum);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        sizePolicy4.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy4);
        verticalLayout_8 = new QVBoxLayout(widget_7);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        labelPlatinum = new QLabel(widget_7);
        labelPlatinum->setObjectName(QString::fromUtf8("labelPlatinum"));
        labelPlatinum->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(labelPlatinum);

        progressBarPlatinum = new QProgressBar(widget_7);
        progressBarPlatinum->setObjectName(QString::fromUtf8("progressBarPlatinum"));
        sizePolicy5.setHeightForWidth(progressBarPlatinum->sizePolicy().hasHeightForWidth());
        progressBarPlatinum->setSizePolicy(sizePolicy5);
        progressBarPlatinum->setMaximum(3000);
        progressBarPlatinum->setValue(480);
        progressBarPlatinum->setAlignment(Qt::AlignCenter);
        progressBarPlatinum->setTextVisible(true);
        progressBarPlatinum->setInvertedAppearance(false);

        verticalLayout_8->addWidget(progressBarPlatinum);


        horizontalLayout_3->addWidget(widget_7);

        widget_11 = new QWidget(widgetPlatinum);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        verticalLayout_4 = new QVBoxLayout(widget_11);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelExplPlatinum = new QLabel(widget_11);
        labelExplPlatinum->setObjectName(QString::fromUtf8("labelExplPlatinum"));
        labelExplPlatinum->setMinimumSize(QSize(0, 30));
        labelExplPlatinum->setWordWrap(true);

        verticalLayout_4->addWidget(labelExplPlatinum);


        horizontalLayout_3->addWidget(widget_11);


        verticalLayout_11->addWidget(widgetPlatinum);


        horizontalLayout_6->addWidget(widget_2);


        verticalLayout_12->addWidget(widget_12);

        widget = new QWidget(WidgetTrophies);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(0, 0));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setSpacing(5);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        buttonReturn = new QPushButton(widget);
        buttonReturn->setObjectName(QString::fromUtf8("buttonReturn"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(buttonReturn->sizePolicy().hasHeightForWidth());
        buttonReturn->setSizePolicy(sizePolicy6);

        horizontalLayout_7->addWidget(buttonReturn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(20, 20));
        label_3->setPixmap(QPixmap(QString::fromUtf8("resources/trophy_bronze.png")));
        label_3->setScaledContents(true);

        horizontalLayout_7->addWidget(label_3);

        labelNbBronze = new QLabel(widget);
        labelNbBronze->setObjectName(QString::fromUtf8("labelNbBronze"));
        sizePolicy4.setHeightForWidth(labelNbBronze->sizePolicy().hasHeightForWidth());
        labelNbBronze->setSizePolicy(sizePolicy4);
        labelNbBronze->setMinimumSize(QSize(40, 0));

        horizontalLayout_7->addWidget(labelNbBronze);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(20, 20));
        label_12->setPixmap(QPixmap(QString::fromUtf8("resources/trophy_silver.png")));
        label_12->setScaledContents(true);

        horizontalLayout_7->addWidget(label_12);

        labelNbSilver = new QLabel(widget);
        labelNbSilver->setObjectName(QString::fromUtf8("labelNbSilver"));
        sizePolicy4.setHeightForWidth(labelNbSilver->sizePolicy().hasHeightForWidth());
        labelNbSilver->setSizePolicy(sizePolicy4);
        labelNbSilver->setMinimumSize(QSize(40, 0));

        horizontalLayout_7->addWidget(labelNbSilver);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(20, 20));
        label_14->setPixmap(QPixmap(QString::fromUtf8("resources/trophy_gold.png")));
        label_14->setScaledContents(true);

        horizontalLayout_7->addWidget(label_14);

        labelNbGold = new QLabel(widget);
        labelNbGold->setObjectName(QString::fromUtf8("labelNbGold"));
        sizePolicy4.setHeightForWidth(labelNbGold->sizePolicy().hasHeightForWidth());
        labelNbGold->setSizePolicy(sizePolicy4);
        labelNbGold->setMinimumSize(QSize(40, 0));

        horizontalLayout_7->addWidget(labelNbGold);

        label_16 = new QLabel(widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(20, 20));
        label_16->setPixmap(QPixmap(QString::fromUtf8("resources/trophy_platinum.png")));
        label_16->setScaledContents(true);

        horizontalLayout_7->addWidget(label_16);

        labelNbPlatinum = new QLabel(widget);
        labelNbPlatinum->setObjectName(QString::fromUtf8("labelNbPlatinum"));
        sizePolicy4.setHeightForWidth(labelNbPlatinum->sizePolicy().hasHeightForWidth());
        labelNbPlatinum->setSizePolicy(sizePolicy4);
        labelNbPlatinum->setMinimumSize(QSize(40, 0));

        horizontalLayout_7->addWidget(labelNbPlatinum);

        labelNbTotal = new QLabel(widget);
        labelNbTotal->setObjectName(QString::fromUtf8("labelNbTotal"));
        sizePolicy4.setHeightForWidth(labelNbTotal->sizePolicy().hasHeightForWidth());
        labelNbTotal->setSizePolicy(sizePolicy4);
        labelNbTotal->setMinimumSize(QSize(0, 0));

        horizontalLayout_7->addWidget(labelNbTotal);


        verticalLayout_12->addWidget(widget);


        retranslateUi(WidgetTrophies);

        QMetaObject::connectSlotsByName(WidgetTrophies);
    } // setupUi

    void retranslateUi(QFrame *WidgetTrophies)
    {
        WidgetTrophies->setWindowTitle(QApplication::translate("WidgetTrophies", "Frame", 0));
        labelName->setText(QApplication::translate("WidgetTrophies", "Collectionneur d'Ambre", 0));
        label->setText(QString());
        labelBronze->setText(QApplication::translate("WidgetTrophies", "Bronze", 0));
        progressBarBronze->setFormat(QApplication::translate("WidgetTrophies", "%v/%m", 0));
        labelExplBronze->setText(QApplication::translate("WidgetTrophies", "R\303\251cup\303\251rer un total de 150 gemmes d'Ambre.", 0));
        label_4->setText(QString());
        labelSilver->setText(QApplication::translate("WidgetTrophies", "Argent", 0));
        progressBarSilver->setFormat(QApplication::translate("WidgetTrophies", "%v/%m", 0));
        labelExplSilver->setText(QApplication::translate("WidgetTrophies", "R\303\251cup\303\251rer un total de 400 gemmes d'Ambre.", 0));
        label_8->setText(QString());
        labelGold->setText(QApplication::translate("WidgetTrophies", "Or", 0));
        progressBarGold->setFormat(QApplication::translate("WidgetTrophies", "%v/%m", 0));
        labelExplGold->setText(QApplication::translate("WidgetTrophies", "R\303\251cup\303\251rer un total de 1000 gemmes d'Ambre.", 0));
        label_6->setText(QString());
        labelPlatinum->setText(QApplication::translate("WidgetTrophies", "Platine", 0));
        progressBarPlatinum->setFormat(QApplication::translate("WidgetTrophies", "%v/%m", 0));
        labelExplPlatinum->setText(QApplication::translate("WidgetTrophies", "R\303\251cup\303\251rer un total de 3000 gemmes d'Ambre.", 0));
        buttonReturn->setText(QApplication::translate("WidgetTrophies", "Retour", 0));
        label_3->setText(QString());
        labelNbBronze->setText(QApplication::translate("WidgetTrophies", "50", 0));
        label_12->setText(QString());
        labelNbSilver->setText(QApplication::translate("WidgetTrophies", "50", 0));
        label_14->setText(QString());
        labelNbGold->setText(QApplication::translate("WidgetTrophies", "20", 0));
        label_16->setText(QString());
        labelNbPlatinum->setText(QApplication::translate("WidgetTrophies", "2", 0));
        labelNbTotal->setText(QApplication::translate("WidgetTrophies", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class WidgetTrophies: public Ui_WidgetTrophies {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETTROPHIES_H
