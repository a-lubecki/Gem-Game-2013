// Copyright Aurelien Lubecki 2012

#include "CellPure.h"
#include "AnimatedImage.h"

CellPure::CellPure(int score, const QString &imagePath, const QString &name,
                   int type, int appearanceFrequency, const QString &typeName)
    : Cell(score, imagePath, name, type, appearanceFrequency, typeName),
      _animatedImage(00)
{
    _animatedImage = new AnimatedImage(this);

    QMap<int, int> interpolations;
    interpolations.insert(0, 0);
    interpolations.insert(10, 1);
    interpolations.insert(25, 2);
    interpolations.insert(40, 3);
    interpolations.insert(55, 4);
    interpolations.insert(70, 5);
    interpolations.insert(85, 6);
    _animatedImage->init(QImage(PATH_RESOURCES "shine.png"), 7, 1, 700, interpolations);

    _animatedImage->setAttribute(Qt::WA_TransparentForMouseEvents);

    int side = 9; //(CELL_SPACING - CELL_SIZE)/2. + 1;
    _animatedImage->move(side, side);
}

CellPure::~CellPure()
{
}

Cell *CellPure::clone() const
{
    return new CellPure(getScore(), getImagePath(), getName(), getType(), getAppearanceFrequency(), getTypeName());
}

void CellPure::setVisible(bool visible)
{
    _animatedImage->setVisible(visible);

    Cell::setVisible(visible);
}
