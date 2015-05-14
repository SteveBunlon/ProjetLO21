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
    // ---- charge les projets dans le tree
    ProjetManager& Pmanager = ProjetManager::Instance();
    TacheManager& Tmanager = TacheManager::Instance();
    unsigned int nbProj = Pmanager.getNb();
    unsigned int nbTaches = Tmanager.getNb();

    QTreeWidget * tree = ui->treeWidget;
    QListWidget * list = ui->listWidget;

    for(int i = 0; i < nbProj; i++)
    {
        QTreeWidgetItem * projet = new QTreeWidgetItem();

        Projet& proj = Pmanager.getProjet(i);
        unsigned int nbTachesProj = proj.getNb();
        projet->setText(0, QString::fromStdString(proj.getTitre()));

        for(i=0; i < nbTachesProj; i++)
        {
            QTreeWidgetItem * tache = new QTreeWidgetItem();
            Tache& t = proj.getTache(i);
            tache->setText(0, QString::fromStdString(t.getTitre()));
            projet->addChild(tache);
            //si tache composite alors ajouter toutes les sous tache en tant que child


            //for(i = 0; i < )
            //tache->addChild(soustache);
        }
        tree->addTopLevelItem(projet);
    }
    // ----

    // ---- charge la liste des taches qui n'ont pas de projet assigné
    for(i = 0; i < nbTaches; i++)
    {
        if(Tmanager.taches[i]->getProjetAssocie() == NULL)
        {
            QListWidgetItem * currentTache = new QListWidgetItem();
            currentTache->setText(QString::fromStdString(proj.getTitre()));
        }
    }

}
