#include "LoadingScreen.hpp"

using namespace views;

LoadingScreen::LoadingScreen() : View(ViewTag::LOADING_SCREEN, "Loading Screen"){
    systems::ViewManager::getInstance()->registerView(this);
}

LoadingScreen::~LoadingScreen() {}

void LoadingScreen::initialize(){
    this->createBackground(AssetType::LOADING_SCREEN_BG);

    views::Text* pText = new views::Text("Loading Text", "Loading...", {SCREEN_WIDTH/2, SCREEN_HEIGHT/2 + 50}, FontType::DEFAULT, 48, true);
    this->attachChild(pText);

    this->bEnabled = false;
}