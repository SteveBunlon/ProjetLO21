#include "classes/Programmation.h"
#include "classes/Tache.h"
#include "classes/Projet.h"

ProjetManager& ProjetManager::Instance()
{
    static ProjetManager Pmanager;
    return Pmanager;
}
