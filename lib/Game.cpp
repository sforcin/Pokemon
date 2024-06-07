//GAMECPP

#include <fstream>
#include <iostream>
#include <unistd.h> 
#include <vector>
#include "../includeFiles/Game.h"
#include "../includeFiles/Pokemon.h"
#include  "../includeFiles/Display.h"
#include  "../includeFiles/Player.h"

using namespace std;  

Game::Game() : player("", ' ') {
    isNewGame = true;
}

// ---------EX of whats in file------------
// Name
// XP
// Level
// HP 
// part1Complete
// Player Inventory
// Pokemon Vector
// ----------------------------------------
void Game::saveGame(string filename) {
    ofstream outFile(filename);
    if(outFile){
        //save player information
        outFile << filename << endl;
        outFile << player.getName() << endl;
        outFile << player.getXP() << endl;
    

        if(isNewGame == true){
            outFile << "t" << endl;
        }
        else if (isNewGame == false){
            outFile << "f" << endl;
        }

        if(part1Complete == true){
            outFile << "t" << endl;
        }
        else if (part1Complete == false){
            outFile << "f" << endl;
        }

        if(part2Complete == true){
            outFile << "t" << endl;
        }
        else if (part2Complete == false){
            outFile << "f" << endl;
        }

        if(part3Complete == true){
            outFile << "t" << endl;
        }
        else if (part4Complete == false){
            outFile << "f" << endl;
        }
        if(part4Complete == true){
            outFile << "t" << endl;
        }
        else if (part4Complete == false){
            outFile << "f" << endl;
        }
        if(part5Complete == true){
            outFile << "t" << endl;
        }
        else if (part5Complete == false){
            outFile << "f" << endl;
        }
        if(part6Complete == true){
            outFile << "t" << endl;
        }
        else if(part6Complete == false){
            outFile << "f" << endl;
        }
        // Save player inventory
        const vector<string>& inventory = player.getInventory();
        outFile << inventory.size() << endl;
        for (const string& item : inventory) {
            outFile << item << endl;
        }
        
        // Save Pokémon vector
        outFile << pokes.size() << endl;
        for (const Pokemon* poke : pokes) {
            // Save Pokémon data (you'll need to adjust this based on your actual Pokémon class)
            outFile << poke->getName() << " " << poke->getType() << " " << poke->checkHP() << " " << poke->attack() << " " << poke->defense() << " " << poke->getType() << " " << poke->speedAttack() << " " << poke->speedDefense() << endl;
        }

        //Game saved
        cout << "Game saved successfully." << endl;
        outFile.close();
    }
    else{
        cout << "Error opening file for saving." << endl;
    }
}

