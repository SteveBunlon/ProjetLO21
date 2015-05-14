#include "classes/Projet.h"
#include "classes/Tache.h"
#include "classes/Programmation.h"



ProjetManager& ProjetManager::Instance()
{
    static ProjetManager Pmanager;
    return Pmanager;
}
