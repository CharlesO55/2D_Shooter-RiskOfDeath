#include "Leaderboard.hpp"

using namespace views;
using namespace systems;

Leaderboard::Leaderboard() : View(ViewTag::LEADERBOARD, "Leaderboard"){}

Leaderboard::~Leaderboard(){}

void Leaderboard::initialize(){
    this->createTextButton(this, "Main Menu Button", "Return", {SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100.f});

    int i = 0;
    float fOffset = 50;
    for (Pair_nScore_strName pairScores : ScoreManager::getInstance()->getLeaderboard()){
        if (i > 9){
            break;
        }

        i++;
        this->attachChild(new views::Text(pairScores.second, pairScores.second, {SCREEN_WIDTH/3, fOffset * i}));
        this->attachChild(new views::Text(std::to_string(pairScores.first), std::to_string(pairScores.first), {SCREEN_WIDTH/2 + fOffset * 2, fOffset * i}));
    }
}

void Leaderboard::onClick(Button* pButton){
    if (pButton->getName() == "Main Menu Button"){
        SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU);
    }
}

void Leaderboard::onRelease(Button* pButton){}