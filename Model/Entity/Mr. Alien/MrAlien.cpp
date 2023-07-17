#include "MrAlien.hpp"

using namespace models;

MrAlien::MrAlien(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    this->CNormalColor = sf::Color(0, 0, 0, 255);
    this->CBlinkColor = sf::Color(255, 255, 255, 255);
}

MrAlien::~MrAlien() {}

void MrAlien::initialize() {
    this->setFrame(0);
    this->centerSpriteOrigin();
    this->pSprite->setPosition(701.0f, 277.0f);
    this->pSprite->setColor(this->CNormalColor);

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    Collider* pCollider = new Collider(this->strName + " Collider");
    sf::FloatRect COffset = sf::FloatRect(60.0f, 0.0f, -60.0f, -60.0f);
    pCollider->setOffset(COffset);
    pCollider->setListener(this);

    this->pBlinker = new Blinker(this->strName + " Blinker");
    this->pBlinker->setBlinkable(this);

    this->attachComponent(pRendererComponent);
    this->attachComponent(pCollider);
    this->attachComponent(pBlinker);
    
    PhysicsManager::getInstance()->trackCollider(pCollider);
}

void MrAlien::blink() {
    if(this->pSprite->getColor() == this->CNormalColor) {
        this->pSprite->setColor(this->CBlinkColor);
        for(GameObject* pChild : this->vecChildren)
            pChild->getSprite()->setColor(this->CBlinkColor);
    }
    else {
        this->pSprite->setColor(this->CNormalColor);
        for(GameObject* pChild : this->vecChildren)
            pChild->getSprite()->setColor(this->CNormalColor);
    }
}

void MrAlien::onCollisionEnter(GameObject* pGameObject) {
    if(pGameObject->getName().find("Bullet") != std::string::npos) {
        MenuBar* pView = (MenuBar*)ViewManager::getInstance()->getView(ViewTag::MENU_BAR);
        pView->incrementScore();
        this->pBlinker->start();
        SFXManager::getInstance()->getSound(SFXType::ENEMY_HIT)->play();
    }
}

void MrAlien::onCollisionExit(GameObject* pGameObject) {}
