#include "Killable.hpp"

using namespace components;

Killable::Killable(std::string strName, float fFrameInterval) : Component(strName, ComponentType::SCRIPT) {
    this->fFrameInterval = fFrameInterval;
    this->fTicks = 0.0f;
    this->bKilled = false;
}

void Killable::perform() {
    if (this->bKilled) {
        //Include the animation procedure once done.
        std::cout << "[Killable] : Kill Performed" << std::endl;
        PoolableObject* pObject = (PoolableObject*)this->pOwner;
        ObjectPoolManager::getInstance()->getPool(pObject->getTag())->releasePoolable(pObject);

        this->bKilled = false;
    }
}

void Killable::damage() {
    BaseEnemy* pEnemy = (BaseEnemy*)this->pOwner;

    if (!ItemManager::getInstance()->isItemActive(ItemType::DAMAGE_BOOST))
        pEnemy->setHealth(pEnemy->getHealth() - 1);

    else
        pEnemy->setHealth(pEnemy->getHealth() - 2);
}

bool Killable::isKilled() {
    return this->bKilled;
}

void Killable::setKilled(bool bKilled) {
    this->bKilled = bKilled;
}

int Killable::getCurrentHealth() {
    BaseEnemy* pEnemy = (BaseEnemy*)this->pOwner;

    return pEnemy->getHealth();
}