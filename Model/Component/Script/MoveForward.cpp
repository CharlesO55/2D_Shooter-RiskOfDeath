#include "MoveForward.hpp"

using namespace components;
using namespace models;

MoveForward::MoveForward(std::string strName) : Component(strName, ComponentType::SCRIPT){}

MoveForward::~MoveForward(){}

void MoveForward::perform(){
    BaseEnemy* pEnemy = (BaseEnemy*) this->pOwner;
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");

    float fZ = pEnemy->getScenePos().z;
    fZ -= pEnemy->getSpeed() * this->tDeltaTime.asSeconds();

    pEnemy->setZPos(fZ);

    if (fZ <= 0.0f) {
        ObjectPoolManager::getInstance()->getPool(pEnemy->getTag())->releasePoolable(pEnemy);
        pUI->decrementHealth();
    }
}