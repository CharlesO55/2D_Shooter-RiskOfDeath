#include "ScoreManager.hpp"

using namespace systems;
using namespace controllers;

void ScoreManager::resetScore(){
    this->CTime = sf::Time::Zero;
}

void ScoreManager::incrementScore(sf::Time CDeltaTime){
    this->CTime += CDeltaTime;
    this->CTimeToSpeedUp += CDeltaTime;

    if (CTimeToSpeedUp > sf::seconds(DEFAULT_SPEEDUP_TIMEFRAME)){
        EnemyManager::getInstance()->scaleEnemySpeed();
        // float fIncreasedSpeed = GameStateManager::getInstance()->getGameSpeed() + 0.1f;
        // GameStateManager::getInstance()->setGameSpeed(fIncreasedSpeed);
        CTimeToSpeedUp = sf::Time::Zero;
    }
}


/* void ScoreManager::logEndTime(){
    sf::Time CScore = this->CClock.restart();
    std::cout << "\nTIME: " << CScore.asSeconds() << std::endl;
} */

int ScoreManager::getScore() {
    return this->CTime.asSeconds();
}

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


const std::vector <Pair_nScore_strName> ScoreManager::getLeaderboard(){
    this->vecLeaderboard.clear();
    int nScore;
    std::string strName;

    std::ifstream fp("Scores.txt");
    
    if(!fp.is_open()){
        std::cout << "\nFAILED TO OPEN SCORES TXT FILE";
        throw 0;
    }

    int nLine = 0;
    while (!fp.fail()){
        if (nLine == 0){
            fp >> nScore;
            nLine++;
        }
        else {
            fp >> strName;
            this->vecLeaderboard.push_back(std::make_pair(nScore, strName));
            nLine = 0;
        }
    }
    fp.close();

    this->sortScores();
    return this->vecLeaderboard;
}

void ScoreManager::sortScores(){
    std::sort(this->vecLeaderboard.begin(), this->vecLeaderboard.end(), std::greater<>());
}


void ScoreManager::logScoreOnEnd(std::string strPlayerName){
    this->getLeaderboard();

    this->pairCurrPlayerScore = Pair_nScore_strName(this->CTime.asSeconds(), strPlayerName);
    // Pair_nScore_strName pairScore(this->CTime.asSeconds(), strPlayerName);
    this->vecLeaderboard.push_back(pairCurrPlayerScore);
    this->sortScores();

    std::ofstream fp("Scores.txt");

    for (Pair_nScore_strName itr : this->vecLeaderboard){
        fp << itr.first << std::endl;
        fp << itr.second << std::endl;
    }
    fp.close();

    this->resetScore();
}


const Pair_nScore_strName ScoreManager::getCurrPlayerScore(){
    return this->pairCurrPlayerScore;
}




ScoreManager* ScoreManager::P_SHARED_INSTANCE = NULL;

ScoreManager::ScoreManager(){}

ScoreManager* ScoreManager::getInstance(){
    if (P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new ScoreManager();
    }
    return P_SHARED_INSTANCE;
}