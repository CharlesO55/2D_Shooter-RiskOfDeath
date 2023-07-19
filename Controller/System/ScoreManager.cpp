#include "ScoreManager.hpp"

using namespace systems;


void ScoreManager::logStartTime(){
    this->CClock.restart();
}

void ScoreManager::logEndTime(){
    sf::Time CScore = this->CClock.restart();
    std::cout << "\nTIME: " << CScore.asSeconds() << std::endl;
}


ScoreManager* ScoreManager::P_SHARED_INSTANCE = NULL;

ScoreManager::ScoreManager(){}

ScoreManager* ScoreManager::getInstance(){
    if (P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new ScoreManager();
    }
    return P_SHARED_INSTANCE;
}