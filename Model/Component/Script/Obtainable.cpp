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
        this->toggle(pObject->getTag(), true);
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

void Obtainable::toggle(PoolTag ETag, bool bState) {
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");

    switch (ETag) {
        case PoolTag::DAMAGE_BOOST:
            std::cout << "[OBTAINABLE] : Damage Boost Active" << std::endl;
            pUI->addItemToInventory(ItemType::DAMAGE_BOOST);
            //ItemManager::getInstance()->setItemState(ItemType::DAMAGE_BOOST, bState);
            break;

        case PoolTag::PIERCING_SHOT:
            std::cout << "[OBTAINABLE] : Piercing Shot Active" << std::endl;
            pUI->addItemToInventory(ItemType::PIERCING_SHOT);
            //ItemManager::getInstance()->setItemState(ItemType::PIERCING_SHOT, bState);
            break;

        case PoolTag::INFINITY_AMMO:
            std::cout << "[OBTAINABLE] : Infinity Active" << std::endl;
            pUI->addItemToInventory(ItemType::INFINITY_AMMO);
            //ItemManager::getInstance()->setItemState(ItemType::INFINITY_AMMO, bState);
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