#include "Game.h"

Game::Game() : player("", ' ') {
    isNewGame = true;
}

void Game::saveGame(string saveFileName) {

}

void Game::loadGame(string loadFileName) {
    cout << "Loading a save file does nothing at the moment." << endl;
    cout << "Starting a new game." << endl << endl;
}