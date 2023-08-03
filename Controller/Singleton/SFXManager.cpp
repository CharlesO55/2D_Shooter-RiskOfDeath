#include "SFXManager.hpp"

using namespace controllers;

void SFXManager::loadAll() {
    this->create(SFXType::SHOOT, "View/SFX/Shoot.wav");
    this->create(SFXType::RELOAD, "View/SFX/Reload.wav");

    this->create(SFXType::ITEM_TAKEN, "View/SFX/Item_Taken.wav");
    this->create(SFXType::ITEM_ACTIVATE, "View/SFX/Item_Activate.wav");

    this->create(SFXType::HEAL_PLAYER, "View/SFX/Heal_Player.wav");
    this->create(SFXType::KILL_ALL, "View/SFX/Kill_All.wav");

    this->create(SFXType::ENEMY_HIT, "View/SFX/Enemy_Hit.wav");
    this->create(SFXType::PLAYER_HIT, "View/SFX/Player_Hit.wav");
}

void SFXManager::unloadAll() {
    sf::Sound* pSound;
    for(int i = 0; i < this->vecSound.size(); i++) {
        if(pSound->getStatus() == sf::Sound::Stopped) {
            delete this->vecSound[i];
        }
    }
}

sf::Sound* SFXManager::getSound(SFXType EType) {
    return this->mapSound[EType];
}

void SFXManager::create(SFXType EType, std::string strPath) {
    sf::Sound* pSound = new sf::Sound();
    sf::SoundBuffer* pBuffer = new sf::SoundBuffer();
    
    pBuffer->loadFromFile(strPath);
    pSound->setBuffer(*pBuffer);
    this->add(EType, pSound);
}

void SFXManager::add(SFXType EType, sf::Sound* pSound) {
    this->mapSound[EType] = pSound;
    this->vecSound.push_back(pSound);
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
SFXManager* SFXManager::P_SHARED_INSTANCE = NULL;
SFXManager::SFXManager() {}
SFXManager::SFXManager(const SFXManager&) {}

SFXManager* SFXManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new SFXManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */
