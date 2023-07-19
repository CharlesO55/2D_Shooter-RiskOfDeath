#include "GameProper.hpp"

using namespace scenes;
using namespace systems;

GameProper::GameProper() : Scene(SceneTag::GAME_PROPER){}

GameProper::~GameProper(){}

void GameProper::onLoadObjects(){
    this->createBackground("Game Proper Background");
    this->registerObject(new FrontViewUI());

    ScoreManager::getInstance()->resetScore();
}