#include "LoadingScene.hpp"

using namespace scenes;

LoadingScene::LoadingScene() : Scene(SceneTag::LOADING){}

LoadingScene::~LoadingScene(){}

void LoadingScene::onLoadObjects(){
    this->registerObject(new LoadingScreen());
}