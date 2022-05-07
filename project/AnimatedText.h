// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"

namespace Ui {
class AnimatedText;
}

class AnimatedText : public QWidget
{
    Q_OBJECT

    Ui::AnimatedText *ui;

    QPropertyAnimation _animPosRight;
    QPropertyAnimation _animPosLeft;

    QPropertyAnimation _animTransRight;
    QPropertyAnimation _animTransLeft;
    QPropertyAnimation _animTransUp;

    QTimer _timerHide;

public:
    explicit AnimatedText(QWidget *parent = 0);
    virtual ~AnimatedText();

    virtual void showText(const QString& text);

protected:
    virtual void resizeEvent(QResizeEvent* event);
};
