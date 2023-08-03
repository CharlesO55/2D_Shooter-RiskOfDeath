#include "MenuBar.hpp"

using namespace views;

MenuBar::MenuBar() : View(ViewTag::MENU_BAR, "Menu Bar View") {
    ViewManager::getInstance()->registerView(this);
    this->nScore = 0;
    this->nHeart = 3;
}

MenuBar::~MenuBar() {}

void MenuBar::initialize() {
    std::string strImageName = this->strName + " Heart ";
    float fWidth = 46.0f;
    float fSpacing = 14.0f;
    float fX = 53.0f;
    float fY = 55.5f;

    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::HEART));
    for(int i = 0; i < this->nHeart; i++) {
        this->createImage(strImageName + std::to_string(i + 1), pTexture, 1.0f, fX, fY);
        fX = fX + fWidth + fSpacing;
    }

    this->pText = new Text(this->strName + " Score", "00000", {0,0}, FontType::DEFAULT, 47);
    this->pText->getText()->setPosition(535, 35);
    this->attachChild(pText);

    this->createTextButton(this, "Quit Button", "Give Up", {SCREEN_WIDTH - 90, DEFAULT_TEXT_SIZE}, DEFAULT_TEXT_SIZE);



    // systems::ScoreManager::getInstance()->resetScore();
}

void MenuBar::incrementScore() {
    std::string strText = "99999";

    this->nScore++;
    if(this->nScore < 99999) {
        strText = "";

        int nDigits = 5;
        int nLength = std::to_string(this->nScore).length();

        for(int i = 0; i < (nDigits - nLength); i++)
            strText = strText + "0";
        
        strText = strText + std::to_string(this->nScore);
    }

    this->pText->setText(strText);
}

void MenuBar::decrementHeart() {
    if(this->nHeart > 0) {
        std::string strImageName = this->strName + " Heart " + std::to_string(this->nHeart);
        bool bFound = false;
        for(int i = 0; i < this->vecChildren.size() && !bFound; i++) {
            if(this->vecChildren[i]->getName() == strImageName) {
                this->vecChildren[i]->setEnabled(false);
                bFound = true;
            }
        }

        this->nHeart--;
    }
}


void MenuBar::onClick(Button* pButton){
    if (pButton->getName() == "Quit Button"){
        systems::SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);
    }
}