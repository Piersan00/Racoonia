#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Character
{
public:

    Character(string name, int life, int strenght, int defense);

    virtual ~Character() {}

    void takeDamage(int danno);
    bool isAlive();

    //getter
    int getDefense();
    string getName();

    virtual void attack(Character* bersaglio);

protected:

    string c_Name; 
    int c_Life;
    int c_Strenght;
    int c_Defense;
};