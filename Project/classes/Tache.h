#ifndef TACHE_H
#define TACHE_H

#include <iostream>
#include <string>
#include "timing.h"

using namespace TIME;
using namespace std;

class Programmation;
class Projet;

class CalendarException{
    public:
        CalendarException(const string& message):info(message){}
        string getInfo() const { return info; }
    private:
        string info;
};

class Tache {
private:
    string titre;
    Tache** antecedentes;
    Date dispo;         //date de début
    Date echeance;
    Projet* projet;
public:
    Tache(const string& t, const Date& d, const Date& e):
        titre(t), dispo(d), echeance(e), projet(NULL){}
    Tache(const string& t, const Date& d, const Date& e, Projet& proj):
        titre(t), dispo(d), echeance(e) { projet = &proj; }
    const string getTitre() const { return titre; }
    const Date getDispo() const { return dispo; }
    const Date getEcheance() const { return echeance; }
    const Projet* getProjetAssocie() const { return projet; }
    virtual ~Tache() = 0;
};

class TacheUnitaire: public Tache{
private:
    Duree duree;        //si non preemptive, ne peut être > 12h
    bool preemptive;
public:
    TacheUnitaire(const string& t, const Date& d, const Date& e, const Duree& dur, const bool& p):
        Tache(t, d, e), duree(dur), preemptive(p) {}
    TacheUnitaire(const string& t, const Date& d, const Date& e, Projet& proj, const Duree& dur, const bool& p):
        Tache(t, d, e, proj), duree(dur), preemptive(p) {}
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
    TacheComposite(string t, Date d, Date e):
        Tache(t, d, e), nb(0), max(0), soustaches(NULL) {}
    TacheComposite(string t, Date d, Date e, Projet& proj):
        Tache(t, d, e, proj), nb(0), max(0), soustaches(NULL) {}
    Tache& getSousTache(unsigned int num)const { return *soustaches[num]; }
    const unsigned int getNb() const { return nb; }
    const unsigned int getMax() const { return max; }
    ~TacheComposite(){}
};

class TacheManager {
private:
    Tache** taches;
    unsigned int nb;
    unsigned int max;
    void addTache(Tache* t);
public:
    TacheManager(): taches(NULL), nb(0), max(0){}
    TacheManager(const TacheManager& t){ *this = t; }
    ~TacheManager();
    bool existTache(const string& titre);
    void createTacheUnitaire(const string& t, const Date& dispo, const Date& echeance, const Duree& duree, const bool preemptive);
    void createTacheUnitaire(const string& t, const Date& dispo, const Date& echeance, const Duree& duree, const bool preemptive, Projet& proj);
    void createTacheComposite(const string& t, const Date& dispo, const Date& echeance);
    void createTacheComposite(const string& t, const Date& dispo, const Date& echeance, const Duree& duree, const bool preemptive, Projet& proj);
    Tache& getTache(const string& titre);
    const Tache& getTache(const string& titre) const { return this->getTache(titre); }
    void operator=(const TacheManager& t);
};

#endif // TACHE_H
