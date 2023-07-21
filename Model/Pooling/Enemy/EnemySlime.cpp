#include "EnemySlime.hpp"

using namespace models;

//Inheritance not properly implemented yet. 
EnemySlime::EnemySlime(std::string strName, AnimatedTexture* pTexture) : BaseEnemy(strName, pTexture, PoolTag::SLIME_1) {
    this->nHealth = 1;
    this->fSpeed = 1.0f;
    this->fKillableSpeed = 0.1f;
}

void EnemySlime::initialize() {
    this->setFrame(0);
    this->getSprite()->setScale(3.0f, 3.0f);
    this->centerSpriteOrigin();

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    Killable* pKillableComponent = new Killable(this->strName + " Killable", this->fKillableSpeed);

    this->attachComponent(pRendererComponent);
    this->attachComponent(pKillableComponent);

    EnemyManager::getInstance()->registerComponent(pKillableComponent);
}

void EnemySlime::onActivate() {
    this->randomizePosition();
}

void EnemySlime::onRelease() {}

void EnemySlime::randomizePosition() {
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

PoolableObject* EnemySlime::clone() {
    PoolableObject* pClone = new EnemySlime(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}