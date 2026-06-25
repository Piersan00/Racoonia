#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime> 

#include "Hero.h"
#include "Enemy.h"
#include "Boss.h"


using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    srand(time(0));
    cout << "Benvenuto su ..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // ... (ASCII ART TITOLO) ...
    cout << " _____            _____ ____   ____  _   _ _____          " << endl;
    cout << "|  __ \\     /\\   / ____/ __ \\ / __ \\| \\ | |_   _|   /\\   " << endl;
    cout << "| |__) |   /  \\ | |   | |  | | |  | |  \\| | | |    /  \\  " << endl;
    cout << "|  _  /   / /\\ \\| |   | |  | | |  | | . ` | | |   / /\\ \\ " << endl;
    cout << "| | \\ \\  / ____ \\ |___| |__| | |__| | |\\  |_| |_ / ____ \\" << endl;
    cout << "|_|  \\_\\/_/    \\_\\_____/____/ \\____/|_| \\_|_____/_/    \\_\\" << endl;

    Hero player1;
    bool confermato = false;
    char scelta;
    int stanza = 1;

    // Creazione
    while (!confermato) 
    {
        bool successo = player1.createCharacter(); 

        // Se muore durante la creazione
        if (!successo)
        {
            cout << "Game Over Git Gud." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return 0;
        }

        // se vivo procedi con scheda
        player1.printSheet();

        // Conferma
        cout << "Confermi questo personaggio? (Y/N): ";
        cin >> scelta;

        if (scelta == 'Y' || scelta == 'y') 
        {
            confermato = true;
        } 
        else if (scelta == 'N' || scelta == 'n')
        {
            cout << "Il tuo procione è appena stato lanciato nell'iperspazio, rifacciamo" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
        else
        {
            cout << "Se non sai neanche premere una lettera ho brutte notizie per te" << endl;
          std::this_thread::sleep_for(std::chrono::seconds(5));
          cout << "Siamo seri questo è un gioco su dei procioni ma le basi almeno" << endl;
          std::this_thread::sleep_for(std::chrono::seconds(5));
          cout << "Dio se amo quegli esseri pelosi" << endl;
          std::this_thread::sleep_for(std::chrono::seconds(5));
          cout << "E che tecnica con quelle zampette" << endl;
          std::this_thread::sleep_for(std::chrono::seconds(5));
          cout << "O Cholera Czy To Freddy Fazbear" << endl;
          std::this_thread::sleep_for(std::chrono::seconds(5));
          cout << "Har Har Har Har Har Har Har Har Har Har" << endl;
          std::this_thread::sleep_for(std::chrono::seconds(5));
          cout << "Se ti aspettavi un jumpscare hai sbagliato gioco" << endl;
          std::this_thread::sleep_for(std::chrono::seconds(5));



          cout << "       ,       ,                                          " << endl;
          cout << "      ( \\     / (                                         " << endl;
          cout << "      \\  '---'  /                                         " << endl;
          cout << "      /.--. .--,\\   .-'''-,                               " << endl;
          cout << "     /\\_(o) (o)_/\\ /\\ | /  \\                            " << endl;
          cout << " __.-.___(_c_)_.-./\\ \\ / / /)                            " << endl;
          cout << "(__(((_________)))__--''/ / /                             " << endl;
          cout << " |  ||  ||  ||  ||  ||   / )                              " << endl;
          cout << " |  ||  ||  ||  ||  ||   |/                               " << endl;
          cout << " |  ||  ||  ||  ||  ||   '                                " << endl;
          cout << " \\  ||  ||  ||  ||  ||                                   " << endl;
          cout << "  \\ ||  ||  ||  |.- -'''- -._                            " << endl;
          cout << "  /\\||  ||  ||  ;            :                           " << endl;
          cout << " |  ||  ||  || :      __      ;                          " << endl;
          cout << " |  ||  ||  ||:      (  (      :                         " << endl;
          cout << " |  ||  ||  ||;               .                          " << endl;
          cout << " |  ||  ||  || ,             ,                           " << endl;
          cout << " .,_c,__.,__ldb__'- -,..,- -'                            " << endl;

          std::this_thread::sleep_for(std::chrono::seconds(5)); 
        }
    }

    cout << "\nBenvenuto in un mondo di procioni e magia\n" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    vector<string> nomeNemico;
    nomeNemico.push_back("Fernando / il Tasso");
    nomeNemico.push_back("Ludvilla / lontra magica");
    nomeNemico.push_back("Procione zombie");
    nomeNemico.push_back("Salazar / ladro Lucertola");
    nomeNemico.push_back("Coccolo / Orso gueriero");
    nomeNemico.push_back("Fernando / il Tasso fratello gemello");
    nomeNemico.push_back("ERROR!!!");

    while (stanza <= 5 && player1.isAlive())
    {
        Enemy* avversario = nullptr;
        int nomeNemicoCasuale = rand() % nomeNemico.size();
        string nomeScelto = nomeNemico[nomeNemicoCasuale];

        if (stanza == 5)
        {
            avversario = new Boss("ER TASSONE BOLOGNESE", 100, 15, 5);
        }
        else
        {
            avversario = new Enemy(nomeScelto, 10 + stanza * 2, 2 + stanza * 1.5, 1 + stanza * 1.3);
        }
           

        while (player1.isAlive() && avversario->isAlive())
        {

            player1.attack(avversario);
            std::this_thread::sleep_for(std::chrono::seconds(4));

           if (avversario->isAlive())
           {
               avversario->attack(&player1);
               std::this_thread::sleep_for(std::chrono::seconds(4));
           }
        
        }

        if (!avversario->isAlive()) 
        {
            cout << "L'avversario soccombe alla tua procionità" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(4));
    
            Object bottino = avversario->dropLoot();
            std::this_thread::sleep_for(std::chrono::seconds(4));
            player1.gainXP(avversario->getXP());
            std::this_thread::sleep_for(std::chrono::seconds(4));
    
            if (bottino.getOName() != "Niente") 
            {
                cout << "Hai trovato: " << bottino.getOName() << "!" << endl;
                player1.addObject(bottino);

                std::this_thread::sleep_for(std::chrono::seconds(4));

                player1.printSheet();

                std::this_thread::sleep_for(std::chrono::seconds(4));
            }

            player1.openInventory();
        }
    
        
        delete avversario;
        stanza++;
    }
    
    if(!player1.isAlive())
    {
        cout << "Game Over. Git gud" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(4));

        return 0;
    }
    else
    {
        cout << "Racoonia è salva *non ho voglia di scrivere un wall of text, gg e congratulazioni" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(4));


        cout << "       ,       ,                                          " << endl;
          cout << "      ( \\     / (                                         " << endl;
          cout << "      \\  '---'  /                                         " << endl;
          cout << "      /.--. .--,\\   .-'''-,                               " << endl;
          cout << "     /\\_(o) (o)_/\\ /\\ | /  \\                            " << endl;
          cout << " __.-.___(_c_)_.-./\\ \\ / / /)                            " << endl;
          cout << "(__(((_________)))__--''/ / /                             " << endl;
          cout << " |  ||  ||  ||  ||  ||   / )                              " << endl;
          cout << " |  ||  ||  ||  ||  ||   |/                               " << endl;
          cout << " |  ||  ||  ||  ||  ||   '                                " << endl;
          cout << " \\  ||  ||  ||  ||  ||                                   " << endl;
          cout << "  \\ ||  ||  ||  |.- -'''- -._                            " << endl;
          cout << "  /\\||  ||  ||  ;            :                           " << endl;
          cout << " |  ||  ||  || :      __      ;                          " << endl;
          cout << " |  ||  ||  ||:      (  (      :                         " << endl;
          cout << " |  ||  ||  ||;               .                          " << endl;
          cout << " |  ||  ||  || ,             ,                           " << endl;
          cout << " .,_c,__.,__ldb__'- -,..,- -'                            " << endl;

          std::this_thread::sleep_for(std::chrono::seconds(4));

        return 0;
    }
    
    

    
    return 0;
}
    


    
    
    
        
    
  
