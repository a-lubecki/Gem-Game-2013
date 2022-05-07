// Copyright Aurelien Lubecki 2012

#include "Grid.h"
#include "Cell.h"
#include "Play.h"

Grid::Grid(Play &play, const QSize &size, const QList<const Cell *> &initialCells, QWidget *parent)
    : QWidget(parent),
      _play(&play),
      _gridSize(size),
      _grid(),
      _initialCells(),
      _selectedCell(00),
      _widgetSelectedCell(00),
      _hoveredCell(00),
      _widgetHoveredCell(00),
      _swappedCell1(00),
      _swappedCell2(00),
      _cellsToInit(),
      _timerInitCells(),
      _timerResolving()
{
    assert(size.width() > 0);
    assert(size.height() > 0);
    assert(initialCells.size() > 0);

    setContentsMargins(-1, -1, -1, -1);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    setMinimumSize((CELL_SPACING + 1) * _gridSize.width(), (CELL_SPACING + 1) * _gridSize.height());

    foreach (const Cell *cell, initialCells)
    {
        assert(cell != 00);
        _initialCells.insert(cell->clone(), cell->getAppearanceFrequency());
    }

    QVector<Cell *> horizontalCells;
    horizontalCells.fill(00, _gridSize.width());
    _grid.fill(horizontalCells, _gridSize.height());

    show();

    _widgetSelectedCell = new QWidget(this);
    _widgetSelectedCell->setAttribute(Qt::WA_TransparentForMouseEvents);
    _widgetSelectedCell->hide();
    _widgetSelectedCell->resize(CELL_SPACING, CELL_SPACING);
    _widgetSelectedCell->setStyleSheet(
        "QWidget {"
        "background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.7, fx:0.5, fy:0.5,"
        "stop:0 rgba(0, 0, 0, 0),"
        "stop:0.3 rgba(0, 0, 0, 0),"
        "stop:1 rgba(255, 255, 255, 100));"
        "border:2px solid rgb(255, 255, 255);"
        "border-radius:5px;"
        "}");

    _widgetHoveredCell = new QWidget(this);
    _widgetHoveredCell->setAttribute(Qt::WA_TransparentForMouseEvents);
    _widgetHoveredCell->hide();
    _widgetHoveredCell->resize(CELL_SPACING + 6, CELL_SPACING + 6);
    _widgetHoveredCell->setStyleSheet(
        "QWidget {"
        "background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.7, fx:0.5, fy:0.5,"
        "stop:0 rgba(0, 0, 0, 0),"
        "stop:0.3 rgba(0, 0, 0, 0),"
        "stop:1 rgba(220, 220, 220, 100));"
        "border:2px solid rgb(220, 220, 220);"
        "border-radius:5px;"
        "}");

    _timerInitCells.setSingleShot(false);
    _timerInitCells.setInterval(10);
    connect(&_timerInitCells, SIGNAL(timeout()),
            this, SLOT(initOneCell()), Qt::UniqueConnection);

    _timerResolving.setSingleShot(false);
    _timerResolving.setInterval(CELL_MOVE_DURATION + 200);
    connect(&_timerResolving, SIGNAL(timeout()),
            this, SLOT(resolveOneSituation()), Qt::UniqueConnection);
}

Grid::~Grid()
{
}

const QSize &Grid::getGridSize() const
{
    return _gridSize;
}

void Grid::initGrid()
{
    _timerInitCells.stop();
    _timerResolving.stop();

    activateCellsClic(false);

    clearGrid();

    setSelectedCell(00);
    setHoveredCell(00);

    _swappedCell1 = 00;
    _swappedCell2 = 00;

    // start to fill grid
    for (int y = _gridSize.height() - 1; y >= 0; y--)
    {
        for (int x = 0; x < _gridSize.width(); x++)
        {
            assert(_grid[y][x] == 00);

            _cellsToInit.append(QPoint(x, y));
        }
    }

    _timerInitCells.start();
}

void Grid::initOneCell()
{
    if (_cellsToInit.size() <= 0)
    {
        _timerInitCells.stop();
        emit isReady();
        activateCellsClic(true);
        return;
    }

    const QPoint &loc = _cellsToInit.takeFirst();

    // add a new cell
    QSet<int> forbiddenTypes;
    Cell *down = getCell(loc.x(), loc.y() + 1);
    if (down != 00)
    {
        forbiddenTypes.insert(down->getType());
    }
    Cell *right = getCell(loc.x() - 1, loc.y());
    if (right != 00)
    {
        forbiddenTypes.insert(right->getType());
    }

    const Cell *initial = getRandomInitialCell(forbiddenTypes);
    if (initial == 00)
    {
        assert(false);
        initial = getRandomInitialCell();
    }

    Cell *cell = initial->clone();
    cell->setParent(this);
    cell->setGrid(this);
    _grid[loc.y()][loc.x()] = cell;
    cell->setLocationInGrid(loc);
    cell->show();
}

bool Grid::moveCell(Cell &cell, const QPoint &nextLocation)
{
    const QPoint &currentLocation = cell.getLocationInGrid();
    TEST(getCell(currentLocation) != 00);

    if (_grid[currentLocation.y()][currentLocation.x()] == 00 ||
        _grid[nextLocation.y()][nextLocation.x()] != 00)
    {
        return false;
    }

    _grid[nextLocation.y()][nextLocation.x()] = &cell;
    _grid[currentLocation.y()][currentLocation.x()] = 00;

    cell.setLocationInGrid(nextLocation);

    return true;
}

void Grid::getNearbyCells(QSet<Cell *> &nearbyCells, Cell &cellRef, bool searchHorizontally) const
{
    if (nearbyCells.contains(&cellRef))
    {
        return;
    }
    nearbyCells.insert(&cellRef);

    QVector<Cell *> cells(2);
    cells.fill(00);
    if (searchHorizontally)
    {
        cells[0] = getCellRight(cellRef);
        cells[1] = getCellLeft(cellRef);
    }
    else
    {
        cells[0] = getCellUp(cellRef);
        cells[1] = getCellDown(cellRef);
    }

    foreach (Cell *c, cells)
        if (c != 00 && c->getType() == cellRef.getType())
        {
            getNearbyCells(nearbyCells, *c, searchHorizontally);
        }
}

void Grid::getAllNearbyCellsToDelete(QSet<Cell *> &cells)
{
    cells.clear();

    for (int y = 0; y < _gridSize.height(); y++)
    {
        for (int x = 0; x < _gridSize.width(); x++)
        {
            Cell *cell = _grid[y][x];
            if (cell != 00 && cell->getType() >= 0)
            {
                QSet<Cell *> nearbyCellsH;
                getNearbyCells(nearbyCellsH, *cell, true);
                if (nearbyCellsH.size() >= 3)
                {
                    cells.unite(nearbyCellsH);
                }

                QSet<Cell *> nearbyCellsV;
                getNearbyCells(nearbyCellsV, *cell, false);
                if (nearbyCellsV.size() >= 3)
                {
                    cells.unite(nearbyCellsV);
                }
            }
        }
    }
}

Cell *Grid::getNextUpperCell(const QPoint &currentLocation) const
{
    TEST(getCell(currentLocation) == 00);

    Cell *upCell = 00;
    int x = currentLocation.x();
    int y = currentLocation.y() - 1;

    while (y >= 0)
    {
        upCell = getCell(x, y);
        if (upCell != 00)
        {
            assert(upCell->getLocationInGrid() == QPoint(x, y));
            return upCell;
        }
        y--;
    }

    return 00;
}

const Cell *Grid::getRandomInitialCell(const QSet<int> &forbiddenTypes) const
{
    TEST(_initialCells.size() > 0);
    TEST(forbiddenTypes.size() < _initialCells.size());

    const QList<int> initialRandValues = _initialCells.values();
    int total = 0;
    foreach (int n, initialRandValues)
    {
        total += n;
    }

    // chose a cell type
    const Cell *chosenCell = 00;
    do
    {
        int chosen = QRandomGenerator::global()->bounded(total);
        int totalNb = 0;

        int i = 0;
        foreach (int n, initialRandValues)
        {
            totalNb += n;
            if (totalNb > chosen)
            {
                chosenCell = (_initialCells.begin() + i).key();
                break;
            }
            i++;
        }

        assert(chosenCell != 00);
    } while (forbiddenTypes.contains(chosenCell->getType()));

    return chosenCell;
}

void Grid::resolveGrid()
{
    _timerResolving.stop();

    activateCellsClic(false);

    _play->pauseTime();

    _timerResolving.start();
    resolveOneSituation();
}

void Grid::resolveOneSituation()
{
    QSet<Cell *> cellsToDelete;
    getAllNearbyCellsToDelete(cellsToDelete);

    bool hasBlankCells = (cellsToDelete.size() > 0);

    deleteCells(cellsToDelete);

    if (!hasBlankCells)
    {
        for (int x = 0; x < _gridSize.width(); x++)
        {
            for (int y = _gridSize.height() - 1; y >= 0; y--)
            {
                Cell *cell = _grid[y][x];
                if (cell == 00)
                {
                    hasBlankCells = true;
                    break;
                }
            }
            if (hasBlankCells)
            {
                break;
            }
        }
    }

    if (!hasBlankCells)
    {
        _timerResolving.stop();

        QTimer::singleShot(500, this, SLOT(endResolving()));

        return;
    }

    // gravity :
    for (int x = 0; x < _gridSize.width(); x++)
    {
        for (int y = _gridSize.height() - 1; y >= 0; y--)
        {
            Cell *cell = _grid[y][x];
            if (cell == 00)
            {
                QPoint loc(x, y);
                Cell *upperCell = getNextUpperCell(loc);
                if (upperCell != 00)
                {
                    moveCell(*upperCell, loc);
                }
                else
                {
                    break;
                }
            }
        }
    }

    // fill the blanks by adding new cells :
    for (int x = 0; x < _gridSize.width(); x++)
    {
        for (int y = 0; y < _gridSize.height(); y++)
        {
            if (_grid[y][x] == 00)
            {
                // add a new cell
                Cell *cell = getRandomInitialCell()->clone();
                cell->setParent(this);
                cell->setGrid(this);
                _grid[y][x] = cell;
                cell->setLocationInGrid(QPoint(x, y));
                cell->show();
            }
            else
            {
                break;
            }
        }
    }
}

void Grid::endResolving()
{
    _play->resumeTime();

    activateCellsClic(true);
}

void Grid::clearGrid()
{
    _timerInitCells.stop();
    _timerResolving.stop();

    setSelectedCell(00);
    setHoveredCell(00);
    _swappedCell1 = 00;
    _swappedCell2 = 00;

    for (int y = 0; y < _gridSize.height(); y++)
    {
        for (int x = 0; x < _gridSize.width(); x++)
        {
            Cell *cell = _grid[y][x];
            if (cell != 00)
            {
                cell->setAboutToDelete();
                _grid[y][x] = 00;
                delete cell;
            }
        }
    }
}

Cell *Grid::getCell(const QPoint &loc) const
{
    return getCell(loc.x(), loc.y());
}

Cell *Grid::getCell(int x, int y) const
{
    if (x < 0 || x >= _gridSize.width() ||
        y < 0 || y >= _gridSize.height())
    {
        return 00;
    }

    Cell *cell = _grid[y][x];
    if (cell != 00)
    {
        TEST(cell->getGrid() == this);
        TEST(cell->getLocationInGrid() == QPoint(x, y));
    }
    return cell;
}

Cell *Grid::getCellUp(const Cell &cell) const
{
    QPoint loc = cell.getLocationInGrid();

    return getCell(loc.x(), loc.y() - 1);
}

Cell *Grid::getCellDown(const Cell &cell) const
{
    QPoint loc = cell.getLocationInGrid();

    return getCell(loc.x(), loc.y() + 1);
}

Cell *Grid::getCellLeft(const Cell &cell) const
{
    QPoint loc = cell.getLocationInGrid();

    return getCell(loc.x() - 1, loc.y());
}

Cell *Grid::getCellRight(const Cell &cell) const
{
    QPoint loc = cell.getLocationInGrid();

    return getCell(loc.x() + 1, loc.y());
}

void Grid::mousePressedOnCell(Cell &cell)
{
    assert(cell.resolveEffect());
}

void Grid::setSelectedCell(Cell *cell)
{
    _selectedCell = cell;

    if (_selectedCell != 00)
    {
        _selectedCell->raise();
        _widgetSelectedCell->move(_selectedCell->getLocationInGrid() * CELL_SPACING +
                                  QPoint(_selectedCell->width() / 2., _selectedCell->height() / 2.) -
                                  QPoint(_widgetSelectedCell->width() / 2., _widgetSelectedCell->height() / 2.));
        _widgetSelectedCell->show();
        _widgetSelectedCell->raise();
    }
    else
    {
        _widgetSelectedCell->hide();
    }
}

Cell *Grid::getSelectedCell() const
{
    return _selectedCell;
}

void Grid::setHoveredCell(Cell *cell)
{
    _hoveredCell = cell;

    if (_hoveredCell != 00)
    {
        _hoveredCell->raise();
        _widgetHoveredCell->move(_hoveredCell->getLocationInGrid() * CELL_SPACING +
                                 QPoint(_hoveredCell->width() / 2., _hoveredCell->height() / 2.) -
                                 QPoint(_widgetHoveredCell->width() / 2., _widgetHoveredCell->height() / 2.));
        _widgetHoveredCell->show();
        _widgetHoveredCell->raise();
    }
    else
    {
        _widgetHoveredCell->hide();
    }
}

bool Grid::swapCells(Cell &cell1, Cell &cell2)
{
    activateCellsClic(false);

    TEST(cell1.getGrid() == this);
    TEST(getCell(cell1.getLocationInGrid()) != 00);

    TEST(cell2.getGrid() == this);
    TEST(getCell(cell2.getLocationInGrid()) != 00);

    QPoint loc1 = cell1.getLocationInGrid();
    QPoint loc2 = cell2.getLocationInGrid();
    TEST(loc1 != loc2);

    _grid[loc1.y()][loc1.x()] = &cell2;
    cell2.setLocationInGrid(loc1);
    _grid[loc2.y()][loc2.x()] = &cell1;
    cell1.setLocationInGrid(loc2);

    _swappedCell1 = &cell1;
    _swappedCell2 = &cell2;

    QTimer::singleShot(CELL_MOVE_DURATION, this, SLOT(endSwapCells()));

    return true;
}

void Grid::endSwapCells()
{
    if (_swappedCell1 == 00)
    {
        return;
    }
    if (_swappedCell2 == 00)
    {
        return;
    }

    QPoint loc1 = _swappedCell1->getLocationInGrid();
    QPoint loc2 = _swappedCell2->getLocationInGrid();

    QSet<Cell *> cells;
    getAllNearbyCellsToDelete(cells);
    bool hasBlankCells = (cells.size() > 0);

    /*
        for(int y=0;y<_gridSize.height();y++)
        {
            QString aaa("");
            for(int x=0;x<_gridSize.width();x++)
            {
                Cell* cell = _grid[y][x];
                if(cell != 00)
                {
                    aaa.append("["%QString::number(cell->getType())%"]");
                }
                else
                {
                    aaa.append("[X]");
                }
            }
            qDebug() << aaa;
        }*/

    if (hasBlankCells)
    {
        resolveGrid();
    }
    else
    {
        // revert :
        _grid[loc1.y()][loc1.x()] = _swappedCell2;
        _swappedCell2->setLocationInGrid(loc1);
        _grid[loc2.y()][loc2.x()] = _swappedCell1;
        _swappedCell1->setLocationInGrid(loc2);

        activateCellsClic(true);
    }

    _swappedCell1 = 00;
    _swappedCell2 = 00;
}

void Grid::deleteCells(const QSet<Cell *> &cellsToDelete)
{
    if (cellsToDelete.size() <= 0)
    {
        return;
    }

    _play->scoreDeletedCells(cellsToDelete);

    foreach (Cell *cell, cellsToDelete)
    {
        assert(cell != 00);

        const QPoint &nbcLoc = cell->getLocationInGrid();
        assert(getCell(nbcLoc) != 00);

        if (_selectedCell == cell)
        {
            setSelectedCell(00);
        }
        if (_hoveredCell == cell)
        {
            setHoveredCell(00);
        }
        if (_swappedCell1 == cell)
        {
            _swappedCell1 = 00;
        }
        if (_swappedCell2 == cell)
        {
            _swappedCell2 = 00;
        }
        cell->setAboutToDelete();
        _grid[nbcLoc.y()][nbcLoc.x()] = 00;
        cell->deleteLater();
    }

    if (cellsToDelete.size() > 3)
    {
        _play->setMultiplier(_play->getMultiplier() + 1);
    }
}

void Grid::deleteOneCell(Cell &cell)
{
    QSet<Cell *> set;
    set.insert(&cell);
    deleteCells(set);
}

void Grid::addTimePercentageInPlay(int timePercentage)
{
    assert(_play != 00);

    _play->addTimePercentage(timePercentage);
}

void Grid::addMultiplierInPlay(int nbMultiplier)
{
    assert(_play != 00);

    _play->setMultiplier(_play->getMultiplier() + nbMultiplier);
}

void Grid::activateCellsClic(bool canClick) const
{
    for (int y = 0; y < _gridSize.height(); y++)
    {
        for (int x = 0; x < _gridSize.width(); x++)
        {
            Cell *cell = _grid[y][x];
            if (cell != 00)
            {
                cell->setCanBeClicked(canClick);
            }
        }
    }
}
