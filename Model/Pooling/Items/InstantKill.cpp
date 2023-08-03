#include "InstantKill.hpp"

using namespace models;

InstantKill::InstantKill(std::string strName, AnimatedTexture* pTexture) : BaseItem(strName, pTexture, PoolTag::INSTANT_KILL, 2.0f){}

PoolableObject* InstantKill::clone() {
    PoolableObject* pClone = new InstantKill(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}