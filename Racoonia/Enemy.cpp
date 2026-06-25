#include "Enemy.h"
#include "Object.h"
#include <cstdlib>
#include <ctime>
using std::string;


Object Enemy::dropLoot()
{
    vector<Object> pool;
    pool.push_back(Object("Spada Smussata", 2, 0, 0));
    pool.push_back(Object("Spada di Rame", 4, 0, 0));
    pool.push_back(Object("Spada di Ferro", 6, 0, 0));
    pool.push_back(Object("Spada di Cheat", 20, 0, 0));
    pool.push_back(Object("Scudo di Legno", 0, 2, 0));
    pool.push_back(Object("Scudo di Rame", 0, 4, 0));
    pool.push_back(Object("Scudo di Ferro", 0, 6, 0));
    pool.push_back(Object("Scudo di Cheat", 0, 20, 0));
    pool.push_back(Object("Spazzatura", 0, 0, 0));
    
    int indice = rand() % pool.size();
    return pool[indice];
}

Enemy::Enemy(string name, int life, int strenght, int defense) : Character(name, life, strenght, defense)
{
 
}

int Enemy::getXP()
{
    return c_Strenght * 10;
}