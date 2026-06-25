#pragma once
#include "Character.h"
#include "Object.h"
#include <string>




class Enemy : public Character
{
    public:
    Enemy(string name, int life, int strenght, int defense);
    int getXP();
    Object dropLoot();

    private:
    vector<string> n_Loot;
};