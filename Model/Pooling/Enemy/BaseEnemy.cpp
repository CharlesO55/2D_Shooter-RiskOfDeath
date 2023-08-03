#include "BaseEnemy.hpp"

using namespace models;

BaseEnemy::BaseEnemy(std::string strName, AnimatedTexture* pTexture, PoolTag ETag, int nMaxHealth, float fScale, float fSpeed, float fKillableSpeed) : PoolableObject(ETag, strName, EntityType::ENEMY, pTexture) {
    this->nHealth = nMaxHealth;
    this->nMaxHealth = nMaxHealth;
    this->fSpeed = fSpeed;
    this->fKillableSpeed = fKillableSpeed;

    this->fDefaultScale = fScale;
    this->vecScenePos = {0.f, 0.f, 0.f};
}

void BaseEnemy::initialize() {
    this->setFrame(0);
    this->getSprite()->setScale(3.0f, 3.0f);
    this->centerSpriteOrigin();

    RendererSpawnable* pRendererSpawanable = new RendererSpawnable(this->strName + " Sprite");
    pRendererSpawanable->assignDrawable(this->pSprite);

    Killable* pKillableComponent = new Killable(this->strName + " Killable", this->fKillableSpeed);
    systems::EnemyManager::getInstance()->registerComponent(pKillableComponent);

    ScenePosInterpreter* pPosInterpreter = new ScenePosInterpreter(this->strName + " Interpreter");

    MoveForward* pMoveForward = new MoveForward(this->strName + " MoveForward");

    this->pBlinker = new Blinker(this->strName + " Blinker");
    pBlinker->setBlinkable(this);

    this->attachComponent(pRendererSpawanable);
    this->attachComponent(pKillableComponent);   
    this->attachComponent(pPosInterpreter);
    this->attachComponent(pMoveForward);
    this->attachComponent(pBlinker);
}

void BaseEnemy::onActivate() {
    this->randomizePosition();
    this->nHealth = this->nMaxHealth;
    this->pSprite->setColor(sf::Color::White);
}

void BaseEnemy::randomizePosition() { 
    float fHalfWidth = this->pSprite->getTexture()->getSize().x / 2.0f;
    float fHalfHeight = this->pSprite->getTexture()->getSize().y / 2.0f;
    int nMinZSpawn = 80;
    int nMaxZSpawn = 100;
    
    this->vecScenePos.x = std::rand() % (int)(SCREEN_WIDTH - fHalfWidth + 1 - fHalfWidth) + fHalfWidth;
    this->vecScenePos.y = std::rand() % (int)(SCREEN_HEIGHT - fHalfHeight + 1 - fHalfHeight) + fHalfHeight;
    this->vecScenePos.z = std::rand() % (nMaxZSpawn + 1 - nMinZSpawn) + nMinZSpawn;
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

void BaseEnemy::blink(){
    sf::Color CColor;
    //BLINK EITHER WHITE OR RED
    CColor = (this->pSprite->getColor() != sf::Color::White) 
        ? sf::Color::White 
        : sf::Color::Red;
    
    //SET THE RED TINT TO MATCH THE ENEMY'S REMAINING HP ON LAST BLINK
    if (this->pBlinker->getBlinksRemaining() == 1){
        float fTint = ((float)this->nHealth / this->nMaxHealth) * 255;
        CColor = sf::Color(255.f, fTint, fTint);
    }

    this->pSprite->setColor(CColor);
}
