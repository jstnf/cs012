#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

int main()
{
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    cout << endl;

    srand(seed);

    vector<Character*> adventurers;
    adventurers.push_back(new Warrior("Arthur", 100, 5, "King George"));
    adventurers.push_back(new Warrior("Jane", 100, 6, "King George"));
    adventurers.push_back(new Warrior("Bob", 100, 4, "Queen Emily"));
    adventurers.push_back(new Elf("Raegron", 100, 4, "Sylvarian"));
    adventurers.push_back(new Elf("Cereasstar", 100, 3, "Sylvarian"));
    adventurers.push_back(new Elf("Melimion", 100, 4, "Valinorian"));
    adventurers.push_back(new Wizard("Merlin", 100, 5, 10));
    adventurers.push_back(new Wizard("Adali", 100, 5, 8));
    adventurers.push_back(new Wizard("Vrydore", 100, 4, 6));

    unsigned numAttacks = 10 + rand() % 11;
    unsigned attacker, defender;
    for (unsigned i = 0; i < numAttacks; ++i)
    {
        attacker = rand() % adventurers.size();
        do
        {
            defender = rand() % adventurers.size();
        }
        while (defender == attacker);

        adventurers.at(attacker)->attack(*adventurers.at(defender));
        cout << endl;
    }
    cout << "-----Health Remaining-----" << endl;
    for (unsigned i = 0; i < adventurers.size(); ++i)
    {
        cout << adventurers.at(i)->getName() << ": "
             << adventurers.at(i)->getHealth() << endl;
    }

    return 0;
}