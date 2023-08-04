#include "ItemManager.hpp"

using namespace systems;

void ItemManager::spawn() {
    PoolTag ETag = this->getRandomPool();
    ObjectPoolManager::getInstance()->getPool(ETag)->requestPoolable();
}

void ItemManager::perform() {
    this->fTime += this->tDeltaTime.asSeconds();
    this->cooldown(this->tDeltaTime.asSeconds());
}

void ItemManager::cooldown(float fTime) {
    if (this->bDamageBoost) {
        this->fDamageCooldown += fTime;

        if (this->fDamageCooldown > 5.0f) {
            this->fDamageCooldown = 0.0f;
            this->setItemState(ItemType::DAMAGE_BOOST, false);
        }
    }

    else if (this->bInfiniteAmmo) {
        this->fInfinityCooldown += fTime;

        if (this->fInfinityCooldown > 5.0f) {
            this->fInfinityCooldown = 0.0f;
            this->setItemState(ItemType::INFINITY_AMMO, false);
        }
    }
}

PoolTag ItemManager::getRandomPool() {
    int nPool = (std::rand() % 5) + 1;

    switch (nPool) {
        case 1:
            return PoolTag::HEALTH_BOOST;

        case 2:
            return PoolTag::DAMAGE_BOOST;

        case 3:
            return PoolTag::PIERCING_SHOT;
        
        case 4:
            return PoolTag::INFINITY_AMMO;
        
        case 5:
            return PoolTag::INSTANT_KILL;

        default:
            return PoolTag::NONE;
    }
}

bool ItemManager::isItemActive(ItemType EType) {
    switch (EType) {
        case ItemType::DAMAGE_BOOST:
            return this->bDamageBoost;

        case ItemType::PIERCING_SHOT:
            return this->bPiercingAmmo;

        case ItemType::INFINITY_AMMO:
            return this->bInfiniteAmmo;

        default:
            return false;
    }
}

void ItemManager::setItemState(ItemType EType, bool bState) {
    switch (EType) {
        case ItemType::DAMAGE_BOOST:
            this->bDamageBoost = bState;
            break;

        case ItemType::PIERCING_SHOT:
            this->bPiercingAmmo = bState;
            break;

        case ItemType::INFINITY_AMMO:
            this->bInfiniteAmmo = bState;
            break;

        default:
            break;
    }

    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");
    pUI->updateActiveEffects();
}

void ItemManager::registerComponent(Obtainable* pObtainable) {
    this->vecObtainable.push_back(pObtainable);
}

void ItemManager::unregisterComponent(Obtainable* pObtainable) {
    int nIndex = -1;

    for(int i = 0; i < this->vecObtainable.size() && nIndex == -1; i++) 
        if(this->vecObtainable[i] == pObtainable)
            nIndex = i;

    if(nIndex != -1) 
        this->vecObtainable.erase(this->vecObtainable.begin() + nIndex);  
}

ItemManager* ItemManager::P_SHARED_INSTANCE = NULL;
ItemManager::ItemManager(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
ItemManager::ItemManager(const ItemManager& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

ItemManager* ItemManager::getInstance() {
    return P_SHARED_INSTANCE;
}

void ItemManager::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new ItemManager(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}