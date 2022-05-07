/********************************************************************************
** Form generated from reading UI file 'CellCounter.ui'
**
** Created: Sun 3. Mar 02:53:55 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLCOUNTER_H
#define UI_CELLCOUNTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CellCounter
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *frame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelName;
    QLabel *labelScore;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *CellCounter)
    {
        if (CellCounter->objectName().isEmpty())
            CellCounter->setObjectName(QString::fromUtf8("CellCounter"));
        CellCounter->resize(138, 83);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CellCounter->sizePolicy().hasHeightForWidth());
        CellCounter->setSizePolicy(sizePolicy);
        CellCounter->setMinimumSize(QSize(0, 0));
        CellCounter->setMaximumSize(QSize(16777215, 16777215));
        CellCounter->setStyleSheet(QString::fromUtf8("\n"
"#frame {\n"
"	background-color:rgba(255, 255, 255, 150);\n"
"    border-radius:16px;\n"
"}\n"
"\n"
"#labelName\n"
"{\n"
"	font-size:9px;\n"
"}\n"
"\n"
"#labelScore\n"
"{\n"
"	font-weight:bold;\n"
"	font-size:14px;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(CellCounter);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QWidget(CellCounter);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(110, 0));
        frame->setMaximumSize(QSize(110, 16777215));
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget_2 = new QWidget(frame);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelName = new QLabel(widget_2);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelName->sizePolicy().hasHeightForWidth());
        labelName->setSizePolicy(sizePolicy1);
        labelName->setMinimumSize(QSize(0, 20));
        labelName->setMaximumSize(QSize(50, 16777215));
        labelName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelName->setWordWrap(true);

        verticalLayout->addWidget(labelName);

        labelScore = new QLabel(widget_2);
        labelScore->setObjectName(QString::fromUtf8("labelScore"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelScore->sizePolicy().hasHeightForWidth());
        labelScore->setSizePolicy(sizePolicy2);
        labelScore->setMinimumSize(QSize(0, 0));
        labelScore->setMaximumSize(QSize(16777215, 16777215));
        labelScore->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(labelScore);


        horizontalLayout_2->addWidget(widget_2);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy3);
        widget->setMinimumSize(QSize(40, 40));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        horizontalLayout_2->addWidget(widget);


        horizontalLayout->addWidget(frame);


        retranslateUi(CellCounter);

        QMetaObject::connectSlotsByName(CellCounter);
    } // setupUi

    void retranslateUi(QWidget *CellCounter)
    {
        CellCounter->setWindowTitle(QApplication::translate("CellCounter", "Form", 0));
        labelName->setText(QApplication::translate("CellCounter", "TextLa hhhl", 0));
        labelScore->setText(QApplication::translate("CellCounter", "x100", 0));
    } // retranslateUi

};

namespace Ui {
    class CellCounter: public Ui_CellCounter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLCOUNTER_H
