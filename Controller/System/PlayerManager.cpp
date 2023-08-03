#include "PlayerManager.hpp"

using namespace systems;

void PlayerManager::perform() {
    if (this->bReloading) 
        this->reload(this->tDeltaTime.asSeconds());

    this->checkEndGame();
}

void PlayerManager::reload(float fTime){
    this->fTicks += fTime;
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");

    if (this->fTicks > 1.0f) {
        this->bReloading = false;

        this->fTicks = 0.0f;
        pUI->reloadBullets();
    }
}

void PlayerManager::checkEndGame(){
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");

    if (pUI->getHealth() <= 0){
        std::cout << "\n[GAME OVER] Player died.";
        SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);
    }
}

void PlayerManager::setPlayerName(std::string strPlayerName) { this->strPlayerName = strPlayerName; }

void PlayerManager::healPlayer() { 
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");
    pUI->restoreHealth(); 
}

void PlayerManager::damagePlayer() { 
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");
    pUI->decrementHealth(); 
}

void PlayerManager::setReloading(bool bState) { this->bReloading = bState; }

int PlayerManager::getHealth() { return this->nHealth; }

std::string PlayerManager::getPlayerName() { return this->strPlayerName; }

PlayerManager* PlayerManager::P_SHARED_INSTANCE = NULL;
PlayerManager::PlayerManager(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
PlayerManager::PlayerManager(const PlayerManager& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

PlayerManager* PlayerManager::getInstance() {
    return P_SHARED_INSTANCE;
}

void PlayerManager::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new PlayerManager(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}