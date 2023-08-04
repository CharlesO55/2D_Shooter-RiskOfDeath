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
/* 
    MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->setVolume(40.0f);
    MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->play();
    MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->setLoop(true); */

    
    MusicManager::getInstance()->getMusic(MusicType::Lead_BAKEMONOGATARI)->setVolume(40.0f);
    MusicManager::getInstance()->getMusic(MusicType::Lead_BAKEMONOGATARI)->play();
    MusicManager::getInstance()->getMusic(MusicType::Lead_BAKEMONOGATARI)->setLoop(true);
}


void LeaderboardScene::onUnloadResources(){
    // MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->stop();
    MusicManager::getInstance()->getMusic(MusicType::Lead_BAKEMONOGATARI)->stop();

    Scene::onUnloadResources();
}