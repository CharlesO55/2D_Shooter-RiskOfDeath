#include "PlayerManager.hpp"

using namespace systems;



int PlayerManager::getHealth()             {   return this->nHealth; }
std::string PlayerManager::getPlayerName() {   return this->strPlayerName; }

void PlayerManager::setPlayerName(std::string strPlayerName) {  this->strPlayerName = strPlayerName; }

void PlayerManager::changeHealthBy(int nChange){
    this->nHealth += nChange;
    this->nHealth = std::max(0, nHealth);
    this->nHealth = std::min(MAX_PLAYER_HEALTH, nHealth);

    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");
    if (nChange < 0){
        pUI->decrementHealth();
    }
    else {
        pUI->restoreHealth();
    }

    this->checkEndGame();
}

void PlayerManager::reset(){
    this->nHealth = MAX_PLAYER_HEALTH;
}

void PlayerManager::checkEndGame(){
    // #ifndef DISABLE_PLAYER_DEATH
    if (this->nHealth <= 0){
        std::cout << "\n[GAME OVER] Player died.";
        SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);
    }
    // #endif
}


PlayerManager* PlayerManager::P_SHARED_INSTANCE = NULL;

PlayerManager::PlayerManager() {}
PlayerManager* PlayerManager::getInstance(){
    if (P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new PlayerManager();
    }
    return P_SHARED_INSTANCE;
}