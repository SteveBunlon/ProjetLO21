#include "classes/Projet.h"
#include "classes/Tache.h"
#include "classes/Programmation.h"



ProjetManager& ProjetManager::Instance()
{
    static ProjetManager Pmanager;
    return Pmanager;
}

ProjetManager::~ProjetManager()
{
    for(Projet* projet = this->projets[0]; projet < this->projets[0+this->nb]; ++projet)
    {
        delete projet;
    }
    delete[] this->projets;
}
