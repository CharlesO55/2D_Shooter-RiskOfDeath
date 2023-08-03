#include "PlayerUI.hpp"

using namespace views;
using namespace systems;

PlayerUI::PlayerUI() : View(ViewTag::PLAYER_UI, "Player UI") {
    ViewManager::getInstance()->registerView(this);

    this->nHearts = 5;
    this->nBullets = 5;
    this->nItems = 0;

    this->Inventory1 = ItemType::NONE;
    this->Inventory2 = ItemType::NONE;
    this->Inventory3 = ItemType::NONE;
}

PlayerUI::~PlayerUI() {}

void PlayerUI::initialize(){
    this->createTextButton(this, "Surrender Button", "Give Up", {SCREEN_WIDTH - 100.f, DEFAULT_TEXT_SIZE});

    this->pScoreText = new views::Text("Score Text", ScoreManager::getInstance()->getScoreAsString(), {SCREEN_WIDTH / 2, DEFAULT_TEXT_SIZE}, FontType::DEFAULT, DEFAULT_TEXT_SIZE, true);
    this->attachChild(pScoreText);

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

void PlayerUI::restoreHealth() {
    int nRestoredHealth = (std::rand() % 3) + 1;
    int nCounter = 0;

    for (int i = 0; i < this->vecChildren.size(); i++) {
        std::string strImageName = "Heart " + std::to_string(this->nHearts + 1);

        if (this->vecChildren[i]->getName() == strImageName) {
            this->vecChildren[i]->setFrame(0);
            this->nHearts++;
            
            nCounter++;

            if (nCounter == nRestoredHealth)
                break;
        }
    }
}

void PlayerUI::decrementHealth() {
    if(this->nHearts > 0) {
        std::string strImageName = "Heart " + std::to_string(this->nHearts);

        for(int i = 0; i < this->vecChildren.size(); i++) {
            if(this->vecChildren[i]->getName() == strImageName) 
                this->vecChildren[i]->setFrame(1);
        }

        this->nHearts--;
    }
}

void PlayerUI::reloadBullets() {
    for (int i = 0; i < this->vecChildren.size(); i++) {
        std::string strImageName = "Bullet " + std::to_string(this->nBullets + 1);

        if (this->vecChildren[i]->getName() == strImageName) {
            this->vecChildren[i]->setFrame(0);
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
                this->vecChildren[i]->setFrame(1);
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

void PlayerUI::addItemToInventory(ItemType EType) {
    Image* pInventory1 = (Image*)this->findChildByName("Inventory 1");
    Image* pInventory2 = (Image*)this->findChildByName("Inventory 2");
    Image* pInventory3 = (Image*)this->findChildByName("Inventory 3");

    SFXManager::getInstance()->getSound(SFXType::ITEM_TAKEN)->play();

    switch (this->nItems) {
        case 0:
            if (this->Inventory1 == ItemType::NONE) {
                if (EType == ItemType::DAMAGE_BOOST) 
                    pInventory1->setFrame(1);

                else if (EType == ItemType::PIERCING_SHOT) 
                    pInventory1->setFrame(2);

                else if (EType == ItemType::INFINITY_AMMO) 
                    pInventory1->setFrame(3);

                this->Inventory1 = EType;
                this->nItems = 1;
            }    
            break;

        case 1:
            if (this->Inventory2 == ItemType::NONE) {
                if (EType == ItemType::DAMAGE_BOOST) 
                    pInventory2->setFrame(1);

                else if (EType == ItemType::PIERCING_SHOT) 
                    pInventory2->setFrame(2);

                else if (EType == ItemType::INFINITY_AMMO) 
                    pInventory2->setFrame(3);

                this->Inventory2 = EType;
                this->nItems = 2;
            }
            break;

        case 2:
            if (this->Inventory3 == ItemType::NONE) {
                if (EType == ItemType::DAMAGE_BOOST) 
                    pInventory3->setFrame(1);

                else if (EType == ItemType::PIERCING_SHOT) 
                    pInventory3->setFrame(2);

                else if (EType == ItemType::INFINITY_AMMO) 
                    pInventory3->setFrame(3);

                this->Inventory3 = EType;
                this->nItems = 3;
            }  
            break;

        default:
            break;
    }
}

void PlayerUI::updateInventory(int nInventoryNumber) {
    Image* pInventory1 = (Image*)this->findChildByName("Inventory 1");
    Image* pInventory2 = (Image*)this->findChildByName("Inventory 2");
    Image* pInventory3 = (Image*)this->findChildByName("Inventory 3");

    switch (nInventoryNumber) {
        case 1:
            ItemManager::getInstance()->setItemState(this->Inventory1, true);

            if (this->Inventory1 != ItemType::NONE)
                SFXManager::getInstance()->getSound(SFXType::ITEM_ACTIVATE)->play();

            this->Inventory1 = ItemType::NONE;
            this->nItems = 0;

            pInventory1->setFrame(0);
            break;

        case 2:
            ItemManager::getInstance()->setItemState(this->Inventory2, true);

            if (this->Inventory2 != ItemType::NONE)
                SFXManager::getInstance()->getSound(SFXType::ITEM_ACTIVATE)->play();

            this->Inventory2 = ItemType::NONE;
            if (this->Inventory1 == ItemType::NONE)
                this->nItems = 0;

            else
                this->nItems = 1;

            pInventory2->setFrame(0);
            break;

        case 3:
            ItemManager::getInstance()->setItemState(this->Inventory3, true);

            if (this->Inventory3 != ItemType::NONE)
                SFXManager::getInstance()->getSound(SFXType::ITEM_ACTIVATE)->play();

            this->Inventory3 = ItemType::NONE;

            if (this->Inventory1 == ItemType::NONE)
                this->nItems = 0;

            else if (this->Inventory2 == ItemType::NONE) 
                this->nItems = 1;

            else
                this->nItems = 2;

            pInventory3->setFrame(0);
            break;

        default:
            break;
    }
}

int PlayerUI::getHealth() {
    return this->nHearts;
}

int PlayerUI::getBullets() {
    return this->nBullets;
}

void PlayerUI::onClick(Button* pButton){
    if (pButton->getName() == "Surrender Button"){
        SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);
/* 
        ScoreManager::getInstance()->logScoreOnEnd(DEFAULT_PLAYER_NAME);

        MusicManager::getInstance()->getMusic(MusicType::GAME_PROPER)->stop();
        MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->setVolume(40.0f);
        MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->play();
        MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->setLoop(true); */
    }
}

void PlayerUI::onRelease(Button* pButton) {}