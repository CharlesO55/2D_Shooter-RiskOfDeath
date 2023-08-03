#include "PlayerBullet.hpp"

using namespace models;

PlayerBullet::PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip)
             : PoolableObject(PoolTag::PLAYER_BULLET, strName, EntityType::BULLET, pTexture) {
    this->pShip = pShip;
    this->pCollider = NULL;
}

void PlayerBullet::initialize() {
    this->setFrame(0);
    this->centerSpriteOrigin();

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);
    
    PlayerBulletMovement* pMovementComponent = new PlayerBulletMovement(this->strName + " Bullet Movement");

    this->attachComponent(pRendererComponent);
    this->attachComponent(pMovementComponent);

    this->pCollider = new Collider(this->strName + " Collider");
    this->pCollider->setListener(this);

    this->attachComponent(this->pCollider);
}

void PlayerBullet::onActivate() {
    float fHalfWidth = this->pShip->getSprite()->getGlobalBounds().width / 2.0f;
    float fSpacing = 9.0f;

    this->pSprite->setPosition(this->pShip->getSprite()->getPosition().x + fHalfWidth + fSpacing,
                               this->pShip->getSprite()->getPosition().y);

    this->pCollider->cleanCollisions();
    this->pCollider->setCleanUp(false);
    PhysicsManager::getInstance()->trackCollider(this->pCollider);
    
    SFXManager::getInstance()->getSound(SFXType::PLAYER_BULLET)->play();
}

void PlayerBullet::onRelease() {}

void PlayerBullet::onCollisionEnter(GameObject* pGameObject) {
    if(pGameObject->getName().find("Alien") != std::string::npos ||
       pGameObject->getName().find("Border") != std::string::npos) {
        Collider* pCollider = (Collider*)pGameObject->findComponentByName(pGameObject->getName() + " Collider");
        pCollider->setCollided(this->pCollider, false);

        this->pCollider->setCleanUp(true);
        ObjectPoolManager::getInstance()->getPool(this->ETag)->releasePoolable(this);
    }
}

void PlayerBullet::onCollisionExit(GameObject* pGameObject) {}

PoolableObject* PlayerBullet::clone() {
    PoolableObject* pClone = new PlayerBullet(this->strName, new AnimatedTexture(*this->pTexture), this->pShip);
    return pClone;
}
