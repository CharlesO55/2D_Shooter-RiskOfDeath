#include "PlayerBulletMovement.hpp"

using namespace components;

PlayerBulletMovement::PlayerBulletMovement(std::string strName)
                     : Component(strName, ComponentType::SCRIPT) {
    this->fFrameInterval = 0.01f;
    this->fTicks = 0.0f;
    this->fSpeed = 350.0f;
}

void PlayerBulletMovement::perform() {
    Collider* pCollider = (Collider*)this->pOwner->findComponentByName(this->pOwner->getName() + " Collider");
    PoolableObject* pPoolableOwner = (PoolableObject*)this->pOwner;

    if(pCollider == NULL || pPoolableOwner == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->fTicks += this->tDeltaTime.asSeconds();

        if(this->fTicks > this->fFrameInterval) {
            this->fTicks = 0.0f;
            this->pOwner->getSprite()->move(this->fSpeed * this->tDeltaTime.asSeconds(), 0.0f);

            float fHalfWidth = this->pOwner->getSprite()->getGlobalBounds().width / 2.0f;
            if(this->pOwner->getSprite()->getPosition().x >= (SCREEN_WIDTH + fHalfWidth)) {
                pCollider->setCleanUp(true);
                ObjectPoolManager::getInstance()->getPool(pPoolableOwner->getTag())->releasePoolable(pPoolableOwner);
            }
        }
    }
}
