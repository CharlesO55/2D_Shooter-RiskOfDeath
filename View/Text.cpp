#include "Text.hpp"

using namespace views;

Text::Text(std::string strName, std::string strText, sf::Vector2f vecPos, FontType EFont, int nSize, bool bCenterAlign, sf::Color CColor) : GameObject(strName, NULL) {
    this->pText = new sf::Text();
    this->pText->setString(strText);
    this->pText->setFont(*controllers::FontManager::getInstance()->getFont(EFont));
    this->pText->setCharacterSize(nSize);
    this->pText->setFillColor(CColor);
    this->pText->setStyle(sf::Text::Bold);
    this->pText->setPosition(vecPos);

    if (bCenterAlign){
        this->centerTextOrigin();
    }
}

void Text::initialize() {
    Renderer* pRendererComponent = new Renderer(this->strName + " Text");
    pRendererComponent->assignDrawable(this->pText);

    this->attachComponent(pRendererComponent);
}

sf::Text* Text::getText() {
    return this->pText;
}

void Text::centerTextOrigin(){
    this->pText->setOrigin(
        pText->getLocalBounds().width / 2.f + this->pText->getLocalBounds().left,
        pText->getLocalBounds().height / 2.f + this->pText->getLocalBounds().top
    );
}

void Text::setText(std::string strText) {
    this->pText->setString(strText);
}
