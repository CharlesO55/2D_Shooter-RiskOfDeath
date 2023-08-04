#include "EnemySlime.hpp"

using namespace models;

EnemySlime::EnemySlime(std::string strName, AnimatedTexture* pTexture) : BaseEnemy(strName, pTexture, PoolTag::SLIME, 1, 3.f, 1.5f, 1.1f) {}

void EnemySlime::onRelease() {
    int nRand = std::rand() % 100;

    if (nRand < 2)
        ItemManager::getInstance()->spawn();
}

PoolableObject* EnemySlime::clone() {
    PoolableObject* pClone = new EnemySlime(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}