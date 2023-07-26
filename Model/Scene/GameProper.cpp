#include "GameProper.hpp"

using namespace scenes;
using namespace systems;
using namespace components;

GameProper::GameProper() : Scene(SceneTag::GAME_PROPER){}

GameProper::~GameProper(){}

void GameProper::onLoadObjects() {
    //LOAD THE SCREEN VIEWS
    this->registerObject(new FrontViewScreen());
    this->registerObject(new SideViewScreen());

    //DISABLE THE SIDE VIEW UNTIL SWITCHED TO BY KEY PRESS
    ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->setEnabled(false);


    this->createNullObjectComponents();
    this->createObjectPools();

    //KEEP ON TOP
    
    this->createCrosshair();
    this->registerObject(new PlayerUI());


    ScoreManager::getInstance()->resetScore();
}

void GameProper::createNullObjectComponents() {
    std::srand(std::time(NULL));

    EmptyGameObject* pComponentHolder = new EmptyGameObject("Enemy Manager Holder");
    EnemyManager::initialize("Enemy Manager System", pComponentHolder);
    GameObjectManager::getInstance()->addObject(pComponentHolder);

    //View Screen Changer Components
    EmptyGameObject* pHolder = new EmptyGameObject("Game Proper Navigation");
    GameNavigationInput* pNavInput = new GameNavigationInput("Game Navigation Input");
    GameScreenNavigation* pNavScreen = new GameScreenNavigation(pNavInput);
    
    pHolder->attachComponent(pNavInput);
    pHolder->attachComponent(pNavScreen);

    this->registerObject(pHolder);

}

void GameProper::createCrosshair() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CROSSHAIR));

    Crosshair* pCrosshair = new Crosshair("Crosshair", pTexture);
    this->registerObject(pCrosshair);
}

void GameProper::createObjectPools() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SLIME_1));
    GameObjectPool* pSlimePool = new GameObjectPool(PoolTag::SLIME, 10, new EnemySlime("Enemy Slime", pTexture), NULL);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BAT));
    GameObjectPool* pBatPool = new GameObjectPool(PoolTag::BAT, 10, new EnemyBat("Enemy Bat", pTexture), NULL);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::GHOST));
    GameObjectPool* pGhostPool = new GameObjectPool(PoolTag::GHOST, 10, new EnemyGhost("Enemy Ghost", pTexture), NULL);

    pSlimePool->initialize();
    pBatPool->initialize();
    pGhostPool->initialize();

    ObjectPoolManager::getInstance()->registerObjectPool(pSlimePool);
    ObjectPoolManager::getInstance()->registerObjectPool(pBatPool);
    ObjectPoolManager::getInstance()->registerObjectPool(pGhostPool);
}