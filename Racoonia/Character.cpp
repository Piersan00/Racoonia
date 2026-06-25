#include "Character.h"
#include <iostream>

using std::cout;
using std::endl;

int Character::getDefense() {return c_Defense;}
string Character::getName() {return c_Name;}

Character::Character(string name, int life, int strenght, int defense) : c_Name(name), c_Life(life), c_Strenght(strenght), c_Defense(defense)
{

}

bool Character::isAlive()
{
    return c_Life > 0;
}

void Character::takeDamage(int damage)
{
    if (damage < 0)
    {
        damage = 0;
    }
    
    c_Life -= damage;
    
    cout << c_Name << " ha subito " << damage << " danni! Vita rimanente: " << c_Life << endl;
    
    if (c_Life <= 0)
    {
        cout << c_Name << " è morto!" << endl;
    }
}

void Character::attack(Character* bersaglio)
{
    if (bersaglio == nullptr)
    {
        return;
    }

    int damage = c_Strenght - bersaglio->c_Defense;
    
    cout << c_Name << " attack " << bersaglio->c_Name << "!" << endl;

    bersaglio->takeDamage(damage);
}