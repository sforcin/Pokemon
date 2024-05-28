#include <fstream>
#include <iostream>
#include <unistd.h> 
#include "../includeFiles/Game.h"
#include "../includeFiles/Pokemon.h"
#include  "../includeFiles/Display.h"


Game::Game() : player("", ' ') {
    isNewGame = true;
}

void Game::saveGame(string filename) {
    ofstream outFile(filename);
    if(outFile){
        outFile<< "Player name: " <<player.getName() << endl;
        outFile << "Player XP: " << player.getXP() << endl;
        outFile << "Player HP: " << player.getHP() << endl;
        //we can add more things here.
        outFile.close();
    }
    else{
        __throw_out_of_range("Error opening file for saving");
    }
}

void Game::loadGame(string loadFileName) {
    cout << "Loading a save file does nothing at the moment." << endl;
    cout << "Starting a new game." << endl << endl;
}

void Game::turn() {
    int chance = rand() % 100; // random number between 0 and 100
    if (chance < 75) { // 75% of nothing happening
        cout << "Nothing Happened!!!" << endl;
    } else { // 25% chance of minibattle
        cout << "Mini Boss Encountered!!!" << endl;
        battle();
    }
}


void Game::battle() {
    int enemyHealth = rand() % 75;

    const int maxEnemyAttack = 50;

    cout << "Enemy:" << endl;
    cout << "    Max Attack Damage: " << maxEnemyAttack << endl;
    cout << "    Health: " << enemyHealth << endl;
    cout << endl;

    Pokemon *poke = this->pokes.at(0);
    cout << poke->getName() << ":" << endl;
    cout << "    Attack Damage: " << poke->attack() << endl;
    cout << "    Health: " << poke->checkHP() << endl;
    cout << endl;

    bool loop = true;
    while (loop) {
        if (enemyHealth <= 0 || poke->checkHP() <= 0) break;

        int chance = rand() % 100;
        int enemyDamage = rand() % maxEnemyAttack + 1;

        if (chance < 70) { // do damage to enemy
            enemyHealth -= poke->attack();
            cout << poke->getName() << " did " << poke->attack() << " damage to enemy!!!" << endl;
        } else { // enemy does damage to you
            poke->hurt(enemyDamage);
            cout << "Enemy did " << enemyDamage << " damage to " << poke->getName() << "!!!" << endl; 
        }
    }

    cout << endl;
    if (enemyHealth <= 0) { // enemy is dead
        cout << "Enemy Won This Battle!!! :(" << endl;
    } else { // your pokemon is dead
        cout << "You Won This Battle!!! :)" << endl;
    }
}


void Game::part1(){ 

    if(part1Complete == true){ //if part1 is completed by user, we would know and exit function 
        return;
    }

    type_text("Welcome to the world of Pokemon New trainer!");
    type_text(" Congrats on picking your first Pokemon.");
    cout << endl; 


    part1Complete = true; // when game is reloaded, we will know which parts were completed based on bools for each part
}



void type_text(const string& text) //SOURCED FROM CPLUSPLUS.COM
{
	// loop through each character in the text
	for (std::size_t i = 0; i < text.size(); ++i)
	{
		// output one character
		// flush to make sure the output is not delayed
		std::cout << text[i] << std::flush;
		
		// sleep 60 milliseconds
		usleep(40000); // use Sleep on windows
	}
     usleep(150000);
}
