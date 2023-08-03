#pragma once

#include "../../Config/Settings.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   include <iostream>
#   endif

#include <fstream>

using Pair_nScore_strName = std::pair<int, std::string>;

namespace systems{
    class ScoreManager {
        private:
            sf::Time CTime;
            std::vector <Pair_nScore_strName> vecLeaderboard;
            Pair_nScore_strName pairCurrPlayerScore = Pair_nScore_strName(0, "NONE");


        public:
            void resetScore();
            void incrementScore(sf::Time CDeltaTime);
            void logScoreOnEnd(std::string strPlayerName = DEFAULT_PLAYER_NAME);

        public:
            int getScore();

            const std::string getScoreAsString();
            const std::vector <Pair_nScore_strName> getLeaderboard();
            const Pair_nScore_strName getCurrPlayerScore(); 

        private:
            void sortScores();

        private:
            static ScoreManager* P_SHARED_INSTANCE;

        private:
            ScoreManager();
            ScoreManager(const ScoreManager&) = delete;
            ScoreManager& operator = (const ScoreManager&) = delete;

        public:
            static ScoreManager* getInstance();
    }; 
}