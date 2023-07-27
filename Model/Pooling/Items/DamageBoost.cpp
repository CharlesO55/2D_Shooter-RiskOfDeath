#include "DamageBoost.hpp"

using namespace models;

DamageBoost::DamageBoost(std::string strName, AnimatedTexture* pTexture) : BaseItem(strName, pTexture, PoolTag::DAMAGE_BOOST, 3.0f){}

PoolableObject* DamageBoost::clone() {
    PoolableObject* pClone = new DamageBoost(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}