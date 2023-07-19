#include "ScoreManager.hpp"

using namespace systems;


void ScoreManager::resetScore(){
    this->CTime = sf::Time::Zero;
}

void ScoreManager::incrementScore(sf::Time CDeltaTime){
    this->CTime += CDeltaTime;
}


/* void ScoreManager::logEndTime(){
    sf::Time CScore = this->CClock.restart();
    std::cout << "\nTIME: " << CScore.asSeconds() << std::endl;
} */

const std::string ScoreManager::getScoreAsString() {
    // int nScore = this->CClock.getElapsedTime().asSeconds(); 
    int nScore = this->CTime.asSeconds(); 
    std::string strScore = std::to_string(nScore);

    int nPlaces = 5;
    
    do {
        nScore /= 10;
        nPlaces--;
    } while (nScore > 0);

    while (nPlaces > 0){
        strScore.insert(0, 1, '0');
        nPlaces--;
    }
    
    return strScore;
}

ScoreManager* ScoreManager::P_SHARED_INSTANCE = NULL;

ScoreManager::ScoreManager(){}

ScoreManager* ScoreManager::getInstance(){
    if (P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new ScoreManager();
    }
    return P_SHARED_INSTANCE;
}