#include "calendar.h"

void TacheManager::ajouterTache(const string& id, const string& t, const Duree& dur, const Date& dispo, const Date& deadline)
{
    if(nb != nbMax)
    {
        Tache tache(id, t, dur, dispo, deadline);
    }
}

const Tache& TacheManager::getTache(const string& id)
{
    int i;
    for(i=0;i<this->nb;i++)
        if(this->taches[i]->getID() == id)
            return *this->taches[i];
    return 0;
}

//correction professeur
Tache& TacheManager::getTache(const string& id)
{
    for(Tache* tache = this->taches[0];tache < this->taches[0+this->nb]; ++tache)
    {
        if(tache->getID() == id)
            return *tache;
    }
    throw CalendarException("Tache existante");
}

//correction du prof
void TacheManager::ajouterTache(const string& id, const string& t, const Duree& dur, const Date& dispo, const Date& deadline)
{
    for(Tache* tache = this->taches[0]; tache < this->taches[0+this->nb]; ++tache)
        if(tache->getId() == id) throw CalendarException("Tache deja existante");

    Tache* tache = new Tache(id, t, dur, dispo, deadline);
    this->addItem(tache);
}

//correction du prof
void TacheManager::addItem(tache* t)
{
    if(this->nb == this->nbMax)
    {
        Tache** newTache = new tache*[this->nbMax+10];
        for(int i = 0; i<this->nb; i++)
        {
            newTache[i] = this->taches[i];
            this->taches[i] = NULL;
        }
        tache** toDelete = this->taches;
        delete[] toDelete;
        this->taches = newTache;
        this->nbMax += 10;
    }
    this->taches[this->nb] = t;
    this->nb++;
}

Tachemanager::~TacheManager()
{
    for(Tache* tache = this->taches[0]; tache < this->taches[0+this->nb]; ++tache)
    {
        delete tache;
    }
    delete[] this->taches;
}

void TacheManager::operator=(const TacheManager& t)
{
    this->nb = t.nb;
    this->nbMax = t.nbMax;
    this->taches = new Tache*[this->nbMax];
    for(int i = 0; i < this->nb, ++i)
    {
        this->addItem(t.taches[i]);
        this->taches[i] = new Tache(t.taches[i]->getID(), t.taches[i]->getTitre(), t.taches[i]->getDuree(), t.taches[i]->getDisopnibilite(), t.taches[i]->getEcheance());
    }
}
