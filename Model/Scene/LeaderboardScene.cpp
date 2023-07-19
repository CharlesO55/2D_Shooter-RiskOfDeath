#include "LeaderboardScene.hpp"

using namespace scenes;

LeaderboardScene::LeaderboardScene() : Scene(SceneTag::LEADERBOARD) {}

LeaderboardScene::~LeaderboardScene() {}



void LeaderboardScene::onLoadObjects(){
    this->createBackground("Leaderboard Backgroud", -1);
    this->registerObject(new views::Leaderboard());
}