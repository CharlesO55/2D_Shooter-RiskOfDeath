#pragma once

#include "../../Config/Settings.hpp"
#include <fstream>

namespace systems{
    class PlayerManager{
        private:
            int nHealth = MAX_PLAYER_HEALTH;
            std::string strPlayerName = DEFAULT_PLAYER_NAME;

        public:
            int getHealth();
            std::string getPlayerName();

            void changeHealthBy(int nChange);
            void setPlayerName(std::string strPlayerName); 

            void checkEndGame();
            void reset();


        public:
            static PlayerManager* getInstance();

        private:
            static PlayerManager* P_SHARED_INSTANCE;

            PlayerManager();
            PlayerManager(const PlayerManager&) = delete;
            PlayerManager& operator = (const PlayerManager&) = delete;
    };
}