#include "GameStateManager.hpp"

using namespace controllers;

void GameStateManager::pause() {
    ViewManager::getInstance()->getView(ViewTag::PAUSE_SCREEN)->setEnabled(true);
    ViewManager::getInstance()->getView(ViewTag::PLAYER_UI)->setEnabled(false);
    this->EState = GameState::PAUSED;
}

void GameStateManager::resume() {
    ViewManager::getInstance()->getView(ViewTag::PAUSE_SCREEN)->setEnabled(false);
    ViewManager::getInstance()->getView(ViewTag::PLAYER_UI)->setEnabled(true);

    this->EState = GameState::RUNNING;
}

void GameStateManager::closeGame() {
    this->EState = GameState::CLOSE;
}

bool GameStateManager::isPaused() {
    return this->EState == GameState::PAUSED;
}

bool GameStateManager::isGameClose() {
    return this->EState == GameState::CLOSE;
}

void GameStateManager::reset() {
    this->EState = GameState::RUNNING;
    this->fGameSpeed = DEFAULT_GAME_SPEED;
}


float GameStateManager::getGameSpeed()              {return this->fGameSpeed; }
void GameStateManager::setGameSpeed(float fSpeed)   {this->fGameSpeed = fSpeed;}


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
