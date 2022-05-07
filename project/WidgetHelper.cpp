// Copyright Aurelien Lubecki 2012

#include "WidgetHelper.h"
#include "ui_WidgetHelper.h"

WidgetHelper::WidgetHelper(QWidget *parent) : QFrame(parent),
                                              ui(new Ui::WidgetHelper)
{
    ui->setupUi(this);

    enableInterface(false);
}

WidgetHelper::~WidgetHelper()
{
    delete ui;
}

#define COLOR_STRING(text, color) "<span style='color:rgb(" % QString::number(color.red()) % "," % QString::number(color.green()) % "," % QString::number(color.blue()) % ");font-weight:bold;'>" % text % "</span>"

void WidgetHelper::init()
{
    connect(ui->buttonReturnHelp, SIGNAL(pressed()),
            this, SLOT(stopHelp()), Qt::UniqueConnection);

    QString str_Gemme(COLOR_STRING("Gemme", QColor(255, 200, 50)));
    QString str_Gemmes(COLOR_STRING("Gemmes", QColor(255, 200, 50)));

    QString str_temps(COLOR_STRING("temps", QColor(200, 200, 200)));
    QString str_Temps(COLOR_STRING("Temps", QColor(200, 200, 200)));

    QString str_grille(COLOR_STRING("grille", QColor(255, 150, 150)));

    QString str_Item(COLOR_STRING("Item", QColor(150, 255, 150)));
    QString str_Items(COLOR_STRING("Items", QColor(150, 255, 150)));

    QString str_points(COLOR_STRING("points", QColor(255, 255, 150)));

    QString str_Trophees(COLOR_STRING("Trophées", QColor(255, 255, 255)));

    _helpList.resize(12);

    int help = 0;
    _helpList[help]._title = "But du jeu";
    _helpList[help]._imageName = "purpose";
    _helpList[help]._explanation = "Le jeu consiste à récupérer des " % str_Gemmes % " dans une " % str_grille % " en les alignant. Un objectif est visible dès le début. Il peut être par exemple, de récupérer un nombre de " % str_Gemmes % " d'un type particulier. Une fois l'objectif atteint, vous parvenez au niveau suivant et la " % str_grille % " change ainsi que l'objectif. Il faut continuer ainsi jusqu'à atteidre le niveau final. Mais attention, le " % str_temps % " est limité pour atteindre l'objectif !";

    help++;
    _helpList[help]._title = "La grille";
    _helpList[help]._imageName = "grid";
    _helpList[help]._explanation = "Une fois la " % str_grille % " remplie, vous pouvez sélectionner deux " % str_Gemmes % " adjacentes pour intervertir leur position. Si trois " % str_Gemmes % " ou plus sont alignées, elle disparaissent et vous récupérez des " % str_points % " pour votre score. Les " % str_Gemmes % " situées au dessus ainsi que des nouvelles, tombent ensuite pour combler le vide et il peut s'ensuivre une réaction en chaîne selon la nouvelle configuration de la " % str_grille % ". En revanche, si aucune " % str_Gemme % " n'a disparu, les deux " % str_Gemmes % " échangées initialement reprennent leur place initiale.";

    help++;
    _helpList[help]._title = "Récupérer des gemmes";
    _helpList[help]._imageName = "techniques";
    _helpList[help]._explanation = "Les techniques pour échanger les " % str_Gemmes % " sont multiples. Vous aurez parfois l'occasion de récupérer plus que trois " % str_Gemmes % " sur une ligne ainsi que plusieurs lignes de " % str_Gemmes % " adjacentes. Vous pouvez même utiliser un " % str_Item % " pour faire descendre les " % str_Gemmes % " situées au dessus et ainsi les récupérer.";

    help++;
    _helpList[help]._title = "Les types gemmes";
    _helpList[help]._imageName = "rarity";
    _helpList[help]._explanation = "Chaque " % str_Gemme % " vous rapportera un certain nombre de " % str_points % " selon leur rareté. Ainsi, l'Ambre, rapportant peu de " % str_points % " sera simple à récupérer. En revanche les " % str_Gemmes % " de Diamant seront plus compliquées à aligner car elles seront dispersées.";

    help++;
    _helpList[help]._title = "Le multiplicateur";
    _helpList[help]._imageName = "multiplier";
    _helpList[help]._explanation = "Le mutiplicateur de score est disponible tout le temps et est initialisé à 1 au début de chaque niveau. A chaque fois que vous récupérez des " % str_Gemmes % ", les " % str_points % " obtenus sont multipliés par le mutiplicateur courant. Jusqu'à un maximum de 10, le multiplicateur augmente de 1 à chaque fois que vous récupérez plus de trois " % str_Gemmes % " en un seul coup. En contrepartie, il redescend de 1 toutes les 5 secondes. Il existe aussi des " % str_Items % " pour augmenter le multiplicateur.";

    help++;
    _helpList[help]._title = "Les Items";
    _helpList[help]._imageName = "items";
    _helpList[help]._explanation = "Les " % str_Items % " sont des objets que vous pouvez activer dans la " % str_grille % " en les sélectionnant. Une fois que leur effet a été appliqué, ils disparaissent. Contrairement aux " % str_Gemmes % ", ils ne vous rapportent pas de point mais à la place, ils font baisser votre score. Néanmoins, la plupart du temps, les " % str_Items % " vous seront trés utiles. L'" % str_Item % " de Mutiplicateur augmente de 1 ou 2 votre multiplicateur. L'" % str_Item % " de " % str_Temps % " vous permet de remplir la barre de " % str_temps % " pour repousser l'échéance.";

    help++;
    _helpList[help]._title = "L'Item Dynamite";
    _helpList[help]._imageName = "dynamite";
    _helpList[help]._explanation = "L'" % str_Item % " Dynamite détruit toutes les " % str_Gemmes % " situées autour de lui.";

    help++;
    _helpList[help]._title = "L'Item Laser";
    _helpList[help]._imageName = "laser";
    _helpList[help]._explanation = "L'" % str_Item % " Laser détruit des " % str_Gemmes % " verticalement et horizontalement.";

    help++;
    _helpList[help]._title = "L'Item Ultrasons";
    _helpList[help]._imageName = "ultrasons";
    _helpList[help]._explanation = "L'" % str_Item % " Ultrasons détruit toutes les " % str_Gemmes % " d'un seul type choisi alétoirement.";

    help++;
    _helpList[help]._title = "La gestion du temps";
    _helpList[help]._imageName = "time";
    _helpList[help]._explanation = "Comme le " % str_temps % " est compté pour atteindre l'objectif indiqué, le seul moyen d'en gagner est d'utiliser des " % str_Items % " de " % str_Temps % ". Il est préférable d'utiliser ces " % str_Items % " avec parcimonie : si vous souhaitez utiliser l'" % str_Item % " \"Temps +50%\", il vaut mieux continuer à aligner les " % str_Gemmes % " tant que la barre de " % str_temps % " n'est pas jaune.";

    help++;
    _helpList[help]._title = "Les gemmes pures";
    _helpList[help]._imageName = "pures";
    _helpList[help]._explanation = "Les " % str_Gemmes % " pures sont brillantes, plus rares que les " % str_Gemmes % " normales et n'ont pas d'autres fonction que de rapporter plus de " % str_points % ". Cependant, certains objectifs vous demanderont de collecter seulement des " % str_Gemmes % " pure.";

    help++;
    _helpList[help]._title = "Les Trophées";
    _helpList[help]._imageName = "trophies";
    _helpList[help]._explanation = "Les " % str_Trophees % " sont acessibles à partir du menu principal. Ils vous sont attribués lorsque vous réussissez des exploits. Certains peuvent être acquis en quelques parties seulement. D'autres par contre, mettrons à rude épreuve votre âme de joueur invétéré.";

    assert(help == _helpList.size() - 1);

    QStandardItem *parentItem = _model.invisibleRootItem();
    for (int i = 0; i < _helpList.size(); ++i)
    {
        QStandardItem *item = new QStandardItem(_helpList[i]._title);
        parentItem->appendRow(item);
    }
    ui->listViewHelp->setModel(&_model);

    ui->listViewHelp->setDragDropMode(QAbstractItemView::NoDragDrop);
    ui->listViewHelp->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listViewHelp->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->listViewHelp->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(ui->listViewHelp, SIGNAL(pressed(QModelIndex)),
            this, SLOT(helpSelected(QModelIndex)), Qt::UniqueConnection);
}

void WidgetHelper::enableInterface(bool enable)
{
    ui->buttonReturnHelp->setEnabled(enable);
}

void WidgetHelper::setVisible(bool visible)
{
    QFrame::setVisible(visible);

    if (isVisible())
    {
        ui->listViewHelp->setCurrentIndex(_model.index(0, 0));
        selectHelp(0);
    }
}

void WidgetHelper::helpSelected(QModelIndex index)
{
    selectHelp(index.row());
}

void WidgetHelper::selectHelp(int pos)
{
    assert(pos >= 0 && pos < _helpList.size());

    ui->labelHelpTitle->setText(_helpList[pos]._title);
    ui->labelHelpImage->setPixmap(QPixmap(PATH_RESOURCES_HELP % _helpList[pos]._imageName % ".png"));
    ui->labelHelpExplanation->setText(_helpList[pos]._explanation);
}

void WidgetHelper::stopHelp()
{
    enableInterface(false);

    emit closed();
}
