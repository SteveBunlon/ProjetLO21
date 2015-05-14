#include "classes/Tache.h"
#include "classes/Programmation.h"
#include "classes/Projet.h"

Tache::~Tache()
{
    delete[] antecedentes;
}

Tache& TacheManager::getTache(const string& titre)
{
    for(Tache* tache = this->taches[0];tache < this->taches[0+this->nb]; ++tache)
    {
        if(tache->getTitre() == titre)
            return *tache;
    }
    throw CalendarException("Tache existante");
}

void TacheManager::addTache(Tache* t)
{
    if(this->nb == this->max)
    {
        Tache** newTache = new Tache*[this->max+10];
        for(int i = 0; i<this->nb; i++)
        {
            newTache[i] = this->taches[i];
            this->taches[i] = NULL;
        }
        Tache** toDelete = this->taches;
        this->taches = newTache;
        delete[] toDelete;
        this->max += 10;
    }
    this->taches[this->nb] = t;
    this->nb++;
}

bool TacheManager::existTache(const string& titre)
{
    for(Tache* tache = this->taches[0]; tache < this->taches[0+this->nb]; ++tache)
        if(tache->getTitre() == titre) return true;
    return false;
}

void TacheManager::createTacheUnitaire(const string& t, const Date& dispo, const Date& echeance, const Duree& duree, const bool preemptive)
{
    if(existTache(t) == true) throw CalendarException("Tache deja existante");

    Tache* tacheU = new TacheUnitaire(t, dispo, echeance, duree, preemptive);
    this->addTache(tacheU);
}

void TacheManager::createTacheUnitaire(const string& t, const Date& dispo, const Date& echeance, const Duree& duree, const bool preemptive, Projet& proj)
{
    if(existTache(t) == true) throw CalendarException("Tache deja existante");

    Tache* tacheU = new TacheUnitaire(t, dispo, echeance, proj, duree, preemptive);
    this->addTache(tacheU);
}

TacheManager::~TacheManager()
{
    for(Tache* tache = this->taches[0]; tache < this->taches[0+this->nb]; ++tache)
    {
        delete tache;
    }
    delete[] this->taches;
}

/*void TacheManager::operator=(const TacheManager& t)
{
    this->nb = t.nb;
    this->nbMax = t.nbMax;
    this->taches = new Tache*[this->nbMax];
    for(int i = 0; i < this->n; ++i)
    {
        this->addItem(t.taches[i]);
        this->taches[i] = new Tache(t.taches[i]->getID(), t.taches[i]->getTitre(), t.taches[i]->getDuree(), t.taches[i]->getDisopnibilite(), t.taches[i]->getEcheance());
    }
}*/
