#include "InfinityAmmo.hpp"

using namespace models;

InfinityAmmo::InfinityAmmo(std::string strName, AnimatedTexture* pTexture) : BaseItem(strName, pTexture, PoolTag::INFINITY_AMMO, 2.0f){}

PoolableObject* InfinityAmmo::clone() {
    PoolableObject* pClone = new InfinityAmmo(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}