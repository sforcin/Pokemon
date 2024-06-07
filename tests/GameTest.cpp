#include <gtest/gtest.h>
#include <fstream>
#include "../includeFiles/Game.h"
#include "../includeFiles/Pokemon.h"
#include "../includeFiles/Display.h"
#include "../includeFiles/Player.h"

//check for constructor, save, load files

//constructor test
TEST(GameTest, ConstructorTest) {
    Game game;
    EXPECT_TRUE(game.isNewGame); //assuming all parts of game havent been completed yet
    EXPECT_FALSE(game.part1Complete);
    EXPECT_FALSE(game.part2Complete);
    EXPECT_FALSE(game.part3Complete);
    EXPECT_FALSE(game.part4Complete);
    EXPECT_FALSE(game.part5Complete);
    EXPECT_FALSE(game.part6Complete);
    EXPECT_EQ(game.player.getName(), ""); //using getname, was failing bc wasnt empty
    EXPECT_EQ(game.player.getXP(), 0); // using getXp from player class
    //EXPECT_EQ(game.player.getHP(), 3 * 1 + 100); // 
}
 
// test save game function
TEST(GameTest, SaveGameTest) {
    Game game; //create new game (constructor)
    std::string filename = "test_save_game.txt"; //create new filename


    game.player = Player("User", 'x');
    game.player.gainXP(150); 
    game.player.addItem("Potion");

    game.saveGame(filename); //save the game with chosen file name

    //now we check if the file is created
    std::ifstream infile(filename);
    ASSERT_TRUE(infile.good()); //make sure the file is good()

    std::string line;
    std::getline(infile, line); //check content of the file
    EXPECT_EQ(line, "Player name: User");
    std::getline(infile, line);
    EXPECT_EQ(line, "Player XP: 150");
    std::getline(infile, line);
    EXPECT_EQ(line, "Player HP: 106");

    // close the file and remove it.
    infile.close();
    std::remove(filename.c_str());
}
//testing loadfile
TEST(GameTest, LoadFileTest){

}