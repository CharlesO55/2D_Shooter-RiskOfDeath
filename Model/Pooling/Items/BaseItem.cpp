#include "BaseItem.hpp"

using namespace models;

BaseItem::BaseItem(std::string strName, AnimatedTexture* pTexture, PoolTag ETag, float fScale) : PoolableObject(ETag, strName, pTexture) {}

void BaseItem::initialize() {
    this->setFrame(0);
    this->getSprite()->setScale(3.0f, 3.0f);
    this->centerSpriteOrigin();

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    Obtainable* pObtainableComponent = new Obtainable(this->strName + " Obtainable");
    ItemManager::getInstance()->registerComponent(pObtainableComponent);

    this->attachComponent(pRendererComponent);
    this->attachComponent(pObtainableComponent);   
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