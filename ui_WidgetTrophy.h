/********************************************************************************
** Form generated from reading UI file 'WidgetTrophy.ui'
**
** Created: Mon 25. Mar 19:16:18 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETTROPHY_H
#define UI_WIDGETTROPHY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WidgetTrophy
{
public:
    QLabel *labelName;
    QLabel *labelNew;

    void setupUi(QFrame *WidgetTrophy)
    {
        if (WidgetTrophy->objectName().isEmpty())
            WidgetTrophy->setObjectName(QString::fromUtf8("WidgetTrophy"));
        WidgetTrophy->resize(332, 238);
        WidgetTrophy->setFrameShape(QFrame::StyledPanel);
        WidgetTrophy->setFrameShadow(QFrame::Raised);
        labelName = new QLabel(WidgetTrophy);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setGeometry(QRect(100, 40, 111, 16));
        labelNew = new QLabel(WidgetTrophy);
        labelNew->setObjectName(QString::fromUtf8("labelNew"));
        labelNew->setGeometry(QRect(190, 150, 46, 13));

        retranslateUi(WidgetTrophy);

        QMetaObject::connectSlotsByName(WidgetTrophy);
    } // setupUi

    void retranslateUi(QFrame *WidgetTrophy)
    {
        WidgetTrophy->setWindowTitle(QApplication::translate("WidgetTrophy", "Frame", 0));
        labelName->setText(QApplication::translate("WidgetTrophy", "Nom du trophee", 0));
        labelNew->setText(QApplication::translate("WidgetTrophy", "Nouveau", 0));
    } // retranslateUi

};

namespace Ui {
    class WidgetTrophy: public Ui_WidgetTrophy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETTROPHY_H
