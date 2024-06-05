#include <gtest/gtest.h>
#include <fstream>
#include "../includeFiles/Game.h"
#include "../includeFiles/Pokemon.h"
#include "../includeFiles/Display.h"
#include "../includeFiles/Player.h"

//ill fix this tmrr
// TEST(GameTest, LoadGameTest) {
//     Game game;
//     testing::internal::CaptureStdout();
//     game.loadGame("some_file.txt");
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_TRUE(output.find("Loading a save file does nothing at the moment.") != std::string::npos);
//     EXPECT_TRUE(output.find("Starting a new game.") != std::string::npos);
// }

// TEST(GameTest, ConstructorTest) {
//     Game game;
//     EXPECT_TRUE(game.isNewGame);
// }