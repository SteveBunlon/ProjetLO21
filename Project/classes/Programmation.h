#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include <iostream>
#include <string>
#include "timing.h"

using namespace TIME;
using namespace std;

class Tache;
class Projet;

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

#endif // PROGRAMMATION_H
