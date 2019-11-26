#include <iostream>

using namespace std;

#include "Character.h"
#include "Elf.h"

Elf::Elf(string name, double health, double attack, string family)
    : Character(ELF, name, health, attack), family(family) { }

void Elf::attack(Character& opponent)
{
    cout << "Elf " << name << " ";
    double finDmg = attackStrength * (health / MAX_HEALTH);
    if (opponent.getType() == ELF)
    {
        Elf& elf = dynamic_cast<Elf&>(opponent);
        if (elf.getFamily() == family)
        {
            cout << "does not attack Elf " << elf.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
            return;
        }
    }
    cout << "shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
    cout << opponent.getName() << " takes " << finDmg << " damage." << endl;
    opponent.damage(finDmg);
}

string Elf::getFamily() const
{
    return family;
}