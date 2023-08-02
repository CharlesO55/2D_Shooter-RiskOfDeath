#include "BlockerManager.hpp"

using namespace components;
using namespace systems;
using namespace models;


void BlockerManager::perform(){
    this->findCrosshairRef();

    if (!pCrosshairRef->isLeftClick()){
        return;
    }

    for (BaseBlocker* pBlocker : this->vecBlockers){
        if (pBlocker->isColliding(this->pCrosshairRef->getLocation())){
            std::cout << "\n[BLOCKER HIT] " << pBlocker->getName();
            this->pCrosshairRef->resetLeftClick();
            break;
        }
    }

    //ONLY RESET WHEN NO OTHER MANAGERS NEED LEFT CLICK READING
    this->pCrosshairRef->resetLeftClick();
}

void BlockerManager::registerBlocker(BaseBlocker* pBlocker){
    this->vecBlockers.push_back(pBlocker);
}

void BlockerManager::unregisterAll(){
    for(BaseBlocker* pBlocker : this->vecBlockers){
        controllers::GameObjectManager::getInstance()->deleteObject(pBlocker);
    }

    this->vecBlockers.clear();
}



//SET UP

void BlockerManager::findCrosshairRef(){
    Crosshair* pCrosshair = (Crosshair*)GameObjectManager::getInstance()->findObjectByName("Crosshair");
    if (pCrosshair == NULL){
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
        throw 0;
    }

    CrosshairMouseInput* pCrosshairMouseInput = (CrosshairMouseInput*)pCrosshair->findComponentByName("Crosshair Mouse Input");
    if(pCrosshairMouseInput == NULL){
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
        throw 0;
    }
    this->pCrosshairRef = pCrosshairMouseInput;
}


void BlockerManager::initialize(std::string strName, GameObject* pHolder){
    P_SHARED_INSTANCE = new BlockerManager(strName);
    pHolder->attachComponent(P_SHARED_INSTANCE);
}

BlockerManager* BlockerManager::P_SHARED_INSTANCE = NULL;
BlockerManager::BlockerManager(std::string strName) : Component("Blocker Manager", ComponentType::SCRIPT){}   

BlockerManager* BlockerManager::getInstance(){
    if (P_SHARED_INSTANCE == NULL){
        std::cout << "\n[ERROR] BLOCKER MANAGER IS NOT INITIALIZED";
        throw 0;
    } 
    return P_SHARED_INSTANCE;
}
