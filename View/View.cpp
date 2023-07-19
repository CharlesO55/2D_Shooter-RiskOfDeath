#include "View.hpp"

using namespace views;

View::View(ViewTag ETag, std::string strName) : GameObject(strName) {
    this->ETag = ETag;
}

View::~View() {}

void View::createImage(std::string strName, AnimatedTexture* pTexture, float fScale, float fX, float fY) {
    Image* pImage = new Image(strName, pTexture);
    pImage->getSprite()->setScale(fScale, fScale);
    pImage->getSprite()->setPosition(fX, fY);

    this->attachChild(pImage);
}

void View::createButton(listeners::ButtonListener* pListener, std::string strName, AssetType EAsset, sf::Vector2f vecPos, float fScale){
    AnimatedTexture* pTex = new AnimatedTexture(controllers::TextureManager::getInstance()->getTexture(EAsset));
    Button* pButton = new Button(strName, pTex);
    
    pButton->getSprite()->setScale(fScale, fScale);
    pButton->getSprite()->setPosition(vecPos);
    pButton->centerSpriteOrigin();

    pButton->setListener(pListener);
    this->attachChild(pButton);
}

void View::createTextButton(listeners::ButtonListener* pListener, std::string strName, std::string strText, sf::Vector2f vecPos,  int nSize, FontType EFont){
    views::Text* pQuitText = new views::Text(strName + "Text", strText, vecPos, EFont, nSize, true);
    Button* pQuitButton = new Button(strName, pQuitText->getText());
    pQuitButton->setListener(pListener);
    
    this->attachChild(pQuitButton);
}



ViewTag View::getTag() {
    return this->ETag;
}