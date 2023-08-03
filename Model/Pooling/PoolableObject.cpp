#include "PoolableObject.hpp"

using namespace models;

PoolableObject::PoolableObject(PoolTag ETag, std::string strName, EntityType EType, AnimatedTexture* pTexture)
               : GameObject(strName, pTexture, EType) {
    this->ETag = ETag;
}

PoolableObject::~PoolableObject() {}

PoolTag PoolableObject::getTag() {
    return this->ETag;
}
