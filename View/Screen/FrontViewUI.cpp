#include "FrontViewUI.hpp"

using namespace views;
using namespace systems;

FrontViewUI::FrontViewUI() : View(ViewTag::FRONTVIEW_UI, "Front View UI") {}

FrontViewUI::~FrontViewUI() {}

void FrontViewUI::initialize(){
    this->createTextButton(this, "Surrender Button", "Give Up", {SCREEN_WIDTH - 100.f, DEFAULT_TEXT_SIZE});

    this->pScoreText = new views::Text("Score Text", ScoreManager::getInstance()->getScoreAsString(), {SCREEN_WIDTH / 2, DEFAULT_TEXT_SIZE}, FontType::DEFAULT, DEFAULT_TEXT_SIZE, true);
    this->attachChild(pScoreText);
}

void FrontViewUI::update(sf::Time tDeltaTime){
    ScoreManager::getInstance()->incrementScore(tDeltaTime);
    this->pScoreText->setText(ScoreManager::getInstance()->getScoreAsString());

    GameObject::update(tDeltaTime);
}

void FrontViewUI::onClick(Button* pButton){
    if (pButton->getName() == "Surrender Button"){
        ScoreManager::getInstance()->logScoreOnEnd("NEWWWWW");
        SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);
    }
}

void FrontViewUI::onRelease(Button* pButton) {}
