#include "BaseEnemy.hpp"

using namespace models;

BaseEnemy::BaseEnemy(std::string strName, AnimatedTexture* pTexture, PoolTag ETag, int nHealth, float fSpeed, float fKillableSpeed) : PoolableObject(ETag, strName, pTexture) {
    this->nHealth = nHealth;
    this->fSpeed = fSpeed;
    this->fKillableSpeed = fKillableSpeed;
    this->vecScenePos = {0.f, 0.f, 0.f};
}

void BaseEnemy::initialize() {
    this->setFrame(0);
    this->getSprite()->setScale(3.0f, 3.0f);
    this->centerSpriteOrigin();

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    Killable* pKillableComponent = new Killable(this->strName + " Killable", this->fKillableSpeed);
    systems::EnemyManager::getInstance()->registerComponent(pKillableComponent);

    ScenePosInterpreter* pPosInterpreter = new ScenePosInterpreter(this->strName + " Interpreter");

    this->attachComponent(pRendererComponent);
    this->attachComponent(pKillableComponent);   
    this->attachComponent(pPosInterpreter);
}

void BaseEnemy::onActivate() {
    this->randomizePosition();
}

void BaseEnemy::onRelease() {}

void BaseEnemy::randomizePosition() { 
    float fHalfWidth = this->pSprite->getTexture()->getSize().x / 2.0f;
    float fHalfHeight = this->pSprite->getTexture()->getSize().y / 2.0f;
    int nMinZSpawn = 80;
    int nMaxZSpawn = 100;
    
    this->vecScenePos.x = std::rand() % (int)(SCREEN_WIDTH - fHalfWidth + 1 - fHalfWidth) + fHalfWidth;
    this->vecScenePos.y = std::rand() % (int)(SCREEN_HEIGHT - fHalfHeight + 1 - fHalfHeight) + fHalfHeight;
    this->vecScenePos.z = std::rand() % (nMaxZSpawn + 1 - nMinZSpawn) + nMinZSpawn;

    //REMOVE WHEN RENDERER
    // this->pSprite->setPosition(vecScenePos.x, vecScenePos.y);
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

sf::Vector3f BaseEnemy::getScenePos(){
    return this->vecScenePos;
}
