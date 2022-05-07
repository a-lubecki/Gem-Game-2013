/********************************************************************************
** Form generated from reading UI file 'WidgetHelper.ui'
**
** Created: Thu 21. Mar 22:21:56 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETHELPER_H
#define UI_WIDGETHELPER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetHelper
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QListView *listViewHelp;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *buttonReturnHelp;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_11;
    QLabel *labelHelpTitle;
    QLabel *labelHelpImage;
    QLabel *labelHelpExplanation;

    void setupUi(QFrame *WidgetHelper)
    {
        if (WidgetHelper->objectName().isEmpty())
            WidgetHelper->setObjectName(QString::fromUtf8("WidgetHelper"));
        WidgetHelper->resize(712, 516);
        WidgetHelper->setStyleSheet(QString::fromUtf8("\n"
"#labelHelpTitle\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font-weight:bold;\n"
"	font-size:25px;\n"
"}\n"
"\n"
"#labelHelpExplanation\n"
"{\n"
"	font-size:14px;\n"
"}\n"
"\n"
"#listViewHelp\n"
"{\n"
"	border:2px solid rgb(255, 255, 255);\n"
"	border-radius:5px;\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}"));
        WidgetHelper->setFrameShape(QFrame::StyledPanel);
        WidgetHelper->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(WidgetHelper);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(WidgetHelper);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listViewHelp = new QListView(widget);
        listViewHelp->setObjectName(QString::fromUtf8("listViewHelp"));
        sizePolicy.setHeightForWidth(listViewHelp->sizePolicy().hasHeightForWidth());
        listViewHelp->setSizePolicy(sizePolicy);
        listViewHelp->setMinimumSize(QSize(150, 0));
        listViewHelp->setMaximumSize(QSize(150, 16777215));

        verticalLayout_2->addWidget(listViewHelp);

        widget_10 = new QWidget(widget);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_10->sizePolicy().hasHeightForWidth());
        widget_10->setSizePolicy(sizePolicy1);
        horizontalLayout_10 = new QHBoxLayout(widget_10);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        buttonReturnHelp = new QPushButton(widget_10);
        buttonReturnHelp->setObjectName(QString::fromUtf8("buttonReturnHelp"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonReturnHelp->sizePolicy().hasHeightForWidth());
        buttonReturnHelp->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(buttonReturnHelp);


        verticalLayout_2->addWidget(widget_10);


        horizontalLayout->addWidget(widget);

        widget_9 = new QWidget(WidgetHelper);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        verticalLayout_11 = new QVBoxLayout(widget_9);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        labelHelpTitle = new QLabel(widget_9);
        labelHelpTitle->setObjectName(QString::fromUtf8("labelHelpTitle"));
        sizePolicy1.setHeightForWidth(labelHelpTitle->sizePolicy().hasHeightForWidth());
        labelHelpTitle->setSizePolicy(sizePolicy1);
        labelHelpTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(labelHelpTitle);

        labelHelpImage = new QLabel(widget_9);
        labelHelpImage->setObjectName(QString::fromUtf8("labelHelpImage"));
        labelHelpImage->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(labelHelpImage);

        labelHelpExplanation = new QLabel(widget_9);
        labelHelpExplanation->setObjectName(QString::fromUtf8("labelHelpExplanation"));
        sizePolicy1.setHeightForWidth(labelHelpExplanation->sizePolicy().hasHeightForWidth());
        labelHelpExplanation->setSizePolicy(sizePolicy1);
        labelHelpExplanation->setMinimumSize(QSize(500, 120));
        labelHelpExplanation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelHelpExplanation->setWordWrap(true);

        verticalLayout_11->addWidget(labelHelpExplanation);


        horizontalLayout->addWidget(widget_9);


        retranslateUi(WidgetHelper);

        QMetaObject::connectSlotsByName(WidgetHelper);
    } // setupUi

    void retranslateUi(QFrame *WidgetHelper)
    {
        WidgetHelper->setWindowTitle(QApplication::translate("WidgetHelper", "Frame", 0));
        buttonReturnHelp->setText(QApplication::translate("WidgetHelper", "Retour", 0));
        labelHelpTitle->setText(QApplication::translate("WidgetHelper", "TextLabel", 0));
        labelHelpImage->setText(QApplication::translate("WidgetHelper", "TextLabel", 0));
        labelHelpExplanation->setText(QApplication::translate("WidgetHelper", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class WidgetHelper: public Ui_WidgetHelper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETHELPER_H
