#ifndef TACHE_H
#define TACHE_H

#include <iostream>
#include <string>
#include "timing.h"

using namespace TIME;
using namespace std;

class Programmation;
class Projet;

class Tache {
private:
    string titre;
    Tache** antecedentes;
    Date dispo;         //date de début
    Date echeance;
    Projet& projet;
public:
    Tache(string t, Date d, Date e): titre(t), dispo(d), echeance(e) {}
    const string getTitre() const { return titre; }
    const Date getDispo() const { return dispo; }
    const Date getEcheance() const { return echeance; }
    const Projet& getProjetAssocie() const { return projet; }
};

class TacheUnitaire: public Tache{
private:
    Duree duree;        //si non preemptive, ne peut être > 12h
    bool preemptive;
public:
    const Duree& getDuree() const { return duree; }
    const bool isPreemptive() const { return preemptive; }
};

class TacheComposite: public Tache{
private:
    Tache** soustaches;
    unsigned int nb;
    unsigned int max;
public:
    Tache** getSousTache()const { return soustaches; }
};

#endif // TACHE_H
