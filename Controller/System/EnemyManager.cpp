#include "EnemyManager.hpp"

using namespace systems;

void EnemyManager::killAll() {
    for (Killable* pKillable : this->vecKillable) 
        pKillable->setKilled(true);

    SFXManager::getInstance()->getSound(SFXType::KILL_ALL)->play();
}

void EnemyManager::scaleEnemySpeed() {
    for (Killable* pKillable : this->vecKillable) {
        BaseEnemy* pEnemy = (BaseEnemy*)pKillable->getOwner();

        pEnemy->scaleSpeed();
    }
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

    //This spawns a wave of enemies for every x seconds.
    if (this->fTime > SPAWN_TIME) {
        this->fTime = 0.0f;

        this->spawnWave();
    }
}

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