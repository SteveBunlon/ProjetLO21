#include "edittache.h"
#include "ui_edittache.h"

EditTache::EditTache(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditTache)
{
    ui->setupUi(this);
}

EditTache::~EditTache()
{
    delete ui;
}

void EditTache::loadProjects()
{
    ProjetManager& manager = ProjetManager::Instance();
    unsigned int nbProj = manager.getNb();

    QTreeWidget * tree = ui->treeWidget;


    for(int i = 0; i < nbProj; i++)
    {
        QTreeWidgetItem * projet = new QTreeWidgetItem();

        Projet& proj = manager.getProjet(i);
        unsigned int nbTaches = proj.getNb();
        projet->setText(0, QString::fromStdString(proj.getTitre()));

        for(int i=0; i < nbTaches; i++)
        {
            QTreeWidgetItem * tache = new QTreeWidgetItem();
            Tache& t = proj.getTache(i);
            tache->setText(0, QString::fromStdString(t.getTitre()));
            projet->addChild(tache);
        }
        tree->addTopLevelItem(projet);
    }

}
