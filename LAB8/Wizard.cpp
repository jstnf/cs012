#include <iostream>

using namespace std;

#include "Character.h"
#include "Wizard.h"

Wizard::Wizard(string name, double health, double attack, int rank)
    : Character(WIZARD, name, health, attack), rank(rank) { }

void Wizard::attack(Character& opponent)
{
    cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    double finDmg = attackStrength;
    if (opponent.getType() == WIZARD)
    {
        Wizard& wiz = dynamic_cast<Wizard&>(opponent);
        finDmg = attackStrength * (static_cast<double>(rank) / static_cast<double>(wiz.getRank()));
    }
    cout << opponent.getName() << " takes " << finDmg << " damage." << endl;
    opponent.damage(finDmg);
}

int Wizard::getRank() const
{
    return rank;
}