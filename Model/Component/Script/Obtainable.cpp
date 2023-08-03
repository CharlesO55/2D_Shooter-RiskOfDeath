#include "Obtainable.hpp"

using namespace components;

Obtainable::Obtainable(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fTicks = 0.0f;
    this->bObtained = false;
}

void Obtainable::perform() {
    fTicks += tDeltaTime.asSeconds();
    PoolableObject* pObject = (PoolableObject*)this->pOwner;

    if (this->bObtained) {
        std::cout << "[OBTAINABLE] : Item Obtained" << std::endl;
        this->activate(pObject->getTag());
        ObjectPoolManager::getInstance()->getPool(pObject->getTag())->releasePoolable(pObject);
        this->bObtained = false;
    }

    //Releases the item once 10 seconds have passed after spawning
    if (fTicks > 10.0f) {
        this->fTicks = 0.0f;
        std::cout << "[OBTAINABLE] : Item Despawned" << std::endl;
        ObjectPoolManager::getInstance()->getPool(pObject->getTag())->releasePoolable(pObject);
    }
}

void Obtainable::activate(PoolTag ETag) {
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");

    switch (ETag) {
        case PoolTag::DAMAGE_BOOST:
            std::cout << "[OBTAINABLE] : Damage Boost Added to Inventory" << std::endl;
            pUI->addItemToInventory(ItemType::DAMAGE_BOOST);
            break;

        case PoolTag::PIERCING_SHOT:
            std::cout << "[OBTAINABLE] : Piercing Shot Added to Inventory" << std::endl;
            pUI->addItemToInventory(ItemType::PIERCING_SHOT);
            break;

        case PoolTag::INFINITY_AMMO:
            std::cout << "[OBTAINABLE] : Infinity Added to Inventory" << std::endl;
            pUI->addItemToInventory(ItemType::INFINITY_AMMO);
            break;

        case PoolTag::HEALTH_BOOST:
            std::cout << "[OBTAINABLE] : Health Restored" << std::endl;
            pUI->restoreHealth();
            break;

        case PoolTag::INSTANT_KILL:
            std::cout << "[OBTAINABLE] : All Enemies Killed" << std::endl;
            EnemyManager::getInstance()->killAll();
            break;

        default:
            break;
    }
}

bool Obtainable::isObtained() {
    return this->bObtained;
}

void Obtainable::setObtained(bool bObtained) {
    this->bObtained = bObtained;
}