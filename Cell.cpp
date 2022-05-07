// Copyright Aurelien Lubecki 2012

#include "Cell.h"
#include "Grid.h"
#include <QtWidgets/QHBoxLayout>

Cell::Cell(int score, const QString &imagePath, const QString &name,
           int type, int appearanceFrequency, const QString &typeName) : QWidget(00),
                                                                         _score(score),
                                                                         _imagePath(imagePath),
                                                                         _image(imagePath),
                                                                         _name(name),
                                                                         _type(type),
                                                                         _appearanceFrequency(appearanceFrequency),
                                                                         _typeName(typeName),
                                                                         _canBeClicked(false),
                                                                         _aboutToDelete(false),
                                                                         _locationInGrid(-1, -1),
                                                                         _anim(this, "pos"),
                                                                         _labelImage(00),
                                                                         _grid(00),
                                                                         _isDeletedManually(false)
{
    if (_typeName.isNull() || _typeName.isEmpty())
    {
        _typeName = _name;
    }

    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    setLayout(new QHBoxLayout(this));
    _labelImage = new QLabel(this);

    assert(!_image.isNull());
    assert(_image.width() == CELL_SIZE);
    assert(_image.height() == CELL_SIZE);
    _labelImage->setPixmap(QPixmap::fromImage(_image));
    _labelImage->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    layout()->addWidget(_labelImage);
    layout()->setContentsMargins(-1, -1, -1, -1);
    setContentsMargins(-1, -1, -1, -1);

    _labelImage->setMinimumSize(CELL_SIZE, CELL_SIZE);

    _anim.setDuration(CELL_MOVE_DURATION);
    _anim.setEasingCurve(QEasingCurve::InCubic);
    _anim.setDirection(QAbstractAnimation::Forward);
    connect(&_anim, SIGNAL(finished()),
            this, SLOT(endMoveInTime()), Qt::UniqueConnection);
}

Cell::~Cell()
{
}

void Cell::moveInTime(int x, int y)
{
    moveInTime(QPoint(x, y));
}

void Cell::moveInTime(const QPoint &point)
{
    if (_aboutToDelete)
    {
        return;
    }

    _anim.stop();

    setCanBeClicked(false);

    _anim.setStartValue(pos());
    _anim.setEndValue(point);

    _anim.start();
}

void Cell::endMoveInTime()
{
    if (_aboutToDelete)
    {
        return;
    }

    move(_locationInGrid.x() * CELL_SPACING, _locationInGrid.y() * CELL_SPACING);
    setCanBeClicked(true);
}

const QString &Cell::getImagePath() const
{
    return _imagePath;
}

const QString &Cell::getName() const
{
    return _name;
}

int Cell::getType() const
{
    return _type;
}

int Cell::getAppearanceFrequency() const
{
    return _appearanceFrequency;
}

const QString &Cell::getTypeName() const
{
    return _typeName;
}

int Cell::getScore() const
{
    return _score;
}

void Cell::setGrid(Grid *grid)
{
    assert(_grid == 00 && grid != 00);

    _grid = grid;

    if (_locationInGrid.x() < 0)
    {
        return;
    }

    move(_locationInGrid.x() * CELL_SPACING, _locationInGrid.y() * CELL_SPACING);
}

const Grid *Cell::getGrid() const
{
    return _grid;
}

void Cell::setLocationInGrid(const QPoint &point)
{
    if (_aboutToDelete)
    {
        return;
    }

    assert(point.x() >= 0);
    assert(point.y() >= 0);

    if (_grid != 00)
    {
        if (_locationInGrid.x() < 0)
        {
            move(point.x() * CELL_SPACING, -CELL_SIZE - 20);
        }
    }

    _locationInGrid = point;

    if (_grid != 00)
    {
        moveInTime(_locationInGrid.x() * CELL_SPACING, _locationInGrid.y() * CELL_SPACING);
    }
}

const QPoint &Cell::getLocationInGrid() const
{
    return _locationInGrid;
}

void Cell::setCanBeClicked(bool canBeClicked)
{
    if (_aboutToDelete)
    {
        return;
    }

    _canBeClicked = canBeClicked;

    if (_canBeClicked)
    {
        setCursor(QCursor(Qt::PointingHandCursor));
        if (underMouse())
        {
            _grid->setHoveredCell(this);
        }
    }
    else
    {
        unsetCursor();
    }
}

void Cell::setAboutToDelete()
{
    _aboutToDelete = true;
}

bool Cell::isDeletedManually() const
{
    if (_aboutToDelete)
    {
        assert(false);
    }
    return _isDeletedManually;
}

bool Cell::resolveEffect()
{
    if (_aboutToDelete)
    {
        assert(false);
        return false;
    }

    TEST(_grid != 00);

    Cell *selected = _grid->getSelectedCell();
    if (selected == 00)
    {
        _grid->setSelectedCell(this);
    }
    else
    {
        if (selected == this)
        {
            _grid->setSelectedCell(00);
        }
        else
        {
            if (selected == _grid->getCellUp(*this) ||
                selected == _grid->getCellDown(*this) ||
                selected == _grid->getCellRight(*this) ||
                selected == _grid->getCellLeft(*this))
            {
                _grid->setSelectedCell(00);
                _grid->setHoveredCell(00);
                _grid->swapCells(*this, *selected);
            }
            else
            {
                _grid->setSelectedCell(this);
            }
        }
    }

    return true;
}

Cell *Cell::clone() const
{
    if (_aboutToDelete)
    {
        assert(false);
        return 00;
    }

    return new Cell(_score, _imagePath, _name, _type, _appearanceFrequency, _typeName);
}

void Cell::mousePressEvent(QMouseEvent *event)
{
    if (_aboutToDelete)
    {
        return;
    }

    assert(_grid != 00);

    if (event->button() == Qt::RightButton)
    {
        _grid->setSelectedCell(00);
    }
    else if (_canBeClicked && _grid != 00 && event->button() == Qt::LeftButton)
    {
        _grid->mousePressedOnCell(*this);
    }

    QWidget::mousePressEvent(event);
}

void Cell::enterEvent(QEnterEvent *event)
{
    if (_aboutToDelete)
    {
        return;
    }

    assert(_grid != 00);

    if (_canBeClicked)
    {
        _grid->setHoveredCell(this);
    }

    QWidget::enterEvent(event);
}

void Cell::leaveEvent(QEvent *event)
{
    if (_aboutToDelete)
    {
        return;
    }

    assert(_grid != 00);

    if (_canBeClicked)
    {
        _grid->setHoveredCell(00);
    }

    QWidget::leaveEvent(event);
}
