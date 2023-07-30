#include "Obtainable.hpp"

using namespace components;

Obtainable::Obtainable(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fTicks = 0.0f;
    this->bObtained = false;
}

void Obtainable::perform() {
    fTicks += tDeltaTime.asSeconds();

    if (this->bObtained) {
        std::cout << "[OBTAINABLE] : Item Obtained" << std::endl;
        PoolableObject* pObject = (PoolableObject*)this->pOwner;
        this->activate(pObject->getTag());

        ObjectPoolManager::getInstance()->getPool(pObject->getTag())->releasePoolable(pObject);
        this->bObtained = false;
    }

    //Releases the item once 10 seconds have passed after spawning
    if (fTicks > 10.0f) {
        this->fTicks = 0.0f;

        std::cout << "[OBTAINABLE] : Item Despawned" << std::endl;
        PoolableObject* pObject = (PoolableObject*)this->pOwner;
        ObjectPoolManager::getInstance()->getPool(pObject->getTag())->releasePoolable(pObject);
    }
}

void Obtainable::activate(PoolTag ETag) {
    if (ETag == PoolTag::DAMAGE_BOOST) {
        std::cout << "[OBTAINABLE] : Damage Boost Active" << std::endl;
        ItemManager::getInstance()->setItemState(ItemType::DAMAGE_BOOST, true);
    }

    else if (ETag == PoolTag::PIERCING_SHOT) {
        std::cout << "[OBTAINABLE] : Piercing Shot Active" << std::endl;
        ItemManager::getInstance()->setItemState(ItemType::PIERCING_SHOT, true);
    }

    else if (ETag == PoolTag::INFINITY_AMMO) {
        std::cout << "[OBTAINABLE] : Infinity Active" << std::endl;
        ItemManager::getInstance()->setItemState(ItemType::INFINITY_AMMO, true);
    }
}

bool Obtainable::isObtained() {
    return this->bObtained;
}

void Obtainable::setObtained(bool bObtained) {
    this->bObtained = bObtained;
}