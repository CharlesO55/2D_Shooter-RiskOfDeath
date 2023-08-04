#include "BaseItem.hpp"

using namespace models;

BaseItem::BaseItem(std::string strName, AnimatedTexture* pTexture, PoolTag ETag, float fScale) : PoolableObject(ETag, strName, EntityType::ITEM, pTexture) {}

void BaseItem::initialize() {
    this->setFrame(0);
    this->getSprite()->setScale(3.0f, 3.0f);
    this->centerSpriteOrigin();

    RendererSpawnable* pSpawnableComponent = new RendererSpawnable(this->strName + " Sprite");
    pSpawnableComponent->assignDrawable(this->pSprite);

    this->pObtainable_Ref = new Obtainable(this->strName + " Obtainable");
    ItemManager::getInstance()->registerComponent(pObtainable_Ref);

    this->attachComponent(pSpawnableComponent);
    this->attachComponent(this->pObtainable_Ref);   
}

void BaseItem::onActivate() {
    this->randomizePosition();
}

void BaseItem::onRelease() {}

void BaseItem::randomizePosition() { 
    float fHalfWidth = this->pSprite->getTexture()->getSize().x / 2.0f;
    float fHalfHeight = this->pSprite->getTexture()->getSize().y / 2.0f;

    this->getSprite()->setPosition(std::rand() % (int)(SCREEN_WIDTH - fHalfWidth + 1 - fHalfWidth) + fHalfWidth,
                                std::rand() % (int)(SCREEN_HEIGHT - fHalfHeight + 1 - fHalfHeight) + fHalfHeight);
}



void BaseItem::onShot(int nKnockbackPower){
    this->pObtainable_Ref->setObtained(true);
}



bool BaseItem::isVecInHitbox(sf::Vector2f vecLoc){
    return this->getTransformedBounds(ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite()->getTransform()).contains(vecLoc);
}