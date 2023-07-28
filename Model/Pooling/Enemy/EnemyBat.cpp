#include "EnemyBat.hpp"

using namespace models;

EnemyBat::EnemyBat(std::string strName, AnimatedTexture* pTexture) : BaseEnemy(strName, pTexture, PoolTag::BAT, 3, 3.0f, 3.0f, 0.1f) {}

void EnemyBat::onRelease() {
    int nRand = std::rand() % 100;

    if (nRand < 4)
        ItemManager::getInstance()->spawn();
}

PoolableObject* EnemyBat::clone() {
    PoolableObject* pClone = new EnemyBat(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}