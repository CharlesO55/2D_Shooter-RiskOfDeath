#include "GameProper.hpp"

using namespace scenes;
using namespace systems;

GameProper::GameProper() : Scene(SceneTag::GAME_PROPER){}

GameProper::~GameProper(){}

void GameProper::onLoadObjects() {
    this->createBackground("Game Proper Background");
    this->registerObject(new FrontViewUI());
    this->createCrosshair();
    ScoreManager::getInstance()->resetScore();
}

void GameProper::createCrosshair() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CROSSHAIR));

    Crosshair* pCrosshair = new Crosshair("Crosshair", pTexture);
    this->registerObject(pCrosshair);
}