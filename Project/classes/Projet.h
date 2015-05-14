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
    Tache** tachesAssociees;
    unsigned int nb;
    unsigned int max;
    string titre;
    Date dispo;        //date de début
    Date echeance;     //échéance de la tâche la plus tardive
public:
    Projet(const string& t, const Date& d, const Date& e):
        titre(t), dispo(d), echeance(e), tachesAssociees(NULL) {}
    Projet(const string& t, const unsigned int& n, const Date& d, const Date& e):
        titre(t), dispo(d), echeance(e), nb(n), tachesAssociees(NULL) {}
    Projet(const string& t, const unsigned int n, const unsigned int m, const Date& d, const Date& e):
        titre(t), dispo(d), echeance(e), nb(n), max(m) {tachesAssociees = new Tache*[5];}
    const int getNb() const { return nb; }
    const int getMax() const { return max; }
    const string getTitre() const { return titre; }
    const Date& getDispo() const { return dispo; }
    const Date& getEcheance() const { return echeance; }
    Tache& getTache(unsigned int num) const { return *tachesAssociees[num]; }
};

class ProjetManager {
private:
    Projet** projets;
    unsigned int nb;
    unsigned int max;
    static ProjetManager Pmanager;

    ProjetManager():nb(0), max(0), projets(NULL) {}
    ~ProjetManager();
public:
    static ProjetManager& Instance();
    const unsigned int getNb() const { return nb; }
    const unsigned int getMax() const { return max; }
    Projet& getProjet(unsigned int num) const { return *projets[num]; }
};

#endif // PROJET_H
