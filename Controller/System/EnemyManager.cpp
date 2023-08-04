#include "EnemyManager.hpp"

using namespace systems;

void EnemyManager::kill(sf::Vector2f vecLocation) {
    int nIndex = -1;
    GameObject* pTarget;
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");
    
    //Allows all enemies in the proximity of the crosshair to be damaged
    if (ItemManager::getInstance()->isItemActive(ItemType::PIERCING_SHOT) && pUI->getBullets() != 0) {
        for (int i = 0; i < vecKillable.size(); i++) {
            pTarget = this->vecKillable[i]->getOwner();

            if (this->isLocInSprite(pTarget, vecLocation)){
                if(!this->vecKillable[i]->isKilled() && this->vecKillable[i]->getCurrentHealth() <= 1 && pTarget->isEnabled())
                    this->vecKillable[i]->setKilled(true);

                else if (!this->vecKillable[i]->isKilled() && pTarget->isEnabled())
                    this->vecKillable[i]->damage();

                SFXManager::getInstance()->getSound(SFXType::ENEMY_HIT)->play();
            }
        }

        ItemManager::getInstance()->setItemState(ItemType::PIERCING_SHOT, false);
        
        if (!ItemManager::getInstance()->isItemActive(ItemType::INFINITY_AMMO)) 
            pUI->decrementBullets();
    }

    else {
        for (int i = (this->vecKillable.size()) - 1; i > -1 && nIndex == -1; i--) {
            pTarget = this->vecKillable[i]->getOwner();

            if(!this->vecKillable[i]->isKilled()  && pTarget->isEnabled() && this->isLocInSprite(pTarget, vecLocation))
                nIndex = i;
        }

        if(nIndex != -1 && pUI->getBullets() != 0) {
            pTarget = this->vecKillable[nIndex]->getOwner();
            
            if (this->vecKillable[nIndex]->getCurrentHealth() <= 1)
                this->vecKillable[nIndex]->setKilled(true);

            else
                this->vecKillable[nIndex]->damage();

            SFXManager::getInstance()->getSound(SFXType::ENEMY_HIT)->play();
        }

        if (!ItemManager::getInstance()->isItemActive(ItemType::INFINITY_AMMO)) 
            pUI->decrementBullets();
    }
}

void EnemyManager::killAll() {
    for (Killable* pKillable : this->vecKillable) {
        pKillable->setKilled(true);
    }

    SFXManager::getInstance()->getSound(SFXType::KILL_ALL)->play();
}

void EnemyManager::scaleEnemySpeed() {
    for (Killable* pKillable : this->vecKillable) {
        BaseEnemy* pEnemy = (BaseEnemy*)pKillable->getOwner();

        pEnemy->scaleSpeed();
    }
}

bool EnemyManager::isLocInSprite(GameObject* pTarget, sf::Vector2f vecLocation){
    //CONVERT THE SPRITE TO MATCH FRONT VIEW ZOOM 
    if (ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->isEnabled()){/* 
        sf::FloatRect CInitialBounds = pTarget->getSprite()->getGlobalBounds();
        sf::Transform CViewTransform = ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite()->getTransform();
        sf::FloatRect CFinalBounds = CViewTransform.transformRect(CInitialBounds);

        return CFinalBounds.contains(vecLocation); */
        sf::Transform CViewTransform = ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite()->getTransform();
        return pTarget->getTransformedBounds(CViewTransform).contains(vecLocation);
    }

    return false;
}


void EnemyManager::switchEnemiesTexture(ViewTag EDir){
    //DO NOTHING WHEN TEXTURE IS ALREADY MATCHING VIEW
    if(EDir == ViewTag::FRONTVIEW_SCREEN && this->vecKillable[0]->getOwner()->getCurrentFrame() == 0){
        return;
    }
    if(EDir == ViewTag::SIDEVIEW_SCREEN && this->vecKillable[0]->getOwner()->getCurrentFrame() == 1){
        return;
    }

    //ELSE SWITCH BETWEEN FRAMES
    for (Killable* pKillable : this->vecKillable){        
        pKillable->getOwner()->incrementFrame();
    }
}


void EnemyManager::perform() {
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
                std::cout << "[EnemyManager] : Left Click Detected" << std::endl;
                this->kill(pCrosshairMouseInput->getLocation());
                //pCrosshairMouseInput->resetLeftClick();
            }
        }
    }

    //This spawns a wave of enemies for every 8 seconds.
    if (this->fTime > SPAWN_TIME) {
        this->fTime = 0.0f;

        this->spawnWave();
    }
}

//Modify once waves are implemented.
void EnemyManager::spawnWave() {
    int nSpawnCount = (ScoreManager::getInstance()->getScore() * (ViewManager::getInstance()->getScreenCols() * ViewManager::getInstance()->getScreenRows()));
    float fLuck = nSpawnCount * ((std::rand() % 2) / 10.0f);
    float fSpawnDecay = (0.02f * (ScoreManager::getInstance()->getScore() / 5.0f));

    float fCommonRate = 0.7f - fSpawnDecay;
    float fUncommonRate = (1.0f - fCommonRate) * 0.6f;
    float fEliteRate = 1 - (fCommonRate + fUncommonRate);

    nSpawnCount -= fLuck;

    for (int i = 0; i < nSpawnCount; i++) {
        float nRand = (float)std::rand() / (float)RAND_MAX;

        //std::cout << nRand << std::endl;

        if (nRand <= fCommonRate)
            ObjectPoolManager::getInstance()->getPool(PoolTag::BAT)->requestPoolable();
            
        else if (nRand <= fCommonRate + fUncommonRate)
            ObjectPoolManager::getInstance()->getPool(PoolTag::SLIME)->requestPoolable();

        else
            ObjectPoolManager::getInstance()->getPool(PoolTag::GHOST)->requestPoolable();
    }
}

void EnemyManager::registerComponent(Killable* pKillable) {
    this->vecKillable.push_back(pKillable);
}

void EnemyManager::unregisterComponent(Killable* pKillable) {
    int nIndex = -1;

    for(int i = 0; i < this->vecKillable.size() && nIndex == -1; i++) 
        if(this->vecKillable[i] == pKillable)
            nIndex = i;

    if(nIndex != -1) 
        this->vecKillable.erase(this->vecKillable.begin() + nIndex);  
}

EnemyManager* EnemyManager::P_SHARED_INSTANCE = NULL;
EnemyManager::EnemyManager(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
EnemyManager::EnemyManager(const EnemyManager& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

EnemyManager* EnemyManager::getInstance() {
    return P_SHARED_INSTANCE;
}

void EnemyManager::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new EnemyManager(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}