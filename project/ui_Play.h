/********************************************************************************
** Form generated from reading UI file 'Play.ui'
**
** Created: Mon 1. Apr 00:07:03 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAY_H
#define UI_PLAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "WidgetHelper.h"
#include "WidgetTrophies.h"

QT_BEGIN_NAMESPACE

class Ui_Play
{
public:
    QWidget *frame;
    QVBoxLayout *verticalLayout_8;
    QLabel *labelTitle;
    QHBoxLayout *horizontalLayout_6;
    QFrame *widgetPlay;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *labelLevel;
    QFrame *line_2;
    QLabel *label_3;
    QLabel *labelTextGoal;
    QProgressBar *progressBarGoal;
    QFrame *line_4;
    QLabel *label_2;
    QProgressBar *progressBarTime;
    QFrame *line_3;
    QLabel *label_4;
    QLabel *labelMultiplier;
    QFrame *line_5;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *buttonGiveUp;
    QWidget *widgetGrid;
    QVBoxLayout *verticalLayout_2;
    QWidget *buttons;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widgetCristals;
    QVBoxLayout *verticalLayout_5;
    QWidget *widgetPureCristals;
    QVBoxLayout *verticalLayout_6;
    QFrame *line;
    QLabel *label_7;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widgetItems1;
    QVBoxLayout *verticalLayout_3;
    QWidget *widgetItems2;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLabel *labelTotalScore;
    QWidget *widgetMenu;
    QVBoxLayout *verticalLayout_9;
    QLabel *labelEndMessage;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_11;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_5;
    QTableWidget *tableWidget;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *buttonHelp;
    QPushButton *buttonTrophies;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEditPlayerName;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *buttonStart;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    WidgetTrophies *widgetTrophies;
    WidgetHelper *widgetHelp;
    QLabel *labelCredits;

    void setupUi(QMainWindow *Play)
    {
        if (Play->objectName().isEmpty())
            Play->setObjectName(QString::fromUtf8("Play"));
        Play->resize(797, 566);
        Play->setMinimumSize(QSize(0, 0));
        Play->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QFrame\n"
"{\n"
"	border:2px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	border:auto;\n"
"}\n"
"\n"
"\n"
"QLineEdit\n"
"{\n"
"	border:1px solid rgb(40, 70, 100);\n"
"	border-radius:3px;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	border:1px solid rgb(40, 70, 100);\n"
"	border-radius:4px;\n"
"	min-width:100px;\n"
"	min-height:20px;\n"
"	padding:5px;\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0, radius:1.5, fx:0.5, fy:0, stop:0 rgb(255, 255, 255), stop:1 rgb(50, 130, 150));\n"
"}\n"
"\n"
"QPushButton:hover, QPushButton:focus\n"
"{\n"
"	background-color:rgb(210, 220, 255);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	color:rgb(150, 150, 150);\n"
"	border-color:rgb(150, 150, 150);\n"
"}\n"
"\n"
"\n"
"\n"
"QProgressBar \n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0, radius:1.5, fx:0.5, fy:0, stop:0 rgb(130, 210, 250), stop:1 rgb(0, 70, 100));\n"
"	border:1px solid rgb(40, 70, 100);\n"
"	border-radius:3px;\n"
"}\n"
"\n"
" QProgressBar::chunk\n"
"{\n"
"	"
                        "background-color: qradialgradient(spread:pad, cx:0.5, cy:0, radius:1.5, fx:0.5, fy:0, stop:0 rgb(255, 255, 255), stop:1 rgb(50, 130, 150));\n"
"	border:1px solid rgb(0, 70, 100);\n"
"	border-radius:2px;\n"
"	margin:1px;\n"
" }\n"
"\n"
"\n"
"#frame\n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgb(180, 230, 255), stop:1 rgb(50, 130, 150));\n"
"}\n"
"\n"
"#widgetGrid\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0, radius:1.5, fx:0.5, fy:0, stop:0 rgb(130, 210, 250), stop:1 rgb(0, 70, 100));\n"
"	border:2px solid rgb(40, 70, 100);\n"
"	border-radius:10px;\n"
"}\n"
"\n"
"#label, #labelTotalScore\n"
"{\n"
"	color:rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	font-weight:bold;\n"
"}\n"
"\n"
"#labelTitle\n"
"{\n"
"	color:rgb(255, 255, 255);\n"
"	font-size:50px;\n"
"	font-weight:bold;\n"
"}\n"
"\n"
"#labelEndMessage\n"
"{\n"
"	color:rgb(255, 255, 255);\n"
"	font-size:30px;\n"
"	font-weight:bold;\n"
"}\n"
"\n"
"#labelCredits\n"
"{\n"
"	color:rgb(255, 255,"
                        " 255);\n"
"}\n"
"\n"
"#labelTextGoal\n"
"{\n"
"	font-weight:bold;\n"
"}\n"
"\n"
"#labelMultiplier\n"
"{\n"
"	font-weight:bold;\n"
"}\n"
"\n"
"#labelLevel\n"
"{\n"
"	font-weight:bold;\n"
"	font-size:20px;\n"
"}\n"
"\n"
"QTableView {\n"
"	color:rgb(0, 0, 0);\n"
"	background-color:transparent;\n"
"	gridline-color:rgb(255, 255, 255);\n"
"	selection-color:rgb(255, 255, 255);\n"
"    selection-background-color:rgba(0, 0, 0, 100);\n"
"	border:none;\n"
" }\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"     background:transparent;\n"
" }\n"
"\n"
"QTableView QHeaderView {\n"
"	border:none;\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"QTableView QHeaderView::section {\n"
"	border:1px solid rgb(255, 255, 255);\n"
"	color:rgb(0, 0, 0);\n"
"    background-color:transparent;\n"
"	padding:2px 5px;\n"
" }\n"
""));
        frame = new QWidget(Play);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        labelTitle = new QLabel(frame);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy1);
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(labelTitle);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widgetPlay = new QFrame(frame);
        widgetPlay->setObjectName(QString::fromUtf8("widgetPlay"));
        sizePolicy.setHeightForWidth(widgetPlay->sizePolicy().hasHeightForWidth());
        widgetPlay->setSizePolicy(sizePolicy);
        widgetPlay->setFrameShape(QFrame::StyledPanel);
        widgetPlay->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(widgetPlay);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_4 = new QWidget(widgetPlay);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy2);
        widget_4->setMinimumSize(QSize(150, 0));
        widget_4->setMaximumSize(QSize(150, 16777215));
        verticalLayout_7 = new QVBoxLayout(widget_4);
        verticalLayout_7->setSpacing(4);
        verticalLayout_7->setContentsMargins(4, 4, 4, 4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        labelLevel = new QLabel(widget_4);
        labelLevel->setObjectName(QString::fromUtf8("labelLevel"));
        labelLevel->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(labelLevel);

        line_2 = new QFrame(widget_4);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_2);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_3);

        labelTextGoal = new QLabel(widget_4);
        labelTextGoal->setObjectName(QString::fromUtf8("labelTextGoal"));
        sizePolicy3.setHeightForWidth(labelTextGoal->sizePolicy().hasHeightForWidth());
        labelTextGoal->setSizePolicy(sizePolicy3);
        labelTextGoal->setWordWrap(true);

        verticalLayout_7->addWidget(labelTextGoal);

        progressBarGoal = new QProgressBar(widget_4);
        progressBarGoal->setObjectName(QString::fromUtf8("progressBarGoal"));
        progressBarGoal->setMaximum(55);
        progressBarGoal->setValue(50);
        progressBarGoal->setAlignment(Qt::AlignCenter);
        progressBarGoal->setOrientation(Qt::Horizontal);
        progressBarGoal->setInvertedAppearance(false);
        progressBarGoal->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout_7->addWidget(progressBarGoal);

        line_4 = new QFrame(widget_4);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_4);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_2);

        progressBarTime = new QProgressBar(widget_4);
        progressBarTime->setObjectName(QString::fromUtf8("progressBarTime"));
        progressBarTime->setValue(24);
        progressBarTime->setAlignment(Qt::AlignCenter);
        progressBarTime->setOrientation(Qt::Horizontal);
        progressBarTime->setInvertedAppearance(false);
        progressBarTime->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout_7->addWidget(progressBarTime);

        line_3 = new QFrame(widget_4);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_3);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_4);

        labelMultiplier = new QLabel(widget_4);
        labelMultiplier->setObjectName(QString::fromUtf8("labelMultiplier"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelMultiplier->sizePolicy().hasHeightForWidth());
        labelMultiplier->setSizePolicy(sizePolicy4);
        labelMultiplier->setMinimumSize(QSize(0, 70));
        labelMultiplier->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(labelMultiplier);

        line_5 = new QFrame(widget_4);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_5);

        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_9 = new QHBoxLayout(widget_8);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        buttonGiveUp = new QPushButton(widget_8);
        buttonGiveUp->setObjectName(QString::fromUtf8("buttonGiveUp"));
        sizePolicy.setHeightForWidth(buttonGiveUp->sizePolicy().hasHeightForWidth());
        buttonGiveUp->setSizePolicy(sizePolicy);
        buttonGiveUp->setMinimumSize(QSize(112, 32));

        horizontalLayout_9->addWidget(buttonGiveUp);


        verticalLayout_7->addWidget(widget_8);


        horizontalLayout->addWidget(widget_4);

        widgetGrid = new QWidget(widgetPlay);
        widgetGrid->setObjectName(QString::fromUtf8("widgetGrid"));
        sizePolicy.setHeightForWidth(widgetGrid->sizePolicy().hasHeightForWidth());
        widgetGrid->setSizePolicy(sizePolicy);
        widgetGrid->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(widgetGrid);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        horizontalLayout->addWidget(widgetGrid);

        buttons = new QWidget(widgetPlay);
        buttons->setObjectName(QString::fromUtf8("buttons"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(buttons->sizePolicy().hasHeightForWidth());
        buttons->setSizePolicy(sizePolicy5);
        verticalLayout = new QVBoxLayout(buttons);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(buttons);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        widget = new QWidget(buttons);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widgetCristals = new QWidget(widget);
        widgetCristals->setObjectName(QString::fromUtf8("widgetCristals"));
        sizePolicy3.setHeightForWidth(widgetCristals->sizePolicy().hasHeightForWidth());
        widgetCristals->setSizePolicy(sizePolicy3);
        widgetCristals->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(widgetCristals);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));

        horizontalLayout_3->addWidget(widgetCristals);

        widgetPureCristals = new QWidget(widget);
        widgetPureCristals->setObjectName(QString::fromUtf8("widgetPureCristals"));
        sizePolicy3.setHeightForWidth(widgetPureCristals->sizePolicy().hasHeightForWidth());
        widgetPureCristals->setSizePolicy(sizePolicy3);
        widgetPureCristals->setMinimumSize(QSize(0, 0));
        verticalLayout_6 = new QVBoxLayout(widgetPureCristals);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));

        horizontalLayout_3->addWidget(widgetPureCristals);


        verticalLayout->addWidget(widget);

        line = new QFrame(buttons);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_7 = new QLabel(buttons);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        widget_2 = new QWidget(buttons);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widgetItems1 = new QWidget(widget_2);
        widgetItems1->setObjectName(QString::fromUtf8("widgetItems1"));
        sizePolicy3.setHeightForWidth(widgetItems1->sizePolicy().hasHeightForWidth());
        widgetItems1->setSizePolicy(sizePolicy3);
        widgetItems1->setMinimumSize(QSize(0, 0));
        verticalLayout_3 = new QVBoxLayout(widgetItems1);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        horizontalLayout_2->addWidget(widgetItems1);

        widgetItems2 = new QWidget(widget_2);
        widgetItems2->setObjectName(QString::fromUtf8("widgetItems2"));
        sizePolicy3.setHeightForWidth(widgetItems2->sizePolicy().hasHeightForWidth());
        widgetItems2->setSizePolicy(sizePolicy3);
        widgetItems2->setMinimumSize(QSize(0, 0));
        verticalLayout_4 = new QVBoxLayout(widgetItems2);
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));

        horizontalLayout_2->addWidget(widgetItems2);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(buttons);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label);

        labelTotalScore = new QLabel(widget_3);
        labelTotalScore->setObjectName(QString::fromUtf8("labelTotalScore"));
        sizePolicy3.setHeightForWidth(labelTotalScore->sizePolicy().hasHeightForWidth());
        labelTotalScore->setSizePolicy(sizePolicy3);
        labelTotalScore->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(labelTotalScore);


        verticalLayout->addWidget(widget_3);


        horizontalLayout->addWidget(buttons);


        horizontalLayout_6->addWidget(widgetPlay);

        widgetMenu = new QWidget(frame);
        widgetMenu->setObjectName(QString::fromUtf8("widgetMenu"));
        sizePolicy.setHeightForWidth(widgetMenu->sizePolicy().hasHeightForWidth());
        widgetMenu->setSizePolicy(sizePolicy);
        verticalLayout_9 = new QVBoxLayout(widgetMenu);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        labelEndMessage = new QLabel(widgetMenu);
        labelEndMessage->setObjectName(QString::fromUtf8("labelEndMessage"));
        labelEndMessage->setMinimumSize(QSize(0, 100));
        labelEndMessage->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(labelEndMessage);

        widget_10 = new QWidget(widgetMenu);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(0, 0));
        horizontalLayout_11 = new QHBoxLayout(widget_10);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        widget_11 = new QWidget(widget_10);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setMaximumSize(QSize(500, 16777215));
        verticalLayout_10 = new QVBoxLayout(widget_11);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_5 = new QLabel(widget_11);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_5);

        tableWidget = new QTableWidget(widget_11);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(450, 240));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_10->addWidget(tableWidget);

        widget_9 = new QWidget(widget_11);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_10 = new QHBoxLayout(widget_9);
        horizontalLayout_10->setSpacing(10);
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        buttonHelp = new QPushButton(widget_9);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
        sizePolicy.setHeightForWidth(buttonHelp->sizePolicy().hasHeightForWidth());
        buttonHelp->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(buttonHelp);

        buttonTrophies = new QPushButton(widget_9);
        buttonTrophies->setObjectName(QString::fromUtf8("buttonTrophies"));
        sizePolicy.setHeightForWidth(buttonTrophies->sizePolicy().hasHeightForWidth());
        buttonTrophies->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(buttonTrophies);


        verticalLayout_10->addWidget(widget_9);

        widget_7 = new QWidget(widget_11);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_8 = new QHBoxLayout(widget_7);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(widget_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEditPlayerName = new QLineEdit(widget_7);
        lineEditPlayerName->setObjectName(QString::fromUtf8("lineEditPlayerName"));
        lineEditPlayerName->setMaxLength(10);

        horizontalLayout_8->addWidget(lineEditPlayerName);


        verticalLayout_10->addWidget(widget_7);

        widget_6 = new QWidget(widget_11);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        buttonStart = new QPushButton(widget_6);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        sizePolicy.setHeightForWidth(buttonStart->sizePolicy().hasHeightForWidth());
        buttonStart->setSizePolicy(sizePolicy);
        buttonStart->setMinimumSize(QSize(112, 32));

        horizontalLayout_5->addWidget(buttonStart);


        verticalLayout_10->addWidget(widget_6);


        horizontalLayout_11->addWidget(widget_11);


        verticalLayout_9->addWidget(widget_10);

        widget_5 = new QWidget(widgetMenu);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy1.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy1);
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));

        verticalLayout_9->addWidget(widget_5);


        horizontalLayout_6->addWidget(widgetMenu);

        widgetTrophies = new WidgetTrophies(frame);
        widgetTrophies->setObjectName(QString::fromUtf8("widgetTrophies"));
        sizePolicy.setHeightForWidth(widgetTrophies->sizePolicy().hasHeightForWidth());
        widgetTrophies->setSizePolicy(sizePolicy);
        widgetTrophies->setMinimumSize(QSize(0, 0));
        widgetTrophies->setFrameShape(QFrame::StyledPanel);
        widgetTrophies->setFrameShadow(QFrame::Raised);

        horizontalLayout_6->addWidget(widgetTrophies);

        widgetHelp = new WidgetHelper(frame);
        widgetHelp->setObjectName(QString::fromUtf8("widgetHelp"));
        sizePolicy.setHeightForWidth(widgetHelp->sizePolicy().hasHeightForWidth());
        widgetHelp->setSizePolicy(sizePolicy);
        widgetHelp->setMinimumSize(QSize(0, 0));
        widgetHelp->setFrameShape(QFrame::StyledPanel);
        widgetHelp->setFrameShadow(QFrame::Raised);

        horizontalLayout_6->addWidget(widgetHelp);


        verticalLayout_8->addLayout(horizontalLayout_6);

        labelCredits = new QLabel(frame);
        labelCredits->setObjectName(QString::fromUtf8("labelCredits"));
        sizePolicy1.setHeightForWidth(labelCredits->sizePolicy().hasHeightForWidth());
        labelCredits->setSizePolicy(sizePolicy1);
        labelCredits->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(labelCredits);

        Play->setCentralWidget(frame);

        retranslateUi(Play);

        QMetaObject::connectSlotsByName(Play);
    } // setupUi

    void retranslateUi(QMainWindow *Play)
    {
        Play->setWindowTitle(QApplication::translate("Play", "MainWindow", 0));
        labelTitle->setText(QApplication::translate("Play", "Gem Game", 0));
        labelLevel->setText(QApplication::translate("Play", "Niveau 42", 0));
        label_3->setText(QApplication::translate("Play", "Objectif", 0));
        labelTextGoal->setText(QApplication::translate("Play", "TextLabel", 0));
        progressBarGoal->setFormat(QApplication::translate("Play", "%v/%m", 0));
        label_2->setText(QApplication::translate("Play", "Temps", 0));
        progressBarTime->setFormat(QString());
        label_4->setText(QApplication::translate("Play", "Multiplicateur", 0));
        labelMultiplier->setText(QApplication::translate("Play", "TextLabel", 0));
        buttonGiveUp->setText(QApplication::translate("Play", "Abandonner", 0));
        label_6->setText(QApplication::translate("Play", "Gemmes", 0));
        label_7->setText(QApplication::translate("Play", "Items", 0));
        label->setText(QApplication::translate("Play", "Score :", 0));
        labelTotalScore->setText(QApplication::translate("Play", "TextLabel", 0));
        labelEndMessage->setText(QApplication::translate("Play", "TextLabel aaaaaaaa aaaaaaa", 0));
        label_5->setText(QApplication::translate("Play", "Meilleurs scores :", 0));
        buttonHelp->setText(QApplication::translate("Play", "Aide", 0));
        buttonTrophies->setText(QApplication::translate("Play", "Troph\303\251es", 0));
        label_8->setText(QApplication::translate("Play", "Entrez votre nom :", 0));
        buttonStart->setText(QApplication::translate("Play", "D\303\251marrer", 0));
        labelCredits->setText(QApplication::translate("Play", "Gem Game - Aur\303\251lien Lubecki - 2013", 0));
    } // retranslateUi

};

namespace Ui {
    class Play: public Ui_Play {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAY_H
