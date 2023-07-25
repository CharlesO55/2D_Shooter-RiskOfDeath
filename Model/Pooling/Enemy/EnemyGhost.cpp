#include "EnemyGhost.hpp"

using namespace models;

EnemyGhost::EnemyGhost(std::string strName, AnimatedTexture* pTexture) : BaseEnemy(strName, pTexture, PoolTag::GHOST, 5, 5.0f, 5.0f, 0.1f) {}

PoolableObject* EnemyGhost::clone() {
    PoolableObject* pClone = new EnemyGhost(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}