#include "Border.hpp"

using namespace models;

Border::Border(std::string strName, sf::FloatRect CBounds) : GameObject(strName, NULL) {
    this->CBounds = CBounds;
}

Border::~Border() {}

void Border::initialize() {
    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->setListener(this);
    
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);
}

void Border::onCollisionEnter(GameObject* pGameObject) {}

void Border::onCollisionExit(GameObject* pGameObject) {}

sf::FloatRect Border::getGlobalBounds() {
    return this->CBounds;
}