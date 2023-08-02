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
    this->createBlockers();

    //KEEP ON TOP
    
    this->createCrosshair();
    this->registerObject(new PlayerUI());


    ScoreManager::getInstance()->resetScore();
}

void GameProper::createNullObjectComponents() {
    std::srand(std::time(NULL));

    EmptyGameObject* pEnemyManagerHolder = new EmptyGameObject("Enemy Manager Holder");
    EnemyManager::initialize("Enemy Manager System", pEnemyManagerHolder);
    GameObjectManager::getInstance()->addObject(pEnemyManagerHolder);

    EmptyGameObject* pItemManagerHolder = new EmptyGameObject("Item Manager Holder");
    ItemManager::initialize("Item Manager System", pItemManagerHolder);
    GameObjectManager::getInstance()->addObject(pItemManagerHolder);

    EmptyGameObject* pBlockerManagerHolder = new EmptyGameObject("Blocker Manager Holder");
    BlockerManager::initialize("Item Manager System", pBlockerManagerHolder);
    GameObjectManager::getInstance()->addObject(pBlockerManagerHolder);

    //View Screen Changer Components
    EmptyGameObject* pHolder = new EmptyGameObject("Game Proper Navigation");
    GameNavigationInput* pNavInput = new GameNavigationInput("Game Navigation Input");
    GameScreenNavigation* pNavScreen = new GameScreenNavigation(pNavInput);
    
    EmptyGameObject* pInputHolder = new EmptyGameObject("Player Input Holder");
    PlayerInput* pInput = new PlayerInput("Player Input");

    pHolder->attachComponent(pNavInput);
    pHolder->attachComponent(pNavScreen);

    pInputHolder->attachComponent(pInput);

    this->registerObject(pHolder);
    this->registerObject(pInputHolder);
}

void GameProper::createCrosshair() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CROSSHAIR));

    Crosshair* pCrosshair = new Crosshair("Crosshair", pTexture);
    this->registerObject(pCrosshair);
}

void GameProper::createObjectPools() {
    //Enemy Pools
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SLIME));
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

    //Buff Pools
    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::DAMAGE_BOOST));
    GameObjectPool* pDamageBuffPool = new GameObjectPool(PoolTag::DAMAGE_BOOST, 5, new DamageBoost("Damage Buff", pTexture), NULL);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::HEALTH_BOOST));
    GameObjectPool* pHealthBuffPool = new GameObjectPool(PoolTag::HEALTH_BOOST, 5, new HealthBoost("Health Buff", pTexture), NULL);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PIERCING_AMMO));
    GameObjectPool* pPiercingBuffPool = new GameObjectPool(PoolTag::PIERCING_SHOT, 5, new PiercingShot("Piercing Buff", pTexture), NULL);

    pDamageBuffPool->initialize();
    pHealthBuffPool->initialize();
    pPiercingBuffPool->initialize();

    ObjectPoolManager::getInstance()->registerObjectPool(pDamageBuffPool);
    ObjectPoolManager::getInstance()->registerObjectPool(pHealthBuffPool);
    ObjectPoolManager::getInstance()->registerObjectPool(pPiercingBuffPool);
}


void GameProper::createBlockers(){
    BoulderBlocker *pBoulderL = new BoulderBlocker("Boulder 1", sf::FloatRect(0, SCREEN_HEIGHT/2, 100, SCREEN_HEIGHT/2-200), {1,0});
    BoulderBlocker *pBoulderR = new BoulderBlocker("Boulder 2", sf::FloatRect(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2-200), {-1,0});
    this->registerObject(pBoulderL);
    this->registerObject(pBoulderR);
    BlockerManager::getInstance()->registerBlocker(pBoulderL);
    // BlockerManager::getInstance()->registerBlocker(pBoulderR);


    //Commented to reduce clutter. Consult regarding blockers first so everything is within theme
    // PlaneBlocker *pPlane = new PlaneBlocker(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    // this->registerObject(pPlane);
    // pPlane = new PlaneBlocker(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    // this->registerObject(pPlane);
    // pPlane = new PlaneBlocker(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    // this->registerObject(pPlane);

    // CloudBlocker *pCloud = new CloudBlocker(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    // this->registerObject(pCloud);
    // pCloud = new CloudBlocker(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    // this->registerObject(pCloud);
    // pCloud = new CloudBlocker(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    // this->registerObject(pCloud);
}