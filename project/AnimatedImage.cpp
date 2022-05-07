// Copyright Aurelien Lubecki 2012

#include "AnimatedImage.h"

AnimatedImage::AnimatedImage(QWidget *parent) : QWidget(parent),
                                                _nbHorizontal(-1),
                                                _nbVertical(-1),
                                                _duration(-1),
                                                _timerAnim(),
                                                _elapsedTimer(),
                                                _imagesForTime(),
                                                _labelImage(00)
{
    _labelImage = new QLabel(this);

    _timerAnim.setSingleShot(false);

    connect(&_timerAnim, SIGNAL(timeout()),
            this, SLOT(updateImagePosition()), Qt::UniqueConnection);
}

AnimatedImage::~AnimatedImage()
{
}

void AnimatedImage::init(const QImage &image, int nbHorizontal, int nbVertical, int duration, const QMap<int, int> &interpolations)
{
    assert(nbHorizontal > 0);
    assert(nbVertical > 0);

    assert(duration > 0);

    assert(interpolations.size() >= 2);
    foreach (qint32 percentage, interpolations.keys())
    {
        assert(percentage >= 0);
        assert(percentage < 100);
        assert(interpolations[percentage] >= -1);
        assert(interpolations[percentage] < (nbHorizontal * nbVertical));
    }

    _nbHorizontal = nbHorizontal;
    _nbVertical = nbVertical;
    _duration = duration;

    assert(!image.isNull());

    _imagesForTime.clear();
    qreal div = duration / 100.;
    foreach (int percentage, interpolations.keys())
    {
        _imagesForTime.insert(percentage * div, interpolations[percentage]);
    }
    if (!_imagesForTime.contains(0))
    {
        _imagesForTime.insert(0, -1);
    }

    _labelImage->setPixmap(QPixmap::fromImage(image));

    int imW = image.width();
    int imH = image.height();
    _labelImage->resize(imW, imH);

    int w = imW / _nbHorizontal;
    int h = imH / _nbVertical;
    resize(w, h);
}

void AnimatedImage::setVisible(bool visible)
{
    if (visible)
    {
        if (!isVisible())
        {
            startAnimation();
        }
    }
    else if (isVisible())
    {
        stopAnimation();
    }

    QWidget::setVisible(visible);
}

void AnimatedImage::startAnimation()
{
    stopAnimation();

    updateImagePosition();

    _timerAnim.start();
    _elapsedTimer.start();
}

void AnimatedImage::stopAnimation()
{
    _timerAnim.stop();
    _elapsedTimer.invalidate();
}

void AnimatedImage::updateImagePosition()
{
    qint64 elapsed = 0;
    if (_elapsedTimer.isValid())
    {
        elapsed = _elapsedTimer.elapsed() % _duration;
    }
    // else beginning

    int currentImage = -1;
    int newInterval = 0;

    QMap<int, int>::iterator it(_imagesForTime.find(elapsed));
    if (it == _imagesForTime.end())
    {
        // not found -> retry
        it = _imagesForTime.lowerBound(elapsed);
        assert(it != _imagesForTime.begin());

        it--;
    }

    currentImage = it.value();

    ++it;
    if (it == _imagesForTime.end())
    {
        newInterval = _duration - elapsed;
    }
    else
    {
        newInterval = it.key() - elapsed;
    }

    int x = ((currentImage + 1) / _nbVertical) - 1;
    int y = currentImage / _nbHorizontal;

    _labelImage->move(x * (-width()), y * (-height()));

    _timerAnim.setInterval(newInterval);
}
