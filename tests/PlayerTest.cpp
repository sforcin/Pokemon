#include <gtest/gtest.h>
#include "../includeFiles/Game.h"
#include "../includeFiles/Pokemon.h"
#include "../includeFiles/Display.h"
#include "../includeFiles/Player.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

TEST(PlayerTest, AddItemTest) {
    Player player("user", 'x'); // initialize player
    player.addItem("Pokeball"); // Add an item to inventory 
    int pokeballCount = player.getItemCount("Pokeball"); // Get the count of Pokeballs
    EXPECT_EQ(pokeballCount, 1); //passed.
}

TEST(PlayerTest, GainXPTest) {
    Player player("user", 'x');
    player.gainXP(50);
    EXPECT_EQ(player.getXP(), 50);
   // EXPECT_EQ(player.getHP(), 103); 

    player.gainXP(60);  // should level up
    EXPECT_EQ(player.getXP(), 110);
    //EXPECT_EQ(player.getHP(), 106);  
} //this isnt passing. nvm is passing now

TEST(PlayerTest, RemoveItemTest) {
    Player player("user", 'x'); //initialzie class 
    player.addItem("Potion"); //add an item to inventory
    EXPECT_TRUE(player.removeItem("Potion")); 
    EXPECT_FALSE(player.removeItem("Potion"));  // shouldnt work
} //shoudl output that its not in inventory, since its removed. completed 


TEST(PlayerTest, GetXPTest) {
    Player player("user", 'x');
    player.gainXP(25);
    EXPECT_EQ(player.getXP(), 25);
}
// simple test, passing

// TEST(PlayerTest, GetHPTest) { no longer exists
//     Player player("user", 'x');
//     EXPECT_EQ(player.getHP(), 103);  
// } //passing as well


TEST(PlayerTest, CheckLevelTest) {
    Player player("user", 'x');
    player.gainXP(200);    //gain 200 xp
    EXPECT_EQ(player.getXP(), 200); 
   // EXPECT_EQ(player.getHP(), 109);  
}
//passing

//done with player class
