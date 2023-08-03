#include "PauseScreen.hpp"

using namespace views;
using namespace controllers;
using namespace systems;

PauseScreen::PauseScreen() : View(ViewTag::PAUSE_SCREEN, "Pause Screen"){
    ViewManager::getInstance()->registerView(this);
}

PauseScreen::~PauseScreen(){}

void PauseScreen::initialize(){
    this->createBackground(AssetType::BACKGROUND, 2, 2);
    // this->pBackgroundRef->getSprite()->setColor(sf::Color(255, 255, 255, 200));
    this->pBackgroundRef->getSprite()->setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    this->pBackgroundRef->centerSpriteOrigin();

    views::Text *pPauseText = new views::Text("Pause Text", "PAUSED", {SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, FontType::DEFAULT, 60, true);
    this->attachChild(pPauseText);

    views::Text *pInstructionText = new views::Text("Instruction Text", "Press Space", {SCREEN_WIDTH/2, SCREEN_HEIGHT/2 + 60}, FontType::DEFAULT, 24, true);
    this->attachChild(pInstructionText);

    this->setEnabled(false);
}