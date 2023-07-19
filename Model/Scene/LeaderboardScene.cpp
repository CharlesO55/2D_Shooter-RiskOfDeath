#include "LeaderboardScene.hpp"

#include "../../View/Screen/MainMenu.hpp"


using namespace scenes;

LeaderboardScene::LeaderboardScene() : Scene(SceneTag::LEADERBOARD) {}

LeaderboardScene::~LeaderboardScene() {}



void LeaderboardScene::onLoadObjects(){
    this->createBackground();
    this->registerObject(new MainMenu());
}