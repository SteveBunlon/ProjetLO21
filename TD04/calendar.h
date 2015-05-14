#ifndef CALENDAR_H_INCLUDED
#define CALENDAR_H_INCLUDED
#include<string>
#include<iostream>
#include "timing.h"

using namespace std;
using namespace TIME;

class CalendarException{
    public:
        CalendarException(const string& message):info(message){}
        string getInfo() const { return info; }
    private:
        string info;
};

class Tache{
    private:
        string _ID, _titre;
        Duree _duree;
        Date _disponibilite, _echeance;
        Tache** tachePrecedee; //ensemble de tahce précédée par la tache.
    public:
        Tache(const string& id, const string& titre, const Duree& duree, const Date& dispo, const date& ech):
            _ID(id), _titre(titre), _duree(duree), _disponibilté(dispo), _echeance(ech)
            {}

        const string& getID(){return this->_ID;};
        const string& getTitre(){return this->_titre;};
        const Duree& getDuree(){return this->_duree;};
        const Date& getDisopnibilite(){return this->_duree;};
        const Date& getEcheance(){return this->_echeance;};
}

class TacheManager {
    private:
        Tache** taches;
        unsigned int nb;
        unsigned int nbMax;
        void addItem(Tache* t);
    public:
        TacheManager(): taches(NULL), nb(0), nbMax(0){};
        TacheManager(const tacheManager& t){*this = t;}
        ~TacheManager();
        void ajouterTache(const string& id, const string& t, const Duree& dur, const Date& dispo, const Date& deadline);
        Tache& getTache(const string& id);
        const Tache& getTache(const string& id) const {return this->getTache(id);};
        void operator=(const TacheManager& t);
};

class Programmation{
    Tache * tache;
    Date date;
    Horaire horaire;
    public:
        Programmation(Tache* t, Date d, Horaire h, ):tache(t), date(d), horaire(h){};
        const Tache& gettache(){return this->t;};
        const Date& getDate(){return this->date;};
        const Horaire& getHoraire(){return this->horaire;};
}

#endif // CALENDAR_H_INCLUDED
