#include "PiercingShot.hpp"

using namespace models;

PiercingShot::PiercingShot(std::string strName, AnimatedTexture* pTexture) : BaseItem(strName, pTexture, PoolTag::PIERCING_SHOT, 2.0f){}

PoolableObject* PiercingShot::clone() {
    PoolableObject* pClone = new PiercingShot(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}