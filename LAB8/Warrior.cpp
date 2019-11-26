#include <iostream>

using namespace std;

#include "Character.h"
#include "Warrior.h"

Warrior::Warrior(string name, double health, double attack, string allegiance)
    : Character(WARRIOR, name, health, attack), allegiance(allegiance) { }

void Warrior::attack(Character& opponent)
{
    cout << "Warrior " << name << " ";
    double finDmg = attackStrength * (health / MAX_HEALTH);
    if (opponent.getType() == WARRIOR)
    {
        Warrior& war = dynamic_cast<Warrior&>(opponent);
        if (war.getAllegiance() == allegiance)
        {
            cout << "does not attack Warrior " << war.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
            return;
        }
    }
    cout << "attacks " << opponent.getName() << " --- SLASH!!" << endl;
    cout << opponent.getName() << " takes " << finDmg << " damage." << endl;
    opponent.damage(finDmg);
}

string Warrior::getAllegiance() const
{
    return allegiance;
}