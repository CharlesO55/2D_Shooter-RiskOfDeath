#include "MusicManager.hpp"

using namespace controllers;

void MusicManager::loadAll() {
    this->create(MusicType::MAIN_MENU, "View/Music/MAIN_MENU.wav");
    this->create(MusicType::GAME_PROPER, "View/Music/GAME_PROPER.wav");
    this->create(MusicType::LEADERBOARDS, "View/Music/LEADERBOARDS.wav");
    this->create(MusicType::Lead_BAKEMONOGATARI, "View/Music/Bakemonogatari - Suruga Monkey.wav");
    this->create(MusicType::Main_OWARIMONOGATARI, "View/Music/Owarimonogatari - Decent Black.wav");
}

void MusicManager::unloadAll() {
    sf::Music* pMusic;
    for(int i = 0; i < this->vecMusic.size(); i++) {
        if(pMusic->getStatus() == sf::Music::Stopped) {
            delete this->vecMusic[i];
        }
    }
}

sf::Music* MusicManager::getMusic(MusicType EType) {
    return this->mapMusic[EType];
}

void MusicManager::create(MusicType EType, std::string strPath) {
    sf::Music* pMusic = new sf::Music();
    pMusic->openFromFile(strPath);
    this->add(EType, pMusic);
}

void MusicManager::add(MusicType EType, sf::Music* pMusic) {
    this->mapMusic[EType] = pMusic;
    this->vecMusic.push_back(pMusic);
}

MusicManager* MusicManager::P_SHARED_INSTANCE = NULL;
MusicManager::MusicManager() {}
MusicManager::MusicManager(const MusicManager&) {}

MusicManager* MusicManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new MusicManager();

    return P_SHARED_INSTANCE;
}
