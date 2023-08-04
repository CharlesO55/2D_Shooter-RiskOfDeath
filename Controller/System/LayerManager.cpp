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


//PART OF INITIALIZATION
//Marks the vector indices for sorting shootables
void LayerManager::findIndices(){
    bool bFoundFirstBlocker = false;
    int nIndex = 0;

    for (GameObject* pObject : *(this->vecGameObjectRef)){
        //FIND THE FIRST BLOCKER
        if (!bFoundFirstBlocker && pObject->getEntityType() == EntityType::BLOCKER){
            bFoundFirstBlocker = true;
            this->nIndexFirstBoulder = nIndex;
        }

        //FIND THE LAST ENEMY BEFORE ITEMS/BUFFS
        if (pObject->getEntityType() == EntityType::ENEMY){
            this->nIndexLastEnemy = nIndex;
        }

        //FIND THE LAST ITEM AND END OF ALL SHOOTABLES
        if (pObject->getEntityType() == EntityType::ITEM){
            this->nIndexLastItem = nIndex;
        }
        nIndex++;
    }

    this->itr_Start = this->vecGameObjectRef->begin() + this->nIndexFirstBoulder;
    this->itr_End = this->vecGameObjectRef->begin() + this->nIndexLastEnemy + 1;
}


void LayerManager::perform(){
    if (this->nTicks > 100){
        this->sortGameObjects();
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

    this->nTicks = 0;

    // GameObjectManager::getInstance()->printAllItemsDebug();
}

Shootable* LayerManager::getFrontmostHit(sf::Vector2f vecMouse){
    //SCAN THROUGH FROM THE LAST SHOOTABLE(items) TO THE FIRST SHOOTABLE (blockers)
    for (int i = nIndexLastItem; i > this->nIndexFirstBoulder; i--){
        //CHECK FIRST IF ACTIVE
        if (this->vecGameObjectRef->at(i)->isEnabled()){
            Shootable* pShootable = dynamic_cast <Shootable*> (this->vecGameObjectRef->at(i));        
            
            //CHECK IF COLLIDING WITH SHOOTABLE OBJECT
            if (pShootable->isVecInHitbox(vecMouse)){
                return pShootable;
            }
        }
    }

    //ALWAYS CHECK IF NULL IN CASE NO ITEM WAS SHOT    
    return NULL;
}

std::vector <Shootable*> LayerManager::getAllLineHit(sf::Vector2f vecMouse){
    std::vector <Shootable*> vecShot;
    //SCAN THROUGH FROM THE LAST SHOOTABLE(items) TO THE FIRST SHOOTABLE (blockers)
    for (int i = nIndexLastItem; i > this->nIndexFirstBoulder; i--){
        //CHECK FIRST IF ACTIVE
        if (this->vecGameObjectRef->at(i)->isEnabled()){
            Shootable* pShootable = dynamic_cast <Shootable*> (this->vecGameObjectRef->at(i));        
            
            //CHECK IF COLLIDING WITH SHOOTABLE OBJECT
            if (pShootable->isVecInHitbox(vecMouse)){
                vecShot.push_back(pShootable);
            }
        }
    }

    //ALWAYS CHECK IF NULL IN CASE NO ITEM WAS SHOT    
    return vecShot;
}



LayerManager* LayerManager::P_SHARED_INSTANCE = NULL;
LayerManager* LayerManager::getInstance(){
    if (P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new LayerManager();
    }
    return P_SHARED_INSTANCE;
}

LayerManager::LayerManager() : Component("Layer Manager", ComponentType::SCRIPT){}