void Game::loadGame(const string& loadFileName) {
    ifstream inFile(loadFileName);
    if (inFile.is_open()) {
        // Load player information
        string filename;
        string playerName;
        int playerXP;
        string isNewGame; 
        string part1TrueOrFalse;
        string part2TrueOrFalse;
        string part3TrueOrFalse;
        string part4TrueOrFalse;
        string part5TrueOrFalse;
        string part6TrueOrFalse;

        getline(inFile, filename);
        inFile >> playerName; 
        inFile >> playerXP;
        inFile >> isNewGame; 
        inFile >> part1TrueOrFalse;
        inFile >> part2TrueOrFalse;
        inFile >> part3TrueOrFalse;
        inFile >> part4TrueOrFalse;
        inFile >> part5TrueOrFalse;
        inFile >> part6TrueOrFalse;
        player.setName(playerName);
        player.setXP(playerXP);
        
        if(isNewGame == "t"){ isNewGame = true;}
        else if(isNewGame == "f"){isNewGame = false;}
        if(part1TrueOrFalse == "t"){ part1Complete = true;}
        else if(part1TrueOrFalse == "f"){part1Complete = false;}
        if(part2TrueOrFalse == "t"){ part2Complete = true; }
        else if(part2TrueOrFalse == "f"){part2Complete = false;}
        if(part3TrueOrFalse == "t"){ part3Complete = true; }
        else if(part3TrueOrFalse == "f"){part3Complete = false;}
        if(part4TrueOrFalse == "t"){ part4Complete = true; }
        else if(part4TrueOrFalse == "f"){part4Complete = false;}
        if(part5TrueOrFalse == "t"){ part5Complete = true; }
        else if(part5TrueOrFalse == "f"){part5Complete = false;}
        if(part6TrueOrFalse == "t"){ part6Complete = true; }
        else if(part6TrueOrFalse == "f"){part6Complete = false;}
     
        // Load player inventory
        int inventorySize;
        inFile >> inventorySize;
        vector<string> inventory;
        inFile.ignore(); // Ignore newline character before reading strings
        for (int i = 0; i < inventorySize; ++i) {
            string item;
            getline(inFile, item);
            inventory.push_back(item);
        }
        player.setInventory(inventory);
        // Load Pokémon vector
        int numPokemons;
        inFile >> numPokemons;
        pokes.clear(); // Clear existing Pokémon
        inFile.ignore(); // Ignore newline character before reading strings
        for (int i = 0; i < numPokemons; ++i) {
            string pokeName, pokeType;
            int pokeHP, pokeAttack, pokeDefense, pokeSpeedAttack, pokeSpeedDefense;
            
            getline(inFile, pokeName, ' ');
            getline(inFile, pokeType, ' ');
            inFile >> pokeHP >> pokeAttack >> pokeDefense >> pokeSpeedAttack >> pokeSpeedDefense;
            
            // Create a new Pokémon instance based on the type and add it to the vector
            Pokemon* poke = nullptr;
            if (pokeType == "Fire") {
                poke = new CharmanderLine();
            } else if (pokeType == "Grass") {
                poke = new BulbasaurLine();
            } else if (pokeType == "Water") {
                poke = new SquirtleLine();
            } else if (pokeType == "Flying") {
                poke = new PidgeyLine();
            }

            if (poke) {
                poke->setName(pokeName);
                poke->heal(pokeHP - poke->checkHP()); // Adjust HP
                // Set other attributes here if needed
                pokes.push_back(poke);
            }
        }

        cout << "Game loaded successfully." << endl;
    } else {
        cout << "Could not open your saved game. Try again." << endl;
    }
    inFile.close();
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
       type_text("You won this battle!! :)");

    } else { // your pokemon is dead
        cout << "Enemy Won This Battle!!! :(" << endl;
    }
}

void Game::catchPidgey(){
    char choice; 
    player.getPokeballAmt();
       type_text("Do you want to try to catch this Pidgey? (Y/N)");
       cin >> choice; 

       if(tolower(choice) == 'y'){
        Pokemon *Pidgey = new PidgeyLine();
         player.useItem("Pokeball", Pidgey, pokes);
       }
       else{
        type_text("You've decided not to catch this pokemon.");
       }
}

