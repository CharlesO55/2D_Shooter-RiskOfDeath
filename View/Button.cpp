#include "Button.hpp"

using namespace views;

Button::Button(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    this->pText = NULL;
}

Button::Button(std::string strName, sf::Text* pText) : GameObject(strName, NULL){
    this->pText = pText;
}


Button::~Button() {}

void Button::initialize() {
    if (pText == NULL){
        this->setFrame(0);
        this->centerSpriteOrigin();
    }
    Renderer* pRendererComponent = new Renderer(this->strName + " Button");
    // pRendererComponent->assignDrawable(this->pSprite);
    sf::Drawable* pDraw;
    pDraw = (pText) ? (sf::Drawable*)this->pText : (sf::Drawable*)this->pSprite;

    pRendererComponent->assignDrawable(pDraw);


    this->attachComponent(pRendererComponent);
}

void Button::changeState(ButtonState EState) {/* 
    this->pTexture->setCurrentFrame((int)EState);
    this->setFrame(this->pTexture->getCurrentFrame()); */
}

sf::FloatRect Button::getGlobalBounds(){
    if (pText){
        return this->pText->getGlobalBounds();
    }
    return this->pSprite->getGlobalBounds();
}



void Button::setListener(ButtonListener* pListener) {
    this->pListener = pListener;

    ButtonInput* pInputComponent = new ButtonInput(this->strName + " Input", this->pListener);
    this->attachComponent(pInputComponent);
}