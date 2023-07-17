#include "BottomTentacle.hpp"

using namespace models;

BottomTentacle::BottomTentacle(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {}

BottomTentacle::~BottomTentacle() {}

void BottomTentacle::initialize() {
    float fX = 66.0f;
    float fY = 135.0f;

    this->setFrame(0);
    this->pSprite->setOrigin(this->pSprite->getGlobalBounds().width, 0.0f);
    this->pSprite->setPosition(fX, fY);
    this->pSprite->setColor(sf::Color(0, 0, 0, 255));

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    IdleMovement* pIdleComponent = new IdleMovement(this->strName + " Idleable", fY - 14.0f, fY);
    
    this->attachComponent(pRendererComponent);
    this->attachComponent(pIdleComponent);
}
