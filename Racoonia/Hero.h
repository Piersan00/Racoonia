#pragma once
#include <string>
#include <vector>
#include "Character.h"
#include "Object.h"

using std::string;
using std::vector;


class Hero : public Character
{
   protected:
    int e_Level;
    int e_Xp;
    int e_XP_NextLevel;

   public:
    Hero();

    bool createCharacter();
    void printSheet();
    void openInventory();
    void addObject(Object Object);
    void gainXP(int points);
   
   private:
   vector<Object> e_Inventario;
    
};