#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Object
{
public:

    Object(string Name, int BonusStrenght, int BonusDefense, int BonusLife);

    int getOStrenght();
    int getODefense();
    int getOLife();
    string getOName() const;


private: 

    string o_Name;
    int o_BonusStrenght;
    int o_BonusDefense;
    int o_BonusLife;

};