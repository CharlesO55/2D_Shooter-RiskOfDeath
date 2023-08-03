#include "ItemManager.hpp"

using namespace systems;

void ItemManager::obtain(sf::Vector2f vecLocation) {
    int nIndex = -1;
    GameObject* pOwner;
    
    for (int i = (this->vecObtainable.size()) - 1; i > -1 && nIndex == -1; i--) {
        pOwner = this->vecObtainable[i]->getOwner();

        if(!this->vecObtainable[i]->isObtained() && pOwner->isEnabled() && this->isLocInSprite(pOwner, vecLocation)) 
            nIndex = i;
    }

    if(nIndex != -1) {
        pOwner = this->vecObtainable[nIndex]->getOwner();
        this->vecObtainable[nIndex]->setObtained(true);
    }
}

void ItemManager::spawn() {
    PoolTag ETag = this->getRandomPool();
    ObjectPoolManager::getInstance()->getPool(ETag)->requestPoolable();
}

bool ItemManager::isLocInSprite(GameObject* pTarget, sf::Vector2f vecLocation) {
    if (ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->isEnabled()){
        sf::FloatRect CInitialBounds = pTarget->getSprite()->getGlobalBounds();
        sf::Transform CViewTransform = ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite()->getTransform();
        sf::FloatRect CFinalBounds = CViewTransform.transformRect(CInitialBounds);

        return CFinalBounds.contains(vecLocation);
    }

    return false;
}

void ItemManager::perform() {
    this->fTime += this->tDeltaTime.asSeconds();
    Crosshair* pCrosshair = (Crosshair*)GameObjectManager::getInstance()->findObjectByName("Crosshair");

    if(pCrosshair == NULL) 
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    
    else {
        CrosshairMouseInput* pCrosshairMouseInput = (CrosshairMouseInput*)pCrosshair->findComponentByName("Crosshair Mouse Input");
        
        if(pCrosshairMouseInput == NULL)
            std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
        
        else {
            if(pCrosshairMouseInput->isLeftClick()) { 
                std::cout << "[ItemManager] : Left click Detected" << std::endl;

                this->obtain(pCrosshairMouseInput->getLocation());
                // pCrosshairMouseInput->resetLeftClick();
            }
        }
    }

    this->cooldown(this->tDeltaTime.asSeconds());

    //UNCOMMENT FOR TESTING
    //   if (this->fTime > 1.0f) {
    //       this->fTime = 0.0f;


    //           PoolTag ETag = this->getRandomPool();
    //           ObjectPoolManager::getInstance()->getPool(ETag)->requestPoolable();
        
    //   }
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