// Copyright Aurelien Lubecki 2012

#pragma once

#include "stdafx.h"

class AnimatedImage : public QWidget
{
    Q_OBJECT

    int _nbHorizontal;
    int _nbVertical;

    int _duration;


    QTimer _timerAnim;
    QElapsedTimer _elapsedTimer;

    QMap<int, int> _imagesForTime;//<times, numImage>

    QLabel* _labelImage;

    void startAnimation();
    void stopAnimation();

public:
    explicit AnimatedImage(QWidget *parent = 0);
    virtual ~AnimatedImage();

    void init(const QImage& image, int nbHorizontal, int nbVertical,
              int duration, const QMap<int, int>& interpolations);//<percentage, num image>

    virtual void setVisible(bool visible);

private slots:
    void updateImagePosition();
};
