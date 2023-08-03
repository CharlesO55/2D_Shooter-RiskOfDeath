#include "LeaderboardScene.hpp"

using namespace scenes;

LeaderboardScene::LeaderboardScene() : Scene(SceneTag::LEADERBOARD) {}

LeaderboardScene::~LeaderboardScene() {}



void LeaderboardScene::onLoadObjects(){
    this->createBackground("Leaderboard Backgroud");
    this->registerObject(new views::Leaderboard());
}


void LeaderboardScene::onLoadResources(){
    Scene::onLoadResources();

    MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->setVolume(40.0f);
    MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->play();
    MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->setLoop(true);
}


void LeaderboardScene::onUnloadResoures(){
    MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->stop();

    Scene::onUnloadResources();
}