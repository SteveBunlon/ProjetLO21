#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>

class Projet{
private:
    Tache** taches;
    Duree dispo;        //date de début
    Duree echeance;     //échéance de la tâche la plus tardive
public:
    Projet(Duree d, Duree e): dispo(d), echeance(e) {taches = new Tache*[5];}
    const Duree& getDispo() const { return dispo; }
    const Duree& getEcheance() const { return echeance; }
    addTache()
};

class Tache {
private:
    string titre;
    Tache** antecedentes;
    Date dispo;         //date de début
    Date echeance;
    Projet& projet;
public:
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
    const Tache& getSousTaches()const { return soustaches; }
};

class Activite {
private:
    string titre;
    string description;
public:
    const string getTitre() const { return titre; }
    const string getDescription() const { return description; }
};

class Programmation {
private:
    Date debut;
    Duree duree;
public:
    const Date& getDebut() const { return debut; }
    const Duree& getDuree() const { return duree; }

};

class ProgrammationManager {
private:
    Programmation** programmations;
    unsigned int nb;
    unsigned int max;
    static ProgrammationManager Pmanager;

    ProgrammationManager():nb(0), max(10) { programmations = new Programmation*[10]; }
    ~ProgrammationManager() { delete[] programmations; }
public:
    static ProgrammationManager& Instance();
};

#endif // CLASSES_H

