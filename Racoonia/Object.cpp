#include "Object.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

string Object::getOName() const {return o_Name;}
int Object::getOStrenght() {return o_BonusStrenght;}
int Object::getODefense() {return o_BonusDefense;}
int Object::getOLife() {return o_BonusLife;}

Object::Object(string Name, int BonusStrenght, int BonusDefense, int BonusLife) 
    : o_Name(Name), o_BonusStrenght(BonusStrenght), o_BonusDefense(BonusDefense), o_BonusLife(BonusLife)
{
    
}