#ifndef PROJET_H
#define PROJET_H

#include <iostream>
#include <string>
#include "timing.h"

using namespace TIME;
using namespace std;

class Programmation;
class Tache;

class Projet{
private:
    Tache** taches;
    Duree dispo;        //date de début
    Duree echeance;     //échéance de la tâche la plus tardive
public:
    Projet(Duree d, Duree e): dispo(d), echeance(e) {taches = new Tache*[5];}
    const Duree& getDispo() const { return dispo; }
    const Duree& getEcheance() const { return echeance; }
};

class ProjetManager {
private:
    Projet** projets;
    unsigned int nb;
    unsigned int max;
    static ProjetManager Pmanager;

    ProjetManager():nb(0), max(10) { projets = new Projet*[10]; }
    ~ProjetManager() { delete[] projets; }
public:
    static ProjetManager& Instance();
};

#endif // PROJET_H
