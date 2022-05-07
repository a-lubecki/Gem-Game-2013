// Copyright Aurelien Lubecki 2012

#include "AnimatedText.h"
#include "ui_AnimatedText.h"
#include <QGraphicsOpacityEffect>

AnimatedText::AnimatedText(QWidget *parent) : QWidget(parent),
                                              ui(new Ui::AnimatedText),
                                              _animPosRight(),
                                              _animPosLeft(),
                                              _animTransRight(),
                                              _animTransLeft(),
                                              _animTransUp(),
                                              _timerHide()
{
    ui->setupUi(this);

    setStyleSheet("QLabel {"
                  "color:rgb(150, 0, 0);"
                  "font-weight:bold;"
                  "font-size:26px;"
                  "}"
                  "#labelRight, #labelLeft {"
                  "color:rgb(200, 50, 50);"
                  "}");

    int duration = 500;

    QGraphicsOpacityEffect *rightEffect = new QGraphicsOpacityEffect(this);
    ui->labelRight->setGraphicsEffect(rightEffect);
    QGraphicsOpacityEffect *leftEffect = new QGraphicsOpacityEffect(this);
    ui->labelLeft->setGraphicsEffect(leftEffect);
    QGraphicsOpacityEffect *upEffect = new QGraphicsOpacityEffect(this);
    ui->labelUp->setGraphicsEffect(upEffect);

    _animPosRight.setTargetObject(ui->labelRight);
    _animPosRight.setPropertyName("pos");
    _animPosRight.setEasingCurve(QEasingCurve::OutCurve);
    _animPosRight.setDuration(duration);

    _animPosLeft.setTargetObject(ui->labelLeft);
    _animPosLeft.setPropertyName("pos");
    _animPosLeft.setEasingCurve(QEasingCurve::OutCurve);
    _animPosLeft.setDuration(duration);

    _animTransRight.setTargetObject(rightEffect);
    _animTransRight.setPropertyName("opacity");
    _animTransRight.setEasingCurve(QEasingCurve::InCubic);
    _animTransRight.setKeyValueAt(0, 0);
    _animTransRight.setKeyValueAt(1, 1);
    _animTransRight.setDuration(duration);

    _animTransLeft.setTargetObject(leftEffect);
    _animTransLeft.setPropertyName("opacity");
    _animTransLeft.setEasingCurve(QEasingCurve::InCubic);
    _animTransLeft.setKeyValueAt(0, 0);
    _animTransLeft.setKeyValueAt(1, 1);
    _animTransLeft.setDuration(duration);

    _animTransUp.setTargetObject(upEffect);
    _animTransUp.setPropertyName("opacity");
    _animTransUp.setEasingCurve(QEasingCurve::InCubic);
    _animTransUp.setKeyValueAt(0, 0);
    _animTransUp.setKeyValueAt(1, 1);
    _animTransUp.setDuration(duration);

    ui->labelUp->move(0, 0);
    ui->labelRight->move(0, 0);
    ui->labelLeft->move(0, 0);
    ui->labelUp->raise();

    _timerHide.setSingleShot(true);
    _timerHide.setInterval(2000);
    connect(&_timerHide, SIGNAL(timeout()),
            this, SLOT(hide()), Qt::UniqueConnection);

    resize(500, 50);
    raise();
    hide();

    setAttribute(Qt::WA_TransparentForMouseEvents);
}

AnimatedText::~AnimatedText()
{
    delete ui;
}

void AnimatedText::showText(const QString &text)
{
    _timerHide.stop();

    ui->labelUp->setText(text);
    ui->labelRight->setText(text);
    ui->labelLeft->setText(text);

    _animPosRight.setKeyValueAt(0, QPoint(width() / 3., 0));
    _animPosRight.setKeyValueAt(1, QPoint(0, 0));
    _animPosLeft.setKeyValueAt(0, QPoint(-width() / 3., 0));
    _animPosLeft.setKeyValueAt(1, QPoint(0, 0));

    show();

    _animPosRight.start();
    _animPosLeft.start();
    _animTransRight.start();
    _animTransLeft.start();
    _animTransUp.start();

    _timerHide.start();
}

void AnimatedText::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    ui->labelUp->resize(size());
    ui->labelLeft->resize(size());
    ui->labelRight->resize(size());
}
