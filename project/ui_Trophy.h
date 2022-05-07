/********************************************************************************
** Form generated from reading UI file 'Trophy.ui'
**
** Created: Mon 1. Apr 00:07:03 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TROPHY_H
#define UI_TROPHY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Trophy
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelName;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QLabel *labelNum;
    QLabel *labelPercentage;
    QLabel *labelImage;

    void setupUi(QWidget *Trophy)
    {
        if (Trophy->objectName().isEmpty())
            Trophy->setObjectName(QString::fromUtf8("Trophy"));
        Trophy->resize(100, 100);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Trophy->sizePolicy().hasHeightForWidth());
        Trophy->setSizePolicy(sizePolicy);
        Trophy->setStyleSheet(QString::fromUtf8("\n"
"#widget\n"
"{\n"
"	border:2px solid rgb(255, 255, 255);\n"
"	border-radius:50px;\n"
"	\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, \n"
"stop:0 rgba(255, 150, 150, 150), \n"
"stop:1 rgba(150, 0, 0, 150));\n"
"}\n"
"\n"
"#labelName, #labelPercentage\n"
"{\n"
"	color:rgb(255, 255, 255);\n"
"	font-size:10px;\n"
"    background-color: qradialgradient(spread:pad, cx:0.5, cy:0, radius:1.5, fx:0.5, fy:0, \n"
"stop:0 rgb(130, 210, 250), \n"
"stop:1 rgb(0, 70, 100));\n"
"    border:1px solid rgb(40, 70, 100);\n"
"    border-radius:3px;\n"
"}\n"
"\n"
"#labelPercentage\n"
"{\n"
"	font-weight:bold;\n"
"}\n"
"\n"
" #labelNum\n"
"{\n"
"	font-weight:bold;\n"
"	color:rgb(255, 255, 255);\n"
"	font-size:16px;\n"
" }"));
        horizontalLayout_2 = new QHBoxLayout(Trophy);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QFrame(Trophy);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(100, 100));
        widget->setMaximumSize(QSize(100, 100));
        widget->setFrameShape(QFrame::StyledPanel);
        widget->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelName = new QLabel(widget);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelName->sizePolicy().hasHeightForWidth());
        labelName->setSizePolicy(sizePolicy2);
        labelName->setAlignment(Qt::AlignCenter);
        labelName->setWordWrap(true);

        verticalLayout_2->addWidget(labelName);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy3);
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelNum = new QLabel(widget_3);
        labelNum->setObjectName(QString::fromUtf8("labelNum"));
        labelNum->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelNum);

        labelPercentage = new QLabel(widget_3);
        labelPercentage->setObjectName(QString::fromUtf8("labelPercentage"));
        sizePolicy2.setHeightForWidth(labelPercentage->sizePolicy().hasHeightForWidth());
        labelPercentage->setSizePolicy(sizePolicy2);
        labelPercentage->setMinimumSize(QSize(0, 0));
        labelPercentage->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelPercentage);


        horizontalLayout->addWidget(widget_3);

        labelImage = new QLabel(widget_2);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setMinimumSize(QSize(40, 40));
        labelImage->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(labelImage);


        verticalLayout_2->addWidget(widget_2);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(Trophy);

        QMetaObject::connectSlotsByName(Trophy);
    } // setupUi

    void retranslateUi(QWidget *Trophy)
    {
        Trophy->setWindowTitle(QApplication::translate("Trophy", "Form", 0));
        labelName->setText(QApplication::translate("Trophy", "Collectionneur d'Ambre (facile) aaa", 0));
        labelNum->setText(QApplication::translate("Trophy", "50", 0));
        labelPercentage->setText(QApplication::translate("Trophy", "100%", 0));
        labelImage->setText(QApplication::translate("Trophy", "Text", 0));
    } // retranslateUi

};

namespace Ui {
    class Trophy: public Ui_Trophy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TROPHY_H
