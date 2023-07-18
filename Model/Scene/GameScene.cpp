#include "GameScene.hpp"

using namespace scenes;

/* * * * * * * [NEW CONTENT] * * * * * * */
/* This class is meant to be the entire
 * Game Scene (i.e. where the [Ship]
 * attacks [MrAlien]). */

GameScene::GameScene() : Scene(SceneTag::GAME_SCENE) {}

GameScene::~GameScene() {}

/* Nothing to do here, but take note of the
 * [IMPORTANT] comment in the [Game] class. */
void GameScene::onLoadResources() {
    TextureManager::getInstance()->loadAll(SceneTag::MAIN_MENU);
}


/* We transferred ALL object creation which
 * was previously in [Game], into this
 * class. */
void GameScene::onLoadObjects() {
    this->createNullObjectComponents();
    this->createBackground();
    this->createShip();
    this->createAlien();
    this->createUserInterface();
    this->createObjectPools();
    this->createBorders();
}

/* Nothing to do here, but take note of the
 * [IMPORTANT] comment in the [Game] class. */
void GameScene::onUnloadResources() {}

/* ALL functions below are the helper methods 
 * that were previously in the [Game] class. */
void GameScene::createNullObjectComponents() {
    std::srand(std::time(NULL));

    EmptyGameObject* pComponentHolder = new EmptyGameObject("Physics Manager Holder");
    PhysicsManager::initialize("Physics Manager System", pComponentHolder);
    this->registerObject(pComponentHolder);
}

void GameScene::createObjectPools() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BULLET));
    Ship* pShip = (Ship*)GameObjectManager::getInstance()->findObjectByName("Ship");
    
    GameObjectPool* pBulletPool = new GameObjectPool(PoolTag::PLAYER_BULLET,
                                                     3,
                                                     new PlayerBullet("Player Bullet", pTexture, pShip),
                                                     NULL);
    pBulletPool->initialize();
    ObjectPoolManager::getInstance()->registerObjectPool(pBulletPool);
}

void GameScene::createUserInterface() {
    MenuBar* pMenuBar = new MenuBar();
    this->registerObject(pMenuBar);
}

void GameScene::createBackground() {
    AssetType EType = AssetType::BACKGROUND;
    // AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(EType, 1));
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(EType, 0));

    Background* pBackground = new Background("Game Scene Background", pTexture);
    this->registerObject(pBackground);
}

void GameScene::createShip() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SHIP));
    Ship* pShip = new Ship("Ship", pTexture);
    this->registerObject(pShip);
}

void GameScene::createAlien() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MR_ALIEN_BASE));

    MrAlien* pAlien = new MrAlien("Mr. Alien", pTexture);
    this->registerObject(pAlien);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MR_ALIEN_BOTTOM_STAMEN));
    pAlien->attachChild(new BottomStamen("Bottom Stamen", pTexture));

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MR_ALIEN_BOTTOM_TENTACLE));
    pAlien->attachChild(new BottomTentacle("Bottom Tentacle", pTexture));

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MR_ALIEN_TOP_STAMEN));
    pAlien->attachChild(new TopStamen("Top Stamen", pTexture));

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MR_ALIEN_TOP_TENTACLE));
    pAlien->attachChild(new TopTentacle("Top Tentacle", pTexture));
}

void GameScene::createBorders() {
    int fSize = 24.0f;

    this->registerObject(new Border("Top Border", sf::FloatRect(0.0f, 0.0f, SCREEN_WIDTH, fSize)));
    this->registerObject(new Border("Left Border", sf::FloatRect(0.0f, 0.0f, fSize, SCREEN_HEIGHT)));
    this->registerObject(new Border("Bottom Border", sf::FloatRect(0.0f, SCREEN_HEIGHT - fSize, SCREEN_WIDTH, fSize)));
    this->registerObject(new Border("Right Border", sf::FloatRect(SCREEN_WIDTH - fSize, 0.0f, fSize, SCREEN_HEIGHT)));
}
/* * * * * * * * * * * * * * * * * * * * */
