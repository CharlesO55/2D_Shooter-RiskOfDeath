#include "LayerManager.hpp"

using namespace systems;
using namespace components;
using namespace controllers;
using namespace interfaces;


//SORTING TOOLS FOR RENDERING

        //GREATER STARTS FROM FURTHEST BACK FIRST TO FRONT
struct { bool operator()(GameObject* a, GameObject* b) const { 
        Positionable* posA = dynamic_cast <Positionable*> (a);
        Positionable* posB = dynamic_cast <Positionable*> (b);
        return posA->getScenePos().z > posB->getScenePos().z; 
    }
} sortZBackFirst;


        //LESSER STARTS FROM FURTHEST LEFT FIRST TO RIGHT
struct { bool operator()(GameObject* a, GameObject* b) const { 
        Positionable* posA = dynamic_cast <Positionable*> (a);
        Positionable* posB = dynamic_cast <Positionable*> (b);
        return posA->getScenePos().x < posB->getScenePos().x; 
    }
} sortXLeftFirst;


void LayerManager::initialize(){
    this->vecGameObjectRef = GameObjectManager::getInstance()->getVecObjectsRef();
    this->findIndices();
}

void LayerManager::findIndices(){
    bool bFoundFirstBlocker = false;
    int nIndex = 0;
    int nLastEnemy;

    for (GameObject* pObject : *(this->vecGameObjectRef)){
        //FIND THE FIRST BLOCKER
        if (!bFoundFirstBlocker && pObject->getEntityType() == EntityType::BLOCKER){
            bFoundFirstBlocker = true;
            this->itr_Start = this->vecGameObjectRef->begin() + nIndex;
        }

        //FIND THE LAST ENEMY BEFORE ITEMS/BUFFS
        if (pObject->getEntityType() == EntityType::ENEMY){
            nLastEnemy = nIndex;
        }
        nIndex++;
    }
    this->itr_End = this->vecGameObjectRef->begin() + nLastEnemy + 1;
}


void LayerManager::perform(){
    if (this->nTicks > 100){
        this->sortGameObjects();
        nTicks = 0;
    }
    nTicks++;
}

void LayerManager::sortGameObjects(){
    if (ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->isEnabled()){
        std::sort(itr_Start, itr_End, sortZBackFirst);
    }
    else if (ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->isEnabled()){
        std::sort(itr_Start, itr_End, sortXLeftFirst);
    }
    // GameObjectManager::getInstance()->printAllItemsDebug();
}




LayerManager* LayerManager::P_SHARED_INSTANCE = NULL;
LayerManager* LayerManager::getInstance(){
    if (P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new LayerManager();
    }
    return P_SHARED_INSTANCE;
}

LayerManager::LayerManager() : Component("Layer Manager", ComponentType::SCRIPT){}