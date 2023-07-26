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

        views::Text* pName = new views::Text(pairScores.second, pairScores.second, {SCREEN_WIDTH/3, fOffset * i});
        views::Text* pTime = new views::Text(std::to_string(pairScores.first), convertToScoreString(pairScores.first), {SCREEN_WIDTH/2 + fOffset * 2, fOffset * i});

        if (pairScores == ScoreManager::getInstance()->getCurrPlayerScore()){
            pName->getText()->setFillColor(sf::Color::Yellow);
            pTime->getText()->setFillColor(sf::Color::Yellow);
        }
        this->attachChild(pName);
        this->attachChild(pTime);
    }
}

void Leaderboard::onClick(Button* pButton){
    if (pButton->getName() == "Main Menu Button"){
        SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU);
    }
}

void Leaderboard::onRelease(Button* pButton){}



std::string Leaderboard::convertToScoreString(int nValue){
    std::string strScore = 
        this->convertToTenthsString(nValue / 3600) + " :: " + 
        this->convertToTenthsString((nValue / 60) % 60) + " :: " + 
        this->convertToTenthsString(nValue % 60);
                
    return strScore;
}



std::string Leaderboard::convertToTenthsString(int nValue){
    std::string strScore;
    if (nValue < 10){
        strScore = std::to_string(0);
    }
    return strScore + std::to_string(nValue);
}