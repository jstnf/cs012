#ifndef __ELF_H__
#define __ELF_H__

using namespace std;

#include "Character.h"

class Elf : public Character
{
    public:
        Elf(string, double, double, string);
        void attack(Character &) override;
        string getFamily() const;
    private:
        string family;
};

#endif