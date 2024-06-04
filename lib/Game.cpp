//GAMECPP

#include <fstream>
#include <iostream>
#include <unistd.h> 
#include <vector>
#include "../includeFiles/Game.h"
#include "../includeFiles/Pokemon.h"
#include  "../includeFiles/Display.h"
#include  "../includeFiles/Player.h"

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
        cout << "You Won This Battle!!! :)" << endl;
    } else { // your pokemon is dead
        cout << "Enemy Won This Battle!!! :(" << endl;
    }
}

void Game::part1(){ 

    Pokemon *starterPoke = pokes.at(0);
    char choice = 'x'; 

    if(part1Complete == true){ //if part1 is completed by user, we would know and exit function 
        return;
    }

    type_text("You are a young Pokemon Trainer starting your journey in the region of Veridia."); 
    type_text("Your goal is to become the Pokemon Champion by defeating the region's strongest trainers and uncovering the mysteries of the ancient Pokemon said to reside in Veridia's depths.");
    type_text("Goodluck.");
    cout << endl;
    type_text("Transpoting you to the world of Pokemon....");

    //TODO:insert ascii of transporting lol 

    type_text("Welcome to Pinewood Town, where your journey begins.");
    type_text("You are at Professor Maple's lab, where you just chose your first Pokemon. Congrats!");
    cout << endl; 
    cout << endl; 
    type_text("Professor Maple: 'Ah, ", player.getName());
    type_text(", it's great to see you again! I had three Pokemon for you to choose from: Bulbasaur, Charmander, and Squirtle.");
    type_text("Didn't you choose ", starterPoke->getName());
    type_text("?");
    cout << endl; 
    type_text("(Y/N): ");

    cin >> choice; 

    char pokechoice = 'x'; 
    while (tolower(choice) == 'n'){
        type_text("I see I've made a mistake. " , "I had three Pokemon for you to choose from: Bulbasaur, Charmander, and Squirtle.");
        cout << endl;
        type_text("Which pokemon would you like? (C - Charmander / B - Bulbasaur / S - Squirtle): ");
        cin >> pokechoice;

       while(tolower(pokechoice) != 'c' && tolower(pokechoice) != 'b' && tolower(pokechoice) != 's'){
            cout << endl; 
            type_text("Looks like you didn't choose one of our available options!");
            type_text("Please select with these options: 'B', 'C', 'S' for Bulbasaur, Charmander, or Squirtle!");
            cin >> pokechoice; 
        }

        
        if(tolower(pokechoice) == 'c') {
            starterPoke = new CharmanderLine();
        } else if(tolower(pokechoice) == 'b') {
            starterPoke = new BulbasaurLine();
        } else if(tolower(pokechoice) == 's') {
            starterPoke = new SquirtleLine();
        }

        pokes[0] = starterPoke;

        type_text("Now then new trainer, your new chosen pokemon is: ", starterPoke->getName());
        type_text(". Is this correct?");
        cout << endl; 
        type_text("(Y/N): ");
        cin >> choice; 
    }




    type_text("Great choice! Take this Pokedex and start your journey. Your first challenge is to reach Fernleaf City and challenge the Gym Leader there.");
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
		
		// sleep 30 milliseconds
		usleep(30000); // use Sleep on windows
	}
     usleep(150000);
     cout << endl; 
}

void type_text(const string& text1, const string& text2) //SOURCED FROM CPLUSPLUS.COM
{
	// loop through each character in the text
	for (std::size_t i = 0; i < text1.size(); ++i)
	{
		// output one character
		// flush to make sure the output is not delayed
		std::cout << text1[i] << std::flush;
		
		// sleep 30 milliseconds
		usleep(30000); // use Sleep on windows
	}

    for (std::size_t i = 0; i < text2.size(); ++i)
	{
		// output one character
		// flush to make sure the output is not delayed
		std::cout << text2[i] << std::flush;
		
		// sleep 60 milliseconds
		usleep(40000); // use Sleep on windows
	}
     usleep(150000);

}
