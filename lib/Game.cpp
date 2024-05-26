#include <fstream>
#include <iostream>
#include "../includeFiles/Game.h"
#include "../includeFiles/Pokemon.h"


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
