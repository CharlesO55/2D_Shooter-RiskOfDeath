#include "Crosshair.hpp"

using namespace models;

Crosshair::Crosshair(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {}

Crosshair::~Crosshair() {}

void Crosshair::initialize() {
    this->pSprite->setScale(2.0f, 2.0f);
    this->centerSpriteOrigin();

    CrosshairMouseInput* pMouseInputComponent = new CrosshairMouseInput("Crosshair Mouse Input");
    CrosshairMovement* pMovementComponent = new CrosshairMovement("Crosshair Movement");

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    this->attachComponent(pMouseInputComponent);
    this->attachComponent(pMovementComponent);
    this->attachComponent(pRendererComponent);
}
