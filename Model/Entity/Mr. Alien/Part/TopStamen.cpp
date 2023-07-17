#include "TopStamen.hpp"

using namespace models;

TopStamen::TopStamen(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {}

TopStamen::~TopStamen() {}

void TopStamen::initialize() {
    float fX = 76.0f;
    float fY = 8.0f;

    this->setFrame(0);
    this->pSprite->setOrigin(this->pSprite->getGlobalBounds().width, 0.0f);
    this->pSprite->setPosition(fX, fY);
    this->pSprite->setColor(sf::Color(0, 0, 0, 255));
    
    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    IdleMovement* pIdleComponent = new IdleMovement(this->strName + " Idleable", fY - 8.0f, fY + 7.0f, false);
    
    this->attachComponent(pRendererComponent);
    this->attachComponent(pIdleComponent);
}
