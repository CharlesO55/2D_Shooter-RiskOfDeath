#include "SideViewScreen.hpp"

using namespace models;
using namespace views;
using namespace controllers;
using namespace systems;

SideViewScreen::SideViewScreen() : View(ViewTag::SIDEVIEW_SCREEN, "Side View Screen") {
    ViewManager::getInstance()->registerView(this);
}

SideViewScreen::~SideViewScreen() {}

void SideViewScreen::initialize(){
    this->createBackground(AssetType::BACKGROUND, 1, 1);

    views::Text* pFrontText = new views::Text("Side Header Text", "Side", {SCREEN_WIDTH / 2, 50}, FontType::DEFAULT, 15, true);
    this->attachChild(pFrontText);
}

void SideViewScreen::update(sf::Time tDeltaTime){
    GameObject::update(tDeltaTime);
}