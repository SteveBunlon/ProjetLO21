#ifndef ACTIVITE_H
#define ACTIVITE_H

#include <iostream>
#include <string>
#include "timing.h"

using namespace TIME;
using namespace std;

class Activite{
private:
    string titre;
    string description;
public:
    const string getTitre() const { return titre; }
    const string getDescription() const { return description; }
};
