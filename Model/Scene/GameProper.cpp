#include "GameProper.hpp"

using namespace scenes;
using namespace systems;

GameProper::GameProper() : Scene(SceneTag::GAME_PROPER){}

GameProper::~GameProper(){}

void GameProper::onLoadObjects() {
    this->createBackground("Game Proper Background");
    this->createNullObjectComponents();
    this->createObjectPools();

    this->registerObject(new FrontViewUI());
    this->createCrosshair();

    ScoreManager::getInstance()->resetScore();
}

void GameProper::createNullObjectComponents() {
    std::srand(std::time(NULL));

    EmptyGameObject* pComponentHolder = new EmptyGameObject("Enemy Manager Holder");
    EnemyManager::initialize("Enemy Manager System", pComponentHolder);
    GameObjectManager::getInstance()->addObject(pComponentHolder);
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