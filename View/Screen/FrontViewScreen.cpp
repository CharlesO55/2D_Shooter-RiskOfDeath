#include "FrontViewScreen.hpp"

using namespace views;
using namespace systems;

FrontViewScreen::FrontViewScreen() : View(ViewTag::FRONTVIEW_SCREEN, "Front View UI") {
    ViewManager::getInstance()->registerView(this);
}

FrontViewScreen::~FrontViewScreen() {}

void FrontViewScreen::initialize(){
    this->createBackground(AssetType::BACKGROUND, 0, 0);

    views::Text* pFrontText = new views::Text("Front Header Text", "Front", {SCREEN_WIDTH / 2, 50}, FontType::DEFAULT, 15, true);
    this->attachChild(pFrontText);
/* 
    this->createTextButton(this, "Surrender Button", "Give Up", {SCREEN_WIDTH - 100.f, DEFAULT_TEXT_SIZE});

    this->pScoreText = new views::Text("Score Text", ScoreManager::getInstance()->getScoreAsString(), {SCREEN_WIDTH / 2, DEFAULT_TEXT_SIZE}, FontType::DEFAULT, DEFAULT_TEXT_SIZE, true);
    this->attachChild(pScoreText);


    this->createHearts();
    this->createBullets(); */
}

void FrontViewScreen::update(sf::Time tDeltaTime){
    /* ScoreManager::getInstance()->incrementScore(tDeltaTime);
    this->pScoreText->setText(ScoreManager::getInstance()->getScoreAsString());
 */
    GameObject::update(tDeltaTime);
}
/* 
void FrontViewScreen::createHearts() {
    std::string strName = "Heart ";
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::HEART)); 

    float xPos = 50.0f;
    float yPos = 40.0f;

    for (int i = 0; i < 5; i++) {
        this->createImage(strName + std::to_string(i + 1), pTexture, 2.5f, xPos, yPos);
        xPos += 55.0f;
    }
}

void FrontViewScreen::createBullets() {
    std::string strName = "Bullet ";
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BULLET)); 

    float xPos = SCREEN_WIDTH - 175.0f;
    float yPos = SCREEN_HEIGHT - 40.0f;

    for (int i = 0; i < 5; i++) {
        this->createImage(strName + std::to_string(i + 1), pTexture, 2.5f, xPos, yPos);
        xPos += 35.0f;
    }
}

void FrontViewScreen::onClick(Button* pButton){
    if (pButton->getName() == "Surrender Button"){
        ScoreManager::getInstance()->logScoreOnEnd("Test_Player");
        SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);
    }
} */
/* 
void FrontViewScreen::onRelease(Button* pButton) {} */