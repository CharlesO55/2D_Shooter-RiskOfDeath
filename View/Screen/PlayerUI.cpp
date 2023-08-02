#include "PlayerUI.hpp"

using namespace views;
using namespace systems;

PlayerUI::PlayerUI() : View(ViewTag::PLAYER_UI, "Player UI") {
    ViewManager::getInstance()->registerView(this);

    this->nHearts = 5;
    this->nBullets = 5;
}

PlayerUI::~PlayerUI() {}

void PlayerUI::initialize(){
    this->createTextButton(this, "Surrender Button", "Give Up", {SCREEN_WIDTH - 100.f, DEFAULT_TEXT_SIZE});

    this->pScoreText = new views::Text("Score Text", ScoreManager::getInstance()->getScoreAsString(), {SCREEN_WIDTH / 2, DEFAULT_TEXT_SIZE}, FontType::DEFAULT, DEFAULT_TEXT_SIZE, true);
    this->attachChild(pScoreText);

    this->createHeartCases();
    this->createBulletCases();

    this->createHearts();
    this->createBullets();

    this->createInventory();
    this->createStatus();

    this->updateActiveEffects();
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

void PlayerUI::createHeartCases() {
    std::string strName = "Heart Case ";
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::HEART_CASE)); 

    float xPos = 50.0f;
    float yPos = 40.0f;

    for (int i = 0; i < 5; i++) {
        this->createImage(strName + std::to_string(i + 1), pTexture, 2.5f, xPos, yPos);
        xPos += 55.0f;
    }
}

void PlayerUI::createBulletCases() {
    std::string strName = "Bullet Case ";
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BULLET_CASE)); 

    float xPos = SCREEN_WIDTH - 175.0f;
    float yPos = SCREEN_HEIGHT - 40.0f;

    for (int i = 0; i < 5; i++) {
        this->createImage(strName + std::to_string(i + 1), pTexture, 2.5f, xPos, yPos);
        xPos += 35.0f;
    }
}

void PlayerUI::createInventory() {
    std::string strName = "Inventory ";
    AssetType EAssetType;

    float xPos = 50.0f;
    float yPos = SCREEN_HEIGHT - 50.0f;

    for (int i = 0; i < 3; i++) {
        switch(i) {
            case 0:
                EAssetType = AssetType::INVENTORY_1;
                break;

            case 1:
                EAssetType = AssetType::INVENTORY_2;
                break;

            case 2:
                EAssetType = AssetType::INVENTORY_3;
                break;
        }

        AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(EAssetType));

        this->createImage(strName + std::to_string(i + 1), pTexture, 4.0f, xPos, yPos);
        xPos += 90.0f;
    }
}

void PlayerUI::createStatus() {
    std::string strName = "Buff ";

    float xPos = 50.0f;
    float yPos = 90.0f;

    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::DAMAGE_BOOST));
    this->createImage(strName + "Damage", pTexture, 1.5f, xPos, yPos);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PIERCING_AMMO));
    this->createImage(strName + "Pierce", pTexture, 1.5f, xPos + 40.0f, yPos);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::INFINITY_AMMO));
    this->createImage(strName + "Infinity", pTexture, 1.5f, xPos + 80.0f, yPos);
}

void PlayerUI::incrementHealth(int nHealth) {

}

void PlayerUI::decrementHealth() {
    if(this->nHearts > 0) {
        std::string strImageName = "Heart " + std::to_string(this->nHearts);

        for(int i = 0; i < this->vecChildren.size(); i++) {
            if(this->vecChildren[i]->getName() == strImageName) 
                this->vecChildren[i]->setEnabled(false);
        }

        this->nHearts--;
    }
}

//Doesn't reload when empty
void PlayerUI::reloadBullets() {
    // if (this->nBullets < 6) {
    //     for (int i = 0; i < this->vecChildren.size(); i++) {
    //         std::string strImageName = "Bullet " + std::to_string(this->nBullets);

    //         if (this->vecChildren[i]->getName() == strImageName) {
    //             this->vecChildren[i]->setEnabled(true);
    //             nBullets++;
    //         }
    //     }
    // }

    for (int i = 0; i < this->vecChildren.size(); i++) {
        std::string strImageName = "Bullet " + std::to_string(this->nBullets + 1);

        if (this->vecChildren[i]->getName() == strImageName) {
            this->vecChildren[i]->setEnabled(true);
            this->nBullets++;
        }
    }
}

//Doesn't decrement first bullet after reloading
void PlayerUI::decrementBullets() {
    if(this->nBullets > 0) {
        std::string strImageName = "Bullet " + std::to_string(this->nBullets);

        for(int i = 0; i < this->vecChildren.size(); i++) {
            if(this->vecChildren[i]->getName() == strImageName) 
                this->vecChildren[i]->setEnabled(false);
        }

        this->nBullets--;
        std::cout << "Bullet Count: " << this->nBullets << std::endl;
    }
}

void PlayerUI::updateActiveEffects() {
    Image* pDamageBuff = (Image*)this->findChildByName("Buff Damage");
    Image* pPierceBuff = (Image*)this->findChildByName("Buff Pierce");
    Image* pInfiniteBuff = (Image*)this->findChildByName("Buff Infinity");

    if (ItemManager::getInstance()->isItemActive(ItemType::DAMAGE_BOOST))
        pDamageBuff->setEnabled(true);

    else
        pDamageBuff->setEnabled(false);

    if (ItemManager::getInstance()->isItemActive(ItemType::PIERCING_SHOT))
        pPierceBuff->setEnabled(true);

    else
        pPierceBuff->setEnabled(false);

    if (ItemManager::getInstance()->isItemActive(ItemType::INFINITY_AMMO))
        pInfiniteBuff->setEnabled(true);

    else
        pInfiniteBuff->setEnabled(false);
}

int PlayerUI::getHealth() {
    return this->nHearts;
}

int PlayerUI::getBullets() {
    return this->nBullets;
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