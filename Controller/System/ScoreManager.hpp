#pragma once

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace systems{
    class ScoreManager {
        private:
            sf::Clock CClock;

        public:
            void logStartTime();
            void logEndTime();

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