void Game::catchBulbasaur(){
    char choice; 
    player.getPokeballAmt();
       type_text("Do you want to try to catch this Gym Owner's Bulbasaur? (Y/N)");
       cin >> choice; 

       if(tolower(choice) == 'y'){
        Pokemon *Bulbasaur = new BulbasaurLine();
         player.useItem("Pokeball", Bulbasaur, pokes);
       }
       else{
        type_text("You've decided not to catch this pokemon.");
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

    type_ascii("                 ⣀⣠⣤⣴⣶⣶⣶⣶⣶⣶⣶⣦⣤⣀⡀⠀⠀⠀⠀⠀");
    type_ascii("            ⣀⣤⣶⣿⡿⠿⠛⠛⠋⠉⠉⠉⠉⠉⠙⠛⠻⠿⣿⣿⣶⣤⡀⠀");
    type_ascii("    ⠀⠀⠀⢀⣴⣾⣿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠈⠙⠿⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀");
    type_ascii("     ⢀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠈⠙⢿⣿⣦⠀⠀⠀⠀⠀");
    type_ascii("   ⠀⣠⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀    ⠀⠻⣿⣷⡄⠀⠀⠀");
    type_ascii("  ⠀⣼⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀    ⠈⢿⣿⣆⠀⠀");
    type_ascii(" ⠀⣼⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀      ⠈⢿⣿⣆⠀");
    type_ascii(" ⢰⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀      ⠈⣿⣿⡄");
    type_ascii("⠀⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀      ⠸⣿⣧");
    type_ascii("⢸⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     ⠀⣿⣿");
    type_ascii("⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     ⠀⣿⣿");
    type_ascii("⢸⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     ⣠⣿⣿");
    type_ascii("⠈⣿⣿⣿⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⢀⣀⣤⣤⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     ⢀⣴⣿⣿⡿");
    type_ascii(" ⢻⣿⡿⢿⣿⣶⣄⡀⠀⠀⠀⠀⠀ ⢀⣴⣿⣿⠿⠟⠛⠿⢿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀  ⣀⣤⣶⣿⡿⣿⣿⡇");
    type_ascii("⠈ ⢿⣿⡄⠉⠛⠿⣿⣷⣶⣤⣤⣀⣠⣿⡿⠋⢠⠴⠒⠒⠲⢤⡈⠻⣿⣷⣀⣠⣤⣴⣶⣿⡿⠿⠋⠁    ⣰⣿⡟⠀");
    type_ascii("  ⠈⢿⣿⡄⠀⠀⠀⠈⠉⠛⠻⠿⣿⣿⡇⠀⡏⠀⠀⠀⠀  ⠈⡇⠀⢻⣿⡿⠿⠛⠛⠉⠁⠀  ⠀ ⠀⣰⣿⡟⠀⠀");
    type_ascii("   ⠈⢿⣿⣦⠀⠀⠀⠀⠀⠀ ⠀⢸⣿⣧⡀⠻⣄⡀⠀ ⣀⡴⠃⢠⣿⣿⠁⠀⠀⠀⠀⠀     ⢀⣼⣿⠟⠀⠀⠀");
    type_ascii("      ⠻⣿⣷⣄⡀⠀⠀⠀   ⠙⢿⣿⣦⣄⣉⣉⣁⣤⣶⣿⠿⠁⠀⠀       ⢀⣴⣿⡿⠋⠀⠀⠀⠀");
    type_ascii("     ⠀⠈⠻⣿⣿⣦⣀⠀ ⠀⠀⠀⠀⠉⠛⠿⠿⠿⠿⠟⠋⠁⠀⠀⠀⠀     ⠀⣠⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀");
    type_ascii("       ⠀⠀⠙⠻⢿⣿⣶⣤⣄⣀⠀⠀⠀⠀⠀⠀         ⢀⣀⣠⣤⣶⣿⡿⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀");
    type_ascii("          ⠀⠀⠈⠙⠻⠿⢿⣿⣿⣷⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⣿⣿⡿⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
    type_ascii("             ⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉                     ");

    type_text("Welcome to Pinewood Town, where your journey begins.");
    type_text("You are at Professor Maple's lab, where you just chose your first Pokemon. ", "Congrats!");
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
            starterPoke = new SquirtleLine();   //TODO
        }

        pokes.at(0) = starterPoke;

        type_text("Now then new trainer, your new chosen pokemon is: ", starterPoke->getName());
        type_text(". Is this correct?");
        cout << endl; 
        type_text("(Y/N): ");
        cin >> choice; 
    }




    type_text("Great choice! Take this Pokedex, and 3 pokeballs to start your journey. Your first challenge is to reach Fernleaf City and challenge the Gym Leader there.");
    player.addItem("Pokeball");
    player.addItem("Pokeball");
    player.addItem("Pokeball");
    part1Complete = true; // when game is reloaded, we will know which parts were completed based on bools for each part
}

void Game::part2() {
    char choice; 
    type_text("You step out of Professor Maple's lab and start your journey towards Fernleaf City.");
    type_text("As you walk through the tall grass, you encounter a wild Pidgey!");
    cout << endl; 
    
    type_text("Would you like to battle?(Y/N) (Hint: Battling gives you a chance to catch this Pokemon!): ");
    cin >> choice; 

    if(tolower(choice == 'y')){
        type_text("Your thrown into battle with the wild pidgey!!");
        cout << endl; 
        cout << endl; 
        type_text("..........ready.....set.......GO!");
        battle(); 
        catchPidgey(); 

        type_text("After the battle, you continue your journey and reach a small village. The battle and long journey gained you 30 XP!");
        player.gainXP(30);
    }
    else{
        type_text("You avoid the Pidgey and find Fernleaf City before nightfall!");
    }

    type_text("An old man approaches you.");

    type_text("Old Man: 'Hello there, young trainer! Take this Potion. It will heal your Pokemon in battle.'");
    player.addItem("Potion");

    type_text("You thank the old man and continue on your way.");

    part2Complete = true; 
}

void Game::part3() {
    type_text("You arrive at Fernleaf City and head to the local Pokemart to stock up on supplies.");
    type_text("You also learn that the Gym Leader here specializes in Grass-type Pokemon.");

    type_text("You head to the Fernleaf City Gym and challenge the Gym Leader, Flora.");
    type_text("Gym Leader Flora: 'Welcome, challenger! I hope you're ready to face my Grass-type Pokemon.'");
    cout << endl; 
    cout << endl; 
    type_text("..........ready.....set.......GO!");
    battle(); // Battle with Gym Leader Flora
    type_text("Impressive! You've earned the Leaf Badge for visiting this gym. Take this Potion as well. It can heal your pokemon.");
    if(pokes.at(0)->getName() == "Bulbasaur"){
        type_text("This leader battled you with a Bulbasaur Pokemon, which you already have! Because of your battle, your pokemon earned a lot of XP! Your Pokemon is about to evolve!! ");
        pokes.at(0)->evolve();
    }
    else{
        catchBulbasaur();
    }
    player.addItem("Potion");
    cout << "+1 Potion" << endl; 
    part3Complete = true; 
}

void Game::part4() {
    type_text("After defeating Flora, you meet a mysterious trainer outside the gym.");
    type_text("Mysterious Trainer: 'Great job defeating Flora! Here, take this Rare Candy as a reward. It will make your Pokemon much, much stronger.'");

    player.addItem("Rare Candy");

    char choice;
    type_text("Would you like to ask the mysterious trainer about the ancient Pokemon? (Y/N): ");
    cin >> choice;

    if (tolower(choice) == 'y') {
        type_text("Mysterious Trainer: 'I've heard rumors of an ancient Pokemon residing in the depths of Echo Cave. Maybe you should check it out.'");
    } else {
        type_text("Mysterious Trainer: 'Suit yourself. But remember, knowledge is power.'");
    }

    type_text("Your next destination is Echo Cave, to uncover the mysteries of the ancient Pokemon.");

    part4Complete = true;
}

void Game::part5() {
    type_text("You journey towards Echo Cave, ready for whatever challenges lie ahead.");
    type_text("As you enter the cave, you are confronted by Team Rocket!");

    cout << endl; 
    cout << endl; 
    type_text("..........ready.....set.......GO!");

    battle(); // Battle with Team Rocket

    type_text("After defeating Team Rocket, you delve deeper into the cave and find an ancient inscription.");

    type_text("The inscription tells the legend of a powerful Pokemon that can only be awakened by the pure of heart.");

    type_text("Determined to uncover the truth, you continue deeper into the cave.");

    part5Complete = true;
}

void Game::part6() {
    type_text("You reach the heart of Echo Cave and find the resting place of Mewtwo.");
    type_text("Mewtwo awakens and challenges you to a battle!");

    char choice; 
    type_text("Before this battle starts, would you like to use the Rare candy (Y/N)? (Hint: you should): ");
    cin >> choice; 

    if(tolower(choice == 'y')){
        
        string name = "x"; 
        while(true){ 
            type_text("Which Pokemon Would you like to use it on?(C - Charmander, B - Bulbasaur, S - Squirtle, P - Pidgey): ");
            cin >> choice; 

            if(tolower(choice == 'p')) {name == "Pidgey"; break;}
            else if(tolower(choice == 's')){name == "Squirtle"; break;}
            else if(tolower(choice == 'b')){name == "Bulbasaur"; break;}
            else if(tolower(choice == 'c')){name == "Charmander"; break;}
            else{
                type_text("Looks like you haven't chosen the options provided. Please make sure to enter a letter.");
                cout << endl; 
            }
        }

        int pokemonToEvolve = 0; 
        for(unsigned int i = 0; i< pokes.size(); ++i){
            if(pokes.at(i)->getName() == name){
                pokemonToEvolve = i; 
                break; 
            }
        }
        player.useItem("Rare Candy", pokes.at(pokemonToEvolve) , pokes);
    }
    type_text("OK. Now starting battle....");
    cout << endl; 
    cout << endl; 
    type_text("..........ready.....set.......GO!");
    battle(); // Battle with Mewtwo

    type_text("After a fierce battle, you've finally conquered Echo Cave.");
    type_text("With your new Pokemon by your side, you return to Fernleaf City, ready to go home.");

     part6Complete = true;
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

void type_ascii(const string& ascii){

    for (std::size_t i = 0; i < ascii.size(); ++i)
	{
		// output one character
		// flush to make sure the output is not delayed
		std::cout << ascii[i] << std::flush;
		
		// sleep 30 milliseconds
		usleep(100); // use Sleep on windows
	}

    cout << endl;
}
