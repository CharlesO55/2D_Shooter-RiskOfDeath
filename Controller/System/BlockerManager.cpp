#include "BlockerManager.hpp"

using namespace components;
using namespace systems;
using namespace models;

void BlockerManager::perform(){}

void BlockerManager::registerBlocker(BaseBlocker* pBlocker){
    this->vecBlockers.push_back(pBlocker);
}

void BlockerManager::unregisterAll(){
    for(BaseBlocker* pBlocker : this->vecBlockers)
        controllers::GameObjectManager::getInstance()->deleteObject(pBlocker);

    this->vecBlockers.clear();
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
