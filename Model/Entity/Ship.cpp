#include "Ship.hpp"

using namespace models;

Ship::Ship(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    this->CNormalColor = sf::Color(0, 0, 0, 255);
    this->CBlinkColor = sf::Color(255, 255, 255, 255);
    this->bTopBounds = true;
    this->bLeftBounds = true;
    this->bBottomBounds = true;
    this->bRightBounds = true;
}

Ship::~Ship() {}

void Ship::initialize() {
    this->setFrame(0);
    this->centerSpriteOrigin();
    this->pSprite->setPosition(90.0f, 210.0f);
    this->pSprite->setColor(this->CNormalColor);

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    ShipInput* pInputComponent = new ShipInput(this->strName + " Input");
    ShipControls* pControlsComponent = new ShipControls(this->strName + " Controls");

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->setListener(this);

    /* * * [ NEW CONTENT ] * * */
    this->pBlinker = new Blinker(this->strName + " Blinker");
    this->pBlinker->setBlinkable(this);
    /* * * * * * * * * * * * * */

    this->attachComponent(pRendererComponent);
    this->attachComponent(pInputComponent);
    this->attachComponent(pControlsComponent);
    this->attachComponent(pCollider);
    /* * * [ NEW CONTENT ] * * */
    this->attachComponent(pBlinker);
    /* * * * * * * * * * * * * */

    PhysicsManager::getInstance()->trackCollider(pCollider);
}

/* * * [ NEW CONTENT ] * * */
void Ship::blink() {
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
/* * * * * * * * * * * * * */

void Ship::onCollisionEnter(GameObject* pGameObject) {
    if(pGameObject->getName() == "Top Border") {
        this->bTopBounds = false;
    }

    if(pGameObject->getName() == "Left Border") {
        this->bLeftBounds = false;
    }

    if(pGameObject->getName() == "Bottom Border") {
        this->bBottomBounds = false;
    }

    if(pGameObject->getName() == "Right Border") {
        this->bRightBounds = false;
    }

    /* * * [ NEW CONTENT ] * * */
    if(pGameObject->getName().find("Alien") != std::string::npos) {
        MenuBar* pView = (MenuBar*)ViewManager::getInstance()->getView(ViewTag::MENU_BAR);
        pView->decrementHeart();
        this->pBlinker->start();
        SFXManager::getInstance()->getSound(SFXType::PLAYER_HIT)->play();
    }
    /* * * * * * * * * * * * * */
}

void Ship::onCollisionExit(GameObject* pGameObject) {
    if(pGameObject->getName() == "Top Border") {
        this->bTopBounds = true;
    }
    
    if(pGameObject->getName() == "Left Border") {
        this->bLeftBounds = true;
    }
    
    if(pGameObject->getName() == "Bottom Border") {
        this->bBottomBounds = true;
    }
    
    if(pGameObject->getName() == "Right Border") {
        this->bRightBounds = true;
    }
}

bool Ship::isTopBounds() {
    return this->bTopBounds;
}

bool Ship::isLeftBounds() {
    return this->bLeftBounds;
}

bool Ship::isBottomBounds() {
    return this->bBottomBounds;
}

bool Ship::isRightBounds() {
    return this->bRightBounds;
}
