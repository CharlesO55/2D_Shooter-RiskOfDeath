#include "Text.hpp"

using namespace views;

Text::Text(std::string strName, std::string strText, sf::Font* pFont, int nSize) : GameObject(strName, NULL) {
    this->pText = new sf::Text();
    this->pText->setString(strText);
    this->pText->setFont(*pFont);
    this->pText->setCharacterSize(nSize);
    this->pText->setFillColor(sf::Color(0, 0, 0, 255));
    this->pText->setStyle(sf::Text::Bold);
}

void Text::initialize() {
    Renderer* pRendererComponent = new Renderer(this->strName + " Text");
    pRendererComponent->assignDrawable(this->pText);

    this->attachComponent(pRendererComponent);
}

sf::Text* Text::getText() {
    return this->pText;
}

void Text::setText(std::string strText) {
    this->pText->setString(strText);
}