#include "ItemManager.hpp"

using namespace systems;

void ItemManager::obtain(sf::Vector2f vecLocation) {
    int nIndex = -1;
    GameObject* pOwner;
    
    for (int i = (this->vecObtainable.size()) - 1; i > -1 && nIndex == -1; i--) {
        pOwner = this->vecObtainable[i]->getOwner();

        if(!this->vecObtainable[i]->isObtained() && pOwner->isEnabled() && pOwner->getSprite()->getGlobalBounds().contains(vecLocation)) 
            nIndex = i;
    }

    if(nIndex != -1) {
        pOwner = this->vecObtainable[nIndex]->getOwner();
        this->vecObtainable[nIndex]->setObtained(true); //Adjust later on when applying the buff
    }
}

void ItemManager::perform() {
    this->fTime += this->tDeltaTime.asSeconds();

    Crosshair* pCrosshair = (Crosshair*)GameObjectManager::getInstance()->findObjectByName("Crosshair");
    if(pCrosshair == NULL) 
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    
    else {
        CrosshairMouseInput* pCrosshairMouseInput = (CrosshairMouseInput*)pCrosshair->findComponentByName("Crosshair Mouse Input");
        
        if(pCrosshairMouseInput == NULL)
            std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
        
        else {
            if(pCrosshairMouseInput->isLeftClick()) { //Not registering
                this->obtain(pCrosshairMouseInput->getLocation());
                pCrosshairMouseInput->resetLeftClick();
            }
        }
    }

    //Adjust spawning. Make it in line with the killables, so that when they are killed, spawn according to chance
    //DISABLED FOR NOW, determining hte cause of isLeftClick() not registering
    // if (this->fTime > 1.0f) {
    //     this->fTime = 0.0f;
    //     PoolTag ETag = this->getRandomPool();
    //     ObjectPoolManager::getInstance()->getPool(ETag)->requestPoolable();
    // }
}

PoolTag ItemManager::getRandomPool() {
    int nPool = (std::rand() % 3) + 1; //Adjust later when other powerups are introduced

    if (nPool == 1)
        return PoolTag::HEALTH_BOOST;

    else if (nPool == 2)
        return PoolTag::DAMAGE_BOOST;

    else if (nPool == 3)
        return PoolTag::PIERCING_SHOT;

    else if (nPool == 4)
        return PoolTag::INFINITY_AMMO;

    else if (nPool == 5)
        return PoolTag::NUKE;

    else
        return PoolTag::NONE;
}

void ItemManager::registerComponent(Obtainable* pObtainable) {
    this->vecObtainable.push_back(pObtainable);
}

void ItemManager::unregisterComponent(Obtainable* pObtainable) {
    int nIndex = -1;

    for(int i = 0; i < this->vecObtainable.size() && nIndex == -1; i++) 
        if(this->vecObtainable[i] == pObtainable)
            nIndex = i;

    if(nIndex != -1) 
        this->vecObtainable.erase(this->vecObtainable.begin() + nIndex);  
}

ItemManager* ItemManager::P_SHARED_INSTANCE = NULL;
ItemManager::ItemManager(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
ItemManager::ItemManager(const ItemManager& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

ItemManager* ItemManager::getInstance() {
    return P_SHARED_INSTANCE;
}

void ItemManager::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new ItemManager(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}