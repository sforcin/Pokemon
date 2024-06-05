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
    Player player("Ash", 'M');
    player.addItem("Pokeball");
    testing::internal::CaptureStdout();
    player.getPokeballAmt();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("You have 1 Pokeballs.") != std::string::npos);
}

TEST(PlayerTest, GainXPTest) {
    Player player("Ash", 'M');
    player.gainXP(50);
    EXPECT_EQ(player.getXP(), 50);
    EXPECT_EQ(player.getHP(), 103);  //shouldnt change

    player.gainXP(60);  // should level up
    EXPECT_EQ(player.getXP(), 110);
    EXPECT_EQ(player.getHP(), 106);  
}

TEST(PlayerTest, RemoveItemTest) {
    Player player("Ash", 'M');
    player.addItem("Potion");
    EXPECT_TRUE(player.removeItem("Potion"));
    EXPECT_FALSE(player.removeItem("Potion"));  // shouldnt work
}

TEST(PlayerTest, GetPotionAmtTest) {
    Player player("Ash", 'M');
    player.addItem("Potion");
    player.addItem("Potion");
    testing::internal::CaptureStdout();
    player.getPotionAmt();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("You have 2 Potions.") != std::string::npos);
}

TEST(PlayerTest, GetXPTest) {
    Player player("Ash", 'M');
    player.gainXP(25);
    EXPECT_EQ(player.getXP(), 25);
}


TEST(PlayerTest, GetHPTest) {
    Player player("Ash", 'M');
    EXPECT_EQ(player.getHP(), 103);  
}


TEST(PlayerTest, CheckLevelTest) {
    Player player("Ash", 'M');
    player.gainXP(200);  
    EXPECT_EQ(player.getXP(), 200);
    EXPECT_EQ(player.getHP(), 109);  
}

