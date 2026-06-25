#include "Boss.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using std::string;
using std::cout;
using std::cin;
using std::endl; 

Boss::Boss(string name, int life, int strenght, int defense) : Enemy(name, life, strenght, defense)
{
 
}

void Boss::attack(Character* target)
{
    cout << "ATTACCO PROROMPENTE DELLE SETTE VIE DEL RAGU' ALLA BOLOGNESE!!!" << endl;

    if (target == nullptr)
    {
        return;
    }

    int damage = c_Strenght * 1.5 - target->getDefense();

    std::this_thread::sleep_for(std::chrono::seconds(4));
    
    cout << c_Name << " attack " << target->getName() << "!" << endl;

    target->takeDamage(damage);

}