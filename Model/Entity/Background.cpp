#include "Background.hpp"

using namespace models;

Background::Background(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {}

Background::~Background() {}

void Background::initialize() {
    this->setFrame(0);

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);
    this->attachComponent(pRendererComponent);

    if (this->pTexture->getFrameSize() > 1){
        Animator* pAnimator = new Animator(this->strName + " Animator");
        this->attachComponent(pAnimator);
    }
}

/* 
void Background::draw(sf::RenderWindow* pWindow, sf::RenderStates CRenderStates){
    GameObject::draw(pWindow, CRenderStates);

    std::cout << std::endl << this->strName << " HAS " << this->pTexture->getFrameSize();
    if(this->pTexture->getFrameSize() > 1){
        this->incrementFrame();
        // this->pSprite->setTexture(*this->pTexture->getFrame());
    }
} */