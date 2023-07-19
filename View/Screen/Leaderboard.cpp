#include "Leaderboard.hpp"

using namespace views;

Leaderboard::Leaderboard() : View(ViewTag::LEADERBOARD, "Leaderboard"){}

Leaderboard::~Leaderboard(){}

void Leaderboard::initialize(){
    this->createTextButton(this, "Main Menu Button", "Return", {SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100.f});
}

void Leaderboard::onClick(Button* pButton){
    if (pButton->getName() == "Main Menu Button"){
        SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU);
    }
}

void Leaderboard::onRelease(Button* pButton){}