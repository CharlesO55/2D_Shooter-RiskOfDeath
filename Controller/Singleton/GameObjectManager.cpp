#include "GameObjectManager.hpp"

using namespace controllers;

void GameObjectManager::processInput(sf::Event eEvent) {
    for(GameObject* pGameObject : this->vecGameObject) {
        if(pGameObject->isEnabled())
            pGameObject->processInput(eEvent);
    }
}

void GameObjectManager::update(sf::Time tDeltaTime) {
    for(GameObject* pGameObject : this->vecGameObject) {
        if(pGameObject->isEnabled() && !GameStateManager::getInstance()->isPaused()){
            pGameObject->update(tDeltaTime * GameStateManager::getInstance()->getGameSpeed());
        }
    }
}

void GameObjectManager::draw(sf::RenderWindow* pWindow) {
    for(GameObject* pGameObject : this->vecGameObject) {
        if(pGameObject->isEnabled())
            pGameObject->draw(pWindow, sf::RenderStates::Default);
    }
}

void GameObjectManager::addObject(GameObject* pGameObject) {
    this->vecGameObject.push_back(pGameObject);
    this->mapGameObject[pGameObject->getName()] = pGameObject;
    pGameObject->initialize();
}

void GameObjectManager::deleteObject(GameObject* pGameObject) {
    std::string strName = pGameObject->getName();
    int nIndex = -1;

    for(int i = 0; i < this->vecGameObject.size() && nIndex == -1; i++) {
        if(this->vecGameObject[i] == pGameObject)
            nIndex = i;
    }

    if(nIndex != -1) {
        this->vecGameObject.erase(this->vecGameObject.begin() + nIndex);
        this->mapGameObject.erase(this->vecGameObject[nIndex]->getName());
        delete pGameObject;
    }
}

void GameObjectManager::deleteObjectByName(std::string strName) {
    GameObject* pGameObject = this->findObjectByName(strName);
    if(pGameObject != NULL)
        this->deleteObject(pGameObject);
}


std::vector<GameObject*>* GameObjectManager::getVecObjectsRef(){
    return &this->vecGameObject;
}

/* 
using namespace interfaces;
struct {
    bool operator()(GameObject* a, GameObject* b) const { 
        Positionable* posA = dynamic_cast <Positionable*> (a);
        Positionable* posB = dynamic_cast <Positionable*> (b);
        //GREATER STARTS FROM FURTHEST BACK FIRST TO FRONT
        //THE NORMAL ORDER FOR RENDERING
        return posA->getScenePos().z > posB->getScenePos().z; 
    }
} sortZBackFirst; */

void GameObjectManager::printAllItemsDebug() {
    /*************************************************/
    /*ASSUMES THAT ENEMIES ARE CREATED AFTER BLOCKERS*/
    /*************************************************/

/*     bool bFoundBlockerStart = false;
    int nIndexFirstBlocker;
    int nIndexLastEnemy;
 */
    //SORT BETWEEN THE BLOCKERS AND ENEMIES
    int i = 0;

    for (GameObject* pObject : this->vecGameObject){
/*         
        //FIND THE FIRST BLOCKER
        if (!bFoundBlockerStart && (pObject->getEntityType() == EntityType::BLOCKER)){
            bFoundBlockerStart = true;
            nIndexFirstBlocker = i;
        }

        //FIND THE LAST ENEMY
        if (pObject->getEntityType() == EntityType::ENEMY){
            nIndexLastEnemy = i;
        }
 */
        std::cout << std::endl << i << pObject->getName();
        i++;
    }


/* 
    std::vector <GameObject*>::iterator itr_Start = vecGameObject.begin() + nIndexFirstBlocker;
    std::vector <GameObject*>::iterator itr_End   = vecGameObject.begin() + nIndexLastEnemy + 1;
    std::sort(itr_Start, itr_End, sortZBackFirst); */
}


/* * * * * * * [NEW CONTENT] * * * * * * */
/* A helper function that utilizes existing
 * [delete(...)] functions to delete ALL
 * [GameObjects] in the [vector] and [HashMap].
 * This is used by [SceneManager]. */
void GameObjectManager::deleteAllObjects() {
    std::vector<GameObject*> vecGameObject = this->vecGameObject;

    /* Iterate through your [vector] and
     * delete each [GameObject]. */
    for(GameObject* pGameObject : vecGameObject)
        this->deleteObject(pGameObject);

    /* Don't forget to CLEAR the stored 
     * pointers from your fields. */
    this->vecGameObject.clear();
    this->mapGameObject.clear();
}
/* * * * * * * * * * * * * * * * * * * * */

GameObject* GameObjectManager::findObjectByName(std::string strName) {
    if(this->mapGameObject[strName] != NULL)
        return this->mapGameObject[strName];

    else {
        std::cout << "[ERROR] : Object [" << strName << "] NOT found." << std::endl;
        return NULL;
    }
}

/* * * * * * * * * * * * * * * * * * * * *
 *       SINGLETON-RELATED CONTENT       *
 * * * * * * * * * * * * * * * * * * * * */
GameObjectManager* GameObjectManager::P_SHARED_INSTANCE = NULL;
GameObjectManager::GameObjectManager() {}
GameObjectManager::GameObjectManager(const GameObjectManager&) {}

GameObjectManager* GameObjectManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new GameObjectManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */
