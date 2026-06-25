#pragma once
#include "Enemy.h"
#include <string>

class Boss : public Enemy
{
    public:
    Boss(string nome, int vita, int forza, int difesa);
    

    void attack(Character* bersaglio) override;

};