#include "GameProper.hpp"

using namespace scenes;
using namespace systems;
using namespace components;

GameProper::GameProper() : Scene(SceneTag::GAME_PROPER){}

GameProper::~GameProper(){}

void GameProper::onLoadObjects() {
    this->createNullObjectComponents();
    this->createObjectPools();
 
    //LOAD THE SCREEN VIEWS
    this->registerObject(new FrontViewScreen());
    this->registerObject(new SideViewScreen());
    this->registerObject(new PlayerUI());

    //DISABLE THE SIDE VIEW UNTIL SWITCHED TO BY KEY PRESS
    ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->setEnabled(false);


    this->createCrosshair();

    ScoreManager::getInstance()->resetScore();
}

void GameProper::createNullObjectComponents() {
    std::srand(std::time(NULL));

    EmptyGameObject* pComponentHolder = new EmptyGameObject("Enemy Manager Holder");
    EnemyManager::initialize("Enemy Manager System", pComponentHolder);
    GameObjectManager::getInstance()->addObject(pComponentHolder);



    //View Screen Changer Components
    EmptyGameObject* pHolder = new EmptyGameObject("Game Proper");
    
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
    GameObjectPool* pSlimePool = new GameObjectPool(PoolTag::SLIME_1, 10, new EnemySlime("Enemy Slime", pTexture), NULL);

    pSlimePool->initialize();
    ObjectPoolManager::getInstance()->registerObjectPool(pSlimePool);
}

/* 
void GameProper::createNullObjects(){
    EmptyGameObject* pHolder = new EmptyGameObject("Game Proper");
    
    GameNavigationInput* pNavInput = new GameNavigationInput("Game Navigation Input"); 
    GameScreenNavigation* pNavScreen = new GameScreenNavigation(pNavInput);

    pHolder->attachComponent(pNavInput);
    pHolder->attachComponent(pNavScreen);

    this->registerObject(pHolder);
}; */