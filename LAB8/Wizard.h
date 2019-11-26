#ifndef __WIZARD_H__
#define __WIZARD_H__

using namespace std;

#include "Character.h"

class Wizard : public Character
{
    public:
        Wizard(string, double, double, int);
        void attack(Character &) override;
        int getRank() const;
    private:
        int rank;
};

#endif