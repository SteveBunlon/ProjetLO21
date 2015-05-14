#include "classes/Tache.h"
#include "classes/Programmation.h"
#include "classes/Projet.h"

Tache::~Tache()
{
    delete[] antecedentes;
}
