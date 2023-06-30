#include "TextButton.hpp"

using namespace ui;
using namespace components;

TextButton::TextButton(std::string strName, std::string strText, GameObject* pParent, float fX, float fY) : GameObject(strName, EnumObjTypes::TEXT, EnumObjSubTypes::TEXTBUTTON, pParent, fX, fY) {
    this->CColorNormal = sf::Color::White;
    this->CColorHighlight = sf::Color::Yellow;


    sf::Font *pFont = new sf::Font;
    pFont->loadFromFile("Library/Fonts/Belanosima-Regular.ttf");
    this->pText = new sf::Text(strText, *pFont, 50U);


    this->pDrawable = pText;
}


void TextButton::initialize(){
    GameObject::initialize();

    InputButton *pInputButton = new InputButton(this->strName, this);
    this->vecComponents.push_back(pInputButton);
}

void TextButton::update(sf::Time CTime){
    if (bHighlight){
        this->pText->setFillColor(this->CColorHighlight);
    }
    else{
        this->pText->setFillColor(this->CColorNormal);
    }
}

void TextButton::setHighlight(bool bTOF){
    this->bHighlight = bTOF;
}