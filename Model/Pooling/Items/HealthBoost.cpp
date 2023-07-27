#include "HealthBoost.hpp"

using namespace models;

HealthBoost::HealthBoost(std::string strName, AnimatedTexture* pTexture) : BaseItem(strName, pTexture, PoolTag::HEALTH_BOOST, 3.0f){}

PoolableObject* HealthBoost::clone() {
    PoolableObject* pClone = new HealthBoost(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}