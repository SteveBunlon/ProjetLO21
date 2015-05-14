#include "classes/Programmation.h"
#include "classes/Tache.h"
#include "classes/Projet.h"

ProgrammationManager& ProgrammationManager::Instance()
{
    static ProgrammationManager Pmanager;
    return Pmanager;
}
