#include "PlayerUI.hpp"

using namespace views;
using namespace systems;

PlayerUI::PlayerUI() : View(ViewTag::PLAYER_UI, "Player UI") {
    ViewManager::getInstance()->registerView(this);
}

PlayerUI::~PlayerUI() {}

void PlayerUI::initialize(){
    this->createTextButton(this, "Surrender Button", "Give Up", {SCREEN_WIDTH - 100.f, DEFAULT_TEXT_SIZE});

    this->pScoreText = new views::Text("Score Text", ScoreManager::getInstance()->getScoreAsString(), {SCREEN_WIDTH / 2, DEFAULT_TEXT_SIZE}, FontType::DEFAULT, DEFAULT_TEXT_SIZE, true);
    this->attachChild(pScoreText);


    this->createHearts();
    this->createBullets();

    //TESTING ONLY
    // this->pSprite->setPosition(50, 0);
    // this->pSprite->setScale(0.3, 0.3);
}

void PlayerUI::update(sf::Time tDeltaTime){
    ScoreManager::getInstance()->incrementScore(tDeltaTime);
    this->pScoreText->setText(ScoreManager::getInstance()->getScoreAsString());

    GameObject::update(tDeltaTime);
}

void PlayerUI::createHearts() {
    std::string strName = "Heart ";
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::HEART)); 

    float xPos = 50.0f;
    float yPos = 40.0f;

    for (int i = 0; i < 5; i++) {
        this->createImage(strName + std::to_string(i + 1), pTexture, 2.5f, xPos, yPos);
        xPos += 55.0f;
    }
}

void PlayerUI::createBullets() {
    std::string strName = "Bullet ";
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BULLET)); 

    float xPos = SCREEN_WIDTH - 175.0f;
    float yPos = SCREEN_HEIGHT - 40.0f;

    for (int i = 0; i < 5; i++) {
        this->createImage(strName + std::to_string(i + 1), pTexture, 2.5f, xPos, yPos);
        xPos += 35.0f;
    }
}


void PlayerUI::onClick(Button* pButton){
    if (pButton->getName() == "Surrender Button"){
        ScoreManager::getInstance()->logScoreOnEnd("Test_Player");
        SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);

        MusicManager::getInstance()->getMusic(MusicType::GAME_PROPER)->stop();
        MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->setVolume(40.0f);
        MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->play();
        MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->setLoop(true);
    }
}

void PlayerUI::onRelease(Button* pButton) {}