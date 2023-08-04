#include "EnemyGhost.hpp"

using namespace models;

EnemyGhost::EnemyGhost(std::string strName, AnimatedTexture* pTexture) : BaseEnemy(strName, pTexture, PoolTag::GHOST, 5, 5.0f, 1.0f, 1.2f) {}

void EnemyGhost::onRelease() {
    int nRand = std::rand() % 100;

    if (nRand < 6)
        ItemManager::getInstance()->spawn();
}

PoolableObject* EnemyGhost::clone() {
    PoolableObject* pClone = new EnemyGhost(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}