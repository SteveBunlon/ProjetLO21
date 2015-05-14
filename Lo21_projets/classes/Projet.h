#ifndef PROJET_H
#define PROJET_H

#include <iostream>
#include <string>
#include "timing.h"

using namespace TIME;
using namespace std;

class Tache;
class Programmation;

class Projet{
private:
    Tache** taches;
    unsigned int nb;
    unsigned int max;
    string titre;
    Duree dispo;        //date de début
    Duree echeance;     //échéance de la tâche la plus tardive
public:
    Projet(string t, unsigned int n, unsigned int m, Duree d, Duree e):
        titre(t), dispo(d), echeance(e), nb(n), max(m) {taches = new Tache*[5];}
    const unsigned int getNb() { return nb; }
    const unsigned int getMax() const { return max; }
    const string getTitre() const { return titre; }
    const Duree& getDispo() const { return dispo; }
    const Duree& getEcheance() const { return echeance; }
    Tache& getTache(unsigned int num) const { return *taches[num]; }
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
    const unsigned int getNb() const { return nb; }
    const unsigned int getMax() const { return max; }
    Projet& getProjet(unsigned int num) const { return *projets[num]; }
};

#endif // PROJET_H
