#include "GameObjectManager.hpp"

using namespace singletons;

void GameObjectManager::registerObject(GameObject* pObject){
    this->vecObjects.push_back(pObject);
    this->mapObjects[pObject->strName] = pObject;
    pObject->initialize();
}

void GameObjectManager::deleteObject(GameObject* pObject){
    auto it = std::find(this->vecObjects.begin(), this->vecObjects.end(), pObject);

    if(it != this->vecObjects.end()){        
        this->mapObjects.erase(pObject->strName);
        this->vecObjects.erase(it);
    }
}

void GameObjectManager::deleteAllObjects(){
    for (GameObject* pCur : this->vecObjects){
        this->deleteObject(pCur);
    }

    this->vecObjects.clear();
    this->mapObjects.clear();
}



void GameObjectManager::listenObjects(sf::Event EEvent){

}

void GameObjectManager::updateObjects(sf::Time CTime){
    for (GameObject* pObject : this->vecObjects){
        pObject->update(CTime);
        for (GameObject* pChild : pObject->getChildren()){
            pChild->update(CTime);
        }
    }
}

void GameObjectManager::drawObjects(sf::RenderWindow *pWindow){
    for (GameObject* pObject : this->vecObjects){
        if (pObject->isEnabled()){
            pObject->draw(pWindow);
        }
    }
}








GameObjectManager* GameObjectManager::P_SHARED_INSTANCE = NULL;

GameObjectManager* GameObjectManager::getInstance(){
    if (P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new GameObjectManager;
    }
    return P_SHARED_INSTANCE;
}