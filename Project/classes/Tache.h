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
    Tache(string t, Date d, Date e, Projet& proj): titre(t), dispo(d), echeance(e), projet(proj) { antecedentes = new Tache*[10]; }
    const string getTitre() const { return titre; }
    const Date getDispo() const { return dispo; }
    const Date getEcheance() const { return echeance; }
    const Projet& getProjetAssocie() const { return projet; }
    virtual ~Tache() = 0;
};

class TacheUnitaire: public Tache{
private:
    Duree duree;        //si non preemptive, ne peut être > 12h
    bool preemptive;
public:
    TacheUnitaire(string t, Date d, Date e, Projet& proj, Duree dur, bool p): Tache(t, d, e, proj), duree(dur), preemptive(p) {}
    const Duree& getDuree() const { return duree; }
    const bool isPreemptive() const { return preemptive; }
    ~TacheUnitaire(){}
};

class TacheComposite: public Tache{
private:
    Tache** soustaches;
    unsigned int nb;
    unsigned int max;
public:
    TacheComposite(string t, Date d, Date e, Projet& proj): Tache(t, d, e, proj), nb(0), max(10) { soustaches = new Tache*[10]; }
    Tache** getSousTache()const { return soustaches; }
    ~TacheComposite(){}
};

#endif // TACHE_H
