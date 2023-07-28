#include "Obtainable.hpp"

using namespace components;

Obtainable::Obtainable(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fTicks = 0.0f;
    this->bObtained = false;
}

void Obtainable::perform() {
    fTicks += tDeltaTime.asSeconds();

    if (this->bObtained) {
        std::cout << "[Obtainable] : Item Obtained" << std::endl;
        PoolableObject* pObject = (PoolableObject*)this->pOwner;
        ObjectPoolManager::getInstance()->getPool(pObject->getTag())->releasePoolable(pObject);
        this->bObtained = false;
    }

    //Releases the item once 10 seconds have passed after spawning
    if (fTicks > 10.0f) {
        this->fTicks = 0.0f;

        std::cout << "[Obtainable] : Item Despawned" << std::endl;
        PoolableObject* pObject = (PoolableObject*)this->pOwner;
        ObjectPoolManager::getInstance()->getPool(pObject->getTag())->releasePoolable(pObject);
    }
}

bool Obtainable::isObtained() {
    return this->bObtained;
}

void Obtainable::setObtained(bool bObtained) {
    this->bObtained = bObtained;
}