/********************************************************************************
** Form generated from reading UI file 'AnimatedText.ui'
**
** Created: Tue 12. Mar 02:06:03 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMATEDTEXT_H
#define UI_ANIMATEDTEXT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimatedText
{
public:
    QLabel *labelUp;
    QLabel *labelRight;
    QLabel *labelLeft;

    void setupUi(QWidget *AnimatedText)
    {
        if (AnimatedText->objectName().isEmpty())
            AnimatedText->setObjectName(QString::fromUtf8("AnimatedText"));
        AnimatedText->resize(640, 480);
        AnimatedText->setStyleSheet(QString::fromUtf8(""));
        labelUp = new QLabel(AnimatedText);
        labelUp->setObjectName(QString::fromUtf8("labelUp"));
        labelUp->setGeometry(QRect(240, 220, 46, 13));
        labelUp->setAlignment(Qt::AlignCenter);
        labelRight = new QLabel(AnimatedText);
        labelRight->setObjectName(QString::fromUtf8("labelRight"));
        labelRight->setGeometry(QRect(80, 280, 46, 13));
        labelRight->setAlignment(Qt::AlignCenter);
        labelLeft = new QLabel(AnimatedText);
        labelLeft->setObjectName(QString::fromUtf8("labelLeft"));
        labelLeft->setGeometry(QRect(180, 290, 46, 13));
        labelLeft->setAlignment(Qt::AlignCenter);

        retranslateUi(AnimatedText);

        QMetaObject::connectSlotsByName(AnimatedText);
    } // setupUi

    void retranslateUi(QWidget *AnimatedText)
    {
        AnimatedText->setWindowTitle(QApplication::translate("AnimatedText", "Form", 0));
        labelUp->setText(QApplication::translate("AnimatedText", "TextLabel", 0));
        labelRight->setText(QApplication::translate("AnimatedText", "TextLabel", 0));
        labelLeft->setText(QApplication::translate("AnimatedText", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class AnimatedText: public Ui_AnimatedText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATEDTEXT_H
