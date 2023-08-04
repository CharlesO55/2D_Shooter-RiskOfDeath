#include "BaseEnemy.hpp"

using namespace models;

BaseEnemy::BaseEnemy(std::string strName, AnimatedTexture* pTexture, PoolTag ETag, int nMaxHealth, float fScale, float fSpeed, float fSpeedScaling) : PoolableObject(ETag, strName, EntityType::ENEMY, pTexture) {
    this->nHealth = nMaxHealth;
    this->nMaxHealth = nMaxHealth;
    this->fSpeed = fSpeed;
    this->fSpeedScaling = fSpeedScaling;

    this->fDefaultScale = fScale;
    this->vecScenePos = {0.f, 0.f, 0.f};
}

void BaseEnemy::initialize() {
    this->setFrame(0);
    this->getSprite()->setScale(3.0f, 3.0f);
    this->centerSpriteOrigin();

    RendererSpawnable* pRendererSpawanable = new RendererSpawnable(this->strName + " Sprite");
    pRendererSpawanable->assignDrawable(this->pSprite);

    this->pKillableRef = new Killable(this->strName + " Killable", this->fSpeedScaling);
    systems::EnemyManager::getInstance()->registerComponent(pKillableRef);

    ScenePosInterpreter* pPosInterpreter = new ScenePosInterpreter(this->strName + " Interpreter");

    MoveForward* pMoveForward = new MoveForward(this->strName + " MoveForward");

    this->pBlinker = new Blinker(this->strName + " Blinker");
    pBlinker->setBlinkable(this);

    this->attachComponent(pRendererSpawanable);
    this->attachComponent(this->pKillableRef);   
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

void BaseEnemy::scaleSpeed() {
    this->fSpeed = this->fSpeed * this->fSpeedScaling;
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



void BaseEnemy::onShot(int nKnockbackPower){
    std::cout << "\n[SHOT Enemy] : " << this->strName;

    //INCREASE DAMAGE TAKEN WHEN BUFF IS ACTIVE
    this->nHealth = (ItemManager::getInstance()->isItemActive(ItemType::DAMAGE_BOOST)) 
        ? this->nHealth - 2 
        : this->nHealth - 1;


    if (this->nHealth <= 0){
        this->pKillableRef->setKilled(true);
        return;
    }
    this->pBlinker->start();
    this->vecScenePos.z += nKnockbackPower;
}

bool BaseEnemy::isVecInHitbox(sf::Vector2f vecLoc){
    return this->getTransformedBounds(ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite()->getTransform()).contains(vecLoc);
}