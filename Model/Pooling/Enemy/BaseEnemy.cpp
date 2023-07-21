#include "BaseEnemy.hpp"

using namespace models;

BaseEnemy::BaseEnemy(std::string strName, AnimatedTexture* pTexture, PoolTag ETag) : PoolableObject(ETag, strName, pTexture) {
    this->nHealth = -1.0f;
    this->fSpeed = -1.0f;
    this->fKillableSpeed = -1.0f;
}

void BaseEnemy::initialize() {
    this->setFrame(0);
    this->getSprite()->setScale(3.0f, 3.0f);
    this->centerSpriteOrigin();

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    Killable* pKillableComponent = new Killable(this->strName + " Killable", this->fKillableSpeed);

    this->attachComponent(pRendererComponent);
    this->attachComponent(pKillableComponent);   
}

void BaseEnemy::onActivate() {
    this->randomizePosition();
}

void BaseEnemy::onRelease() {}

PoolableObject* BaseEnemy::clone() {
    PoolableObject* pClone = new BaseEnemy(this->strName, new AnimatedTexture(*this->pTexture), this->getTag());
    return pClone;
}

//Can be redone for a cleaner implementation
void BaseEnemy::randomizePosition() { 
    float fX = std::rand() % (SCREEN_WIDTH);
    float fY = std::rand() % (SCREEN_HEIGHT);

    float fWidth = this->pSprite->getTexture()->getSize().x;
    float fHeight = this->pSprite->getTexture()->getSize().y;

    float fHalfWidth = fWidth / 2.0f;
    float fHalfHeight = fHeight / 2.0f;

    if(fX < fHalfWidth)
        fX = fHalfWidth;

    else if(fX > (SCREEN_WIDTH - fHalfWidth))
        fX = (SCREEN_WIDTH - fHalfWidth);
    
    if(fY < fHalfHeight)
        fY = fHalfHeight;

    else if(fY > (SCREEN_HEIGHT - fHalfHeight))
        fY = (SCREEN_HEIGHT - fHalfHeight);
        
    this->pSprite->setPosition(fX, fY);
}

float BaseEnemy::getSpeed() {
    return this->fSpeed;
}

int BaseEnemy::getHealth() {
    return this->nHealth;
}

void BaseEnemy::setHealth(int nHealth) {
    this->nHealth = nHealth;
}