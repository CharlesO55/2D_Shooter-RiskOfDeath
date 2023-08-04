#include "EnemyBat.hpp"

using namespace models;

EnemyBat::EnemyBat(std::string strName, AnimatedTexture* pTexture) : BaseEnemy(strName, pTexture, PoolTag::BAT, 3, 3.0f, 2.0f, 1.2f) {}

void EnemyBat::onRelease() {
    int nRand = std::rand() % 100;

    if (nRand < 4)
        ItemManager::getInstance()->spawn();
}

PoolableObject* EnemyBat::clone() {
    PoolableObject* pClone = new EnemyBat(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}