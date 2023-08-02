#include "GameObjectPool.hpp"

using namespace controllers;

GameObjectPool::GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference, GameObject* pParent) {
    this->ETag = ETag;
    this->nPoolSize = nPoolSize;
    this->pPoolableReference = pPoolableReference;
    this->pParent = pParent;

    this->vecAvailableObject = {};
    this->vecUsedObject = {};
}

void GameObjectPool::initialize() {
    /* Create [this->nPoolSize] PoolableObject* instances and store them in [this->vecAvailableObject]. */

    PoolableObject* pPoolableObject;
    
    for(int i = 0; i < this->nPoolSize; i++) {
        pPoolableObject = this->pPoolableReference->clone();

        /* Attach the object to [this->pParent], if applicable. */
        if(this->pParent != NULL)
            this->pParent->attachChild(pPoolableObject);
        else
            GameObjectManager::getInstance()->addObject(pPoolableObject);
        
        /* Instantiate the object, but disable it. */
        pPoolableObject->setEnabled(false);
        this->vecAvailableObject.push_back(pPoolableObject);
    }
}

PoolableObject* GameObjectPool::requestPoolable() {
    PoolableObject* pPoolableObject = NULL;

    if(this->hasAvailable(1)) {
        /* Retrieve one available object, then update [this->vecAvailableObject] and [this->vecUsedObject] accordingly. */
        pPoolableObject = this->vecAvailableObject[0];
        this->vecUsedObject.push_back(pPoolableObject);
        this->vecAvailableObject.erase(this->vecAvailableObject.begin());

        /* Enable the requested object. */
        this->setEnabled(pPoolableObject, true);
    }
    else{
        #ifndef DISABLE_POOLABLE_WARNINGS
        std::cout << "[ERROR] : GameObjectPool::requestPoolable() FAILED due to no available objects." << std::endl;
        #endif
    }

    return pPoolableObject;
}

std::vector<PoolableObject*> GameObjectPool::requestPoolableBatch(int nRequestSize) {
    std::vector<PoolableObject*> vecPoolableBatch = {};

    if(this->hasAvailable(nRequestSize)) {
        for(int i = 0; i < nRequestSize; i++)
            vecPoolableBatch.push_back(this->requestPoolable());
    }
    else
        std::cout << "[ERROR] : Not enough poolable objects. REQUESTED : " << nRequestSize << " | AVAILABLE : " << this->vecAvailableObject.size() << std::endl;

    return vecPoolableBatch;
}

void GameObjectPool::releasePoolable(PoolableObject* pPoolableObject) {
    int nIndex = -1;

    /* Check if pPoolableObject is in [this->vecUsedObject]. Technically, this is
       an optional step, especially if you yourself ensured that [pPoolableObject]
       can always be found in [this->vecUsedObject]. */
    for(int i = 0; i < this->vecUsedObject.size() && nIndex == -1; i++) {
        if(this->vecUsedObject[i] == pPoolableObject)
            nIndex = i;
    }

    if(nIndex != -1) {
        /* Add [pPoolableObject] to [this->vecAvailableObject]. */
        this->vecAvailableObject.push_back(pPoolableObject);

        /* Erase [pPoolableObject] from [this->vecUsedObject]. */
        this->vecUsedObject.erase(this->vecUsedObject.begin() + nIndex);

        /* Disable the returned object. */
        this->setEnabled(pPoolableObject, false);
    }
}

void GameObjectPool::releasePoolableBatch(std::vector<PoolableObject*> vecPoolableObject) {
    /* [TODO] : Implement this method. You MUST utilize [this->releasePoolable(...)]. */
    
    for(int i = 0; i < vecPoolableObject.size(); i++)
        this->releasePoolable(vecPoolableObject[i]);
}

bool GameObjectPool::hasAvailable(int nRequestSize) {
    if(this->vecAvailableObject.size() >= nRequestSize)
        return true;

    return false;
}

void GameObjectPool::setEnabled(PoolableObject* pPoolableObject, bool bEnabled) {
    pPoolableObject->setEnabled(bEnabled);

    /* Every time pPoolableObject is enabled or disabled, call its [onActivate()] or [onRelease()] respectively. */
    if(bEnabled)
        pPoolableObject->onActivate();
        
    else
        pPoolableObject->onRelease();
}

PoolTag GameObjectPool::getTag() {
    return this->ETag;
}
