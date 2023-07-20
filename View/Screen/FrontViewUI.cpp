#include "FrontViewUI.hpp"

using namespace views;
using namespace systems;

FrontViewUI::FrontViewUI() : View(ViewTag::FRONTVIEW_UI, "Front View UI") {}

FrontViewUI::~FrontViewUI() {}

void FrontViewUI::initialize(){
    this->createTextButton(this, "Surrender Button", "Give Up", {SCREEN_WIDTH - 100.f, DEFAULT_TEXT_SIZE});

    this->pScoreText = new views::Text("Score Text", ScoreManager::getInstance()->getScoreAsString(), {SCREEN_WIDTH / 2, DEFAULT_TEXT_SIZE}, FontType::DEFAULT, DEFAULT_TEXT_SIZE, true);
    this->attachChild(pScoreText);

    this->createHearts();
    this->createBullets();
}

void FrontViewUI::update(sf::Time tDeltaTime){
    ScoreManager::getInstance()->incrementScore(tDeltaTime);
    this->pScoreText->setText(ScoreManager::getInstance()->getScoreAsString());

    GameObject::update(tDeltaTime);
}

void FrontViewUI::createHearts() {
    std::string strName = "Heart ";
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::HEART)); 

    float xPos = 50.0f;
    float yPos = 40.0f;

    for (int i = 0; i < 5; i++) {
        this->createImage(strName + std::to_string(i + 1), pTexture, 2.5f, xPos, yPos);
        xPos += 55.0f;
    }
}

void FrontViewUI::createBullets() {
    std::string strName = "Bullet ";
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BULLET)); 

    float xPos = SCREEN_WIDTH - 175.0f;
    float yPos = SCREEN_HEIGHT - 40.0f;

    for (int i = 0; i < 5; i++) {
        this->createImage(strName + std::to_string(i + 1), pTexture, 2.5f, xPos, yPos);
        xPos += 35.0f;
    }
}

void FrontViewUI::onClick(Button* pButton){
    if (pButton->getName() == "Surrender Button"){
        ScoreManager::getInstance()->logScoreOnEnd("NEWWWW");
        SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);
    }
}

void FrontViewUI::onRelease(Button* pButton) {}
