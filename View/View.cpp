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
    views::Text* pButtonText = new views::Text(strName + "Text", strText, vecPos, EFont, nSize, true);
    Button* pButton = new Button(strName, pButtonText->getText());
    pButton->setListener(pListener);
    
    this->attachChild(pButton);
}

void View::createBackground(AssetType EAsset, int nStartFrame, int nEndFrame){
    AnimatedTexture* pTex = new AnimatedTexture(controllers::TextureManager::getInstance()->getTexture(EAsset, nStartFrame, nEndFrame));
    Background* pBackground = new Background(this->strName + " Background", pTex);
    this->pBackgroundRef = pBackground;

    this->setFrame(0);
    this->attachChild(pBackground);
}


ViewTag View::getTag() {
    return this->ETag;
}

Background* View::getBackground(){
    if(this->pBackgroundRef == NULL){
        std::cout << "\n[ERROR] VIEW BACKGROUND NOT SET";
        throw 0;
    }
    return this->pBackgroundRef;
}
