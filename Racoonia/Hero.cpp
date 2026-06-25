#include "Hero.h"
#include "Character.h"
#include "Object.h"
#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;    

Hero::Hero() : Character("Sconosciuto", 0, 0, 0) 
{
    e_Level = 1;
    e_Xp = 0;
    e_XP_NextLevel = 10;
    
    e_Inventario.clear(); 
}

bool Hero::createCharacter() 
{       
    cout << "CREAZIONE EROE" << endl;
    
    cout << "Nome: ";
    cin >> c_Name;
    
    cout << "Vita (max 10): ";
    cin >> c_Life;

    if (c_Life > 10)
    {
        cout << "A fa lo sborone ti metto la vita ad 1, tiè" << endl;
        c_Life = 1;
    }
    else if (c_Life <= 0)
    {
        cout << "Morire alla creazione, vanne fiero" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return false;        
    }
    
    cout << "Forza (max 5): ";
    cin >> c_Strenght;

    if (c_Strenght > 5)
    {
        cout << "HAHAHAHAAHAHAHAHAH, tiè" << endl;
        c_Strenght = 1;
    }
    else if (c_Strenght <= 0)
    {
        cout << "Un soffio di vento ti trasporta via, le fin" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return false;
    }

    c_Defense = c_Strenght/1.5;

    Object spada("spada", 5, 0, 0);

    e_Inventario.push_back(spada);
    Object scudo("Scudo", 0, 1, 0);
    e_Inventario.push_back(scudo);

    return true;
}

void Hero::addObject(Object oggetto)
{
    e_Inventario.push_back(oggetto);
}

void Hero::openInventory() 
{
    if (e_Inventario.empty())
    {
        cout << "Non hai oggetti." << endl;
        return;
    }

    cout << "--- INVENTARIO ---" << endl;
    
    // Stampa inventario numerato
    for (int i = 0; i < e_Inventario.size(); i++)
    {
        cout << "[" << i << "] " << e_Inventario[i].getOName() << endl;
    }

    cout << "Cosa vuoi equipaggiare? (0 per uscire): ";
    int scelta;
    cin >> scelta;

    if (scelta >= 0 && scelta < e_Inventario.size()) 
    {
        // Aggiungi statistichje
        c_Strenght += e_Inventario[scelta].getOStrenght();
        c_Defense += e_Inventario[scelta].getODefense();
        c_Life += e_Inventario[scelta].getOLife();

        // Cancella oggetto selezionato
        e_Inventario.erase(e_Inventario.begin() + scelta);

        cout << "Oggetto equipaggiato!" << endl;
    }
    else if (scelta != 0)
    {
        cout << "Scelta non valida." << endl;
    }
}

// TODO: aggiungere sistema per non far sommare le statistiche e mantenere vecchi equip dop averli rimossi (magari aggiungere vendita e soldi subito dopo)

void Hero::printSheet()
{
    cout << "--- SCHEDA ---" << endl;
    cout << "Nome: " << c_Name << endl;
    cout << "Livello: " << e_Level << " | al prossimo livello " << e_Xp << " / " << e_XP_NextLevel << endl;
    cout << "Vita: " << c_Life << endl;
    cout << "Forza: " << c_Strenght << endl;
    cout << "Difesa: " << c_Defense << endl;
    
    cout << "Inventario : ";
    for (const auto& item : e_Inventario) 
    {
        cout << item.getOName() << " | ";
    }
    cout << endl;
}

void Hero::gainXP(int points)
{
    e_Xp += points;
    
    if (e_Xp >= e_XP_NextLevel)
    {
        cout << "-------LEVEL UP!!!-------" << endl;
        e_Level++;
        c_Strenght += 2;
        c_Life += 4;
        c_Defense = c_Strenght/1.5;

        e_Xp -= e_XP_NextLevel;
        e_XP_NextLevel += e_Level * 10;
    }
}