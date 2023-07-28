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
    //GOAL: OFFSET THE CURR BOUNDS BY THE PARENT VIEW'S TRANSFORM
    sf::FloatRect CInitialBounds;

    //DETERMINE IF TEXT OR SPRITE BUTTON
    if (pText){
        CInitialBounds = this->pText->getGlobalBounds();
    }
    else{
        CInitialBounds = this->pSprite->getGlobalBounds();
    }

    if(pParent == NULL){
        std::cout << "\n[ERROR] GetGlobalBounds failed. Requires button to be parented to a view";
        throw 0;
    }
    //THE TRANSFORM OF ITS VIEW
    sf::Transform CTransform = this->pParent->getSprite()->getTransform();

    //OFFSET BY ITS VIEW's TRANSFORM
    sf::FloatRect CFinalBounds = CTransform.transformRect(CInitialBounds);
    return CFinalBounds;

/* 
    if (pText){
        // CRenderStates.transform = this->pText->getTransform() * CRenderStates.transform;
        // CRenderStates.transform.getMatrix()
        // sf::FloatRect CBounds = this->pText->getGlobalBounds();
        // CBounds *= CRenderStates.transform

        //GOAL: OFFSET THE CURR BOUNDS BY THE PARENT VIEW'S TRANSFORM
        //THE INITIAL RECT OF THE TEXT
        sf::FloatRect CInitialBounds = this->pText->getGlobalBounds();
        //THE TRANSFORM OF ITS VIEW
        sf::Transform CTransform = this->pParent->getSprite()->getTransform();
        //OFFSET BY ITS VIEW's TRANSFORM
        sf::FloatRect CFinalBounds = CTransform.transformRect(CInitialBounds);
        return CFinalBounds;

    //     return this->pText->getGlobalBounds();
    }
    return this->pSprite->getGlobalBounds(); */
}



void Button::setListener(ButtonListener* pListener) {
    this->pListener = pListener;

    ButtonInput* pInputComponent = new ButtonInput(this->strName + " Input", this->pListener);
    this->attachComponent(pInputComponent);
}