#include "EnemySlime.hpp"

using namespace models;

//Inheritance not properly implemented yet. 
EnemySlime::EnemySlime(std::string strName, AnimatedTexture* pTexture) : BaseEnemy(strName, pTexture, PoolTag::SLIME_1, 1, 1.f, 0.1f) {
}

PoolableObject* EnemySlime::clone() {
    PoolableObject* pClone = new EnemySlime(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}