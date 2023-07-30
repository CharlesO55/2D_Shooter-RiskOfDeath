#include "EnemyManager.hpp"

using namespace systems;

void EnemyManager::kill(sf::Vector2f vecLocation) {
    int nIndex = -1;
    GameObject* pTarget;
    
    if (ItemManager::getInstance()->isItemActive(ItemType::PIERCING_SHOT)) {
        for (int i = 0; i < vecKillable.size(); i++) {
            pTarget = this->vecKillable[i]->getOwner();

            if(!this->vecKillable[i]->isKilled() && pTarget->isEnabled() && this->isLocInSprite(pTarget, vecLocation))
                this->vecKillable[i]->setKilled(true);
        }
    }

    else {
        for (int i = (this->vecKillable.size()) - 1; i > -1 && nIndex == -1; i--) {
            pTarget = this->vecKillable[i]->getOwner();

            if(!this->vecKillable[i]->isKilled() && pTarget->isEnabled() && this->isLocInSprite(pTarget, vecLocation))
                nIndex = i;
        }

        if(nIndex != -1) {
            pTarget = this->vecKillable[nIndex]->getOwner();
            this->vecKillable[nIndex]->setKilled(true);
        }
    }
}

bool EnemyManager::isLocInSprite(GameObject* pTarget, sf::Vector2f vecLocation){
    //CONVERT THE SPRITE TO MATCH FRONT VIEW ZOOM 
    if (ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->isEnabled()){
        sf::FloatRect CInitialBounds = pTarget->getSprite()->getGlobalBounds();
        sf::Transform CViewTransform = ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite()->getTransform();
        sf::FloatRect CFinalBounds = CViewTransform.transformRect(CInitialBounds);

        return CFinalBounds.contains(vecLocation);
    }

    return false;
}


void EnemyManager::perform() {
    this->fTime += this->tDeltaTime.asSeconds();

    Crosshair* pCrosshair = (Crosshair*)GameObjectManager::getInstance()->findObjectByName("Crosshair");
    if(pCrosshair == NULL) 
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    
    else {
        CrosshairMouseInput* pCrosshairMouseInput = (CrosshairMouseInput*)pCrosshair->findComponentByName("Crosshair Mouse Input");
        
        if(pCrosshairMouseInput == NULL)
            std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
        
        else {
            if(pCrosshairMouseInput->isLeftClick()) {
                std::cout << "[EnemyManager] : Left Click Detected" << std::endl;
                this->kill(pCrosshairMouseInput->getLocation());
                //pCrosshairMouseInput->resetLeftClick();
            }
        }
    }

    //This spawns a wave of enemies for every 8 seconds.
    if (this->fTime > 0.3f) { //Adjust later, spawn set to this for testing
        this->fTime = 0.0f;

        //This spawns the wave. Replace with the formula for enemy count per wave.
        for (int i = 0; i < DEFAULT_WAVE_AMOUNT; i++) {
            PoolTag ETag = this->getRandomPool();
            ObjectPoolManager::getInstance()->getPool(ETag)->requestPoolable();
        }
    }
}

//Modify once waves are implemented.
PoolTag EnemyManager::getRandomPool() {
    int nPool = (std::rand() % 3) + 1;

    if (nPool == 1)
        return PoolTag::SLIME;

    else if (nPool == 2)
        return PoolTag::BAT;

    else if (nPool == 3)
        return PoolTag::GHOST;

    else
        return PoolTag::NONE;
}

void EnemyManager::registerComponent(Killable* pKillable) {
    this->vecKillable.push_back(pKillable);
}

void EnemyManager::unregisterComponent(Killable* pKillable) {
    int nIndex = -1;

    for(int i = 0; i < this->vecKillable.size() && nIndex == -1; i++) 
        if(this->vecKillable[i] == pKillable)
            nIndex = i;

    if(nIndex != -1) 
        this->vecKillable.erase(this->vecKillable.begin() + nIndex);  
}

EnemyManager* EnemyManager::P_SHARED_INSTANCE = NULL;
EnemyManager::EnemyManager(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
EnemyManager::EnemyManager(const EnemyManager& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

EnemyManager* EnemyManager::getInstance() {
    return P_SHARED_INSTANCE;
}

void EnemyManager::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new EnemyManager(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}