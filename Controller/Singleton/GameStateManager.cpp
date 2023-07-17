#include "GameStateManager.hpp"

using namespace controllers;

void GameStateManager::pause() {
    this->EState = GameState::PAUSED;
}

void GameStateManager::resume() {
    this->EState = GameState::RUNNING;
}

bool GameStateManager::isPaused() {
    return this->EState == GameState::PAUSED;
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
GameStateManager* GameStateManager::P_SHARED_INSTANCE = NULL;
GameStateManager::GameStateManager() {}
GameStateManager::GameStateManager(const GameStateManager&) {}

GameStateManager* GameStateManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new GameStateManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */
