#include "TopTentacle.hpp"

using namespace models;

TopTentacle::TopTentacle(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {}

TopTentacle::~TopTentacle() {}

void TopTentacle::initialize() {
    float fX = 151.0f;
    float fY = -85.0f;

    this->setFrame(0);
    this->pSprite->setOrigin(this->pSprite->getGlobalBounds().width, 0.0f);
    this->pSprite->setPosition(fX, fY);
    this->pSprite->setColor(sf::Color(0, 0, 0, 255));
    
    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    IdleMovement* pIdleComponent = new IdleMovement(this->strName + " Idleable", fY, fY + 15.0f);
    
    this->attachComponent(pRendererComponent);
    this->attachComponent(pIdleComponent);
}
