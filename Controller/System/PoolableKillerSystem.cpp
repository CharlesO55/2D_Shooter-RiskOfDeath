#include "PoolableKillerSystem.hpp"

using namespace systems;

void PoolableKillerSystem::kill(sf::Vector2f vecLocation) {
    int nIndex = -1;
    GameObject* pOwner;
    
    for (int i = (this->vecKillable.size()) - 1; i > -1 && nIndex == -1; i--) {
        pOwner = this->vecKillable[i]->getOwner();

        if(!this->vecKillable[i]->isKilled() && pOwner->isEnabled() && pOwner->getSprite()->getGlobalBounds().contains(vecLocation)) 
            nIndex = i;
    }

    if(nIndex != -1) {
        pOwner = this->vecKillable[nIndex]->getOwner();
        this->vecKillable[nIndex]->setKilled(true);
    }
}

void PoolableKillerSystem::perform() {
    Crosshair* pCrosshair = (Crosshair*)GameObjectManager::getInstance()->findObjectByName("Crosshair");
    if(pCrosshair == NULL) 
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    
    else {
        CrosshairMouseInput* pCrosshairMouseInput = (CrosshairMouseInput*)pCrosshair->findComponentByName("Crosshair Mouse Input");
        
        if(pCrosshairMouseInput == NULL)
            std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
        
        else {
            if(pCrosshairMouseInput->isLeftClick()) {
                this->kill(pCrosshairMouseInput->getLocation());
                pCrosshairMouseInput->resetLeftClick();
            }
        }
    }
}

void PoolableKillerSystem::registerComponent(Killable* pKillable) {
    this->vecKillable.push_back(pKillable);
}

void PoolableKillerSystem::unregisterComponent(Killable* pKillable) {
    int nIndex = -1;

    for(int i = 0; i < this->vecKillable.size() && nIndex == -1; i++) {
        if(this->vecKillable[i] == pKillable)
            nIndex = i;
    }

    if(nIndex != -1) {
        this->vecKillable.erase(this->vecKillable.begin() + nIndex);
    }
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
PoolableKillerSystem* PoolableKillerSystem::P_SHARED_INSTANCE = NULL;
PoolableKillerSystem::PoolableKillerSystem(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
PoolableKillerSystem::PoolableKillerSystem(const PoolableKillerSystem& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

PoolableKillerSystem* PoolableKillerSystem::getInstance() {
    return P_SHARED_INSTANCE;
}

void PoolableKillerSystem::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new PoolableKillerSystem(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}
/* * * * * * * * * * * * * * * * * * * * */
