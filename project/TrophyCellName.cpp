// Copyright Aurelien Lubecki 2012

#include "TrophyCellName.h"
#include "Cell.h"
#include "LevelResult.h"
#include "WidgetTrophies.h"

TrophyCellName::TrophyCellName(const QVector<int> &objectiveValues, const Cell &cell)
    : Trophy("", objectiveValues),
      _cell(cell.clone())
{
    QString name("Collecteur : ");
    if (cell.getType() < 0)
    {
        name = "Utilisateur : ";
    }

    setName(name % _cell->getName());
}

TrophyCellName::~TrophyCellName()
{
    if (_cell != 00)
    {
        delete _cell;
    }
}

void TrophyCellName::addLevelResult(const LevelResult &result)
{
    addValue(result.getNbCells(*_cell));
}

QString TrophyCellName::getExplanationText(TrophyImportance importance) const
{
    int nb = getObjectiveValue(importance);
    if (_cell->getType() < 0)
    {
        return "Utiliser un total de " % QString::number(nb) % " fois l'Item nommé \"" % _cell->getName() % "\".";
    }

    QString plural("");
    if (nb != 1)
    {
        plural = "s";
    }
    return "Obtenir un total de " % QString::number(nb) % " Gemme" % plural % " nommée" % plural % " \"" % _cell->getName() % "\".";
}
