#ifndef __WARRIOR_H__
#define __WARRIOR_H__

using namespace std;

#include "Character.h"

class Warrior : public Character
{
    public:
        Warrior(string, double, double, string);
        void attack(Character &) override;
        string getAllegiance() const;
    private:
        string allegiance;
};

#endif