#include "PlayerManager.hpp"

using namespace systems;
using namespace controllers;
using namespace interfaces;

void PlayerManager::perform() {
    if(pCrosshairRef == NULL){
        this->findDependencies();
    }
    
    if (this->bReloading) 
        this->reload(this->tDeltaTime.asSeconds());

    else if (this->pCrosshairRef->isLeftClick()){
        this->shoot();
    }

    this->checkEndGame();
}

void PlayerManager::shoot(){
    this->pCrosshairRef->resetLeftClick();

    //CHECK AND UPDATE THE BULLETS WHEN NOT INFINITE
    if (!ItemManager::getInstance()->isItemActive(ItemType::INFINITY_AMMO)){
        if (this->isAmmoEmpty()){
                //STOP WHEN CAN'T EVEN SHOOT
                return;
            }
    }    
    
    //SORT FIRST
    LayerManager::getInstance()->sortGameObjects();

    //LOOK FOR OBJECTS THAT WERE SHOT
    std::vector <Shootable*> vecShootables;
    //GET ALL SHOOTABLES THAT CAN BE SHOT IN A LINE
    if (ItemManager::getInstance()->isItemActive(ItemType::PIERCING_SHOT)){
        std::cout << "\n[Pierce]";
        vecShootables = LayerManager::getInstance()->getAllLineHit(pCrosshairRef->getLocation());
    }
    //GET SINGLE FRONT MOST
    else{
        std::cout << "\n[Single]";
        vecShootables.push_back(LayerManager::getInstance()->getFrontmostHit(pCrosshairRef->getLocation()));
    }


    //TRIGGER ALL THAT WERE SHOT
    for (Shootable* pShot : vecShootables){
        if (pShot == NULL){
            return;
        }
        pShot->onShot();
    }
}

bool PlayerManager::isAmmoEmpty(){
    this->nBullets--;
    this->pUI_Ref->decrementBullets(); 

    if(this->nBullets <= 0){
        SFXManager::getInstance()->getSound(SFXType::NO_AMMO)->play();

        if ((std::rand() % 5) == 2){
            SFXManager::getInstance()->getSound(SFXType::V_NO_AMMO)->play();
        } 
        return true;
    }
    return false;
}



void PlayerManager::findDependencies(){
    //CROSSHAIR
    Crosshair* pCrosshair = (Crosshair*)GameObjectManager::getInstance()->findObjectByName("Crosshair");
    if (pCrosshair == NULL){
        std::cout << "[ERROR] : Crosshair holder missing." << std::endl;
        throw 0;
    }

    CrosshairMouseInput* pCrosshairMouseInput = (CrosshairMouseInput*)pCrosshair->findComponentByName("Crosshair Mouse Input");
    if(pCrosshairMouseInput == NULL){
        std::cout << "[ERROR] : Crosshair input component missing." << std::endl;
        throw 0;
    }
    this->pCrosshairRef = pCrosshairMouseInput;


    //PLAYER UI
    this->pUI_Ref = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");

    //RELOAD IN CASE
    this->reload(1);
}

void PlayerManager::reload(float fTime){
    this->nBullets = 5 * ViewManager::getInstance()->getScreenCols() * ViewManager::getInstance()->getScreenRows();

    this->fTicks += fTime;
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");

    //CHECK RELOAD COOLDOWN OF 1s
    if (this->fTicks > 1.0f) {
        this->bReloading = false;

        this->fTicks = 0.0f;
        pUI->reloadBullets();
        SFXManager::getInstance()->getSound(SFXType::RELOAD)->play();
    }
}

void PlayerManager::checkEndGame(){
    #ifndef DISABLE_PLAYER_DEATH
    if (this->nHealth <= 0){
        std::cout << "\n[GAME OVER] Player died.";
        SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);
    }
    #endif
}

void PlayerManager::setPlayerName(std::string strPlayerName) { this->strPlayerName = strPlayerName; }

void PlayerManager::healPlayer() { 
    this->nHealth++;
    int nRestoredHealth = (std::rand() % 3) + 1;

    // PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");
    this->pUI_Ref->restoreHealth(nRestoredHealth); 

    SFXManager::getInstance()->getSound(SFXType::HEAL_PLAYER)->play();
}

void PlayerManager::damagePlayer() { 
    this->nHealth--;
    
    // PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");
    this->pUI_Ref->decrementHealth(); 

    SFXManager::getInstance()->getSound(SFXType::PLAYER_HIT)->play();
}

int PlayerManager::getBullets() {
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");

    return pUI->getBullets();
}

bool PlayerManager::isReloading() {
    return this->bReloading;
}

void PlayerManager::setReloading(bool bState) { this->bReloading = bState; }

int PlayerManager::getHealth() { return this->nHealth; }
std::string PlayerManager::getPlayerName() { return this->strPlayerName; }




/**************************
*     SINGLETON STUFF     *
**************************/

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