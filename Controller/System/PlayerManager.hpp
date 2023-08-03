#ifndef SYSTEMS_PLAYER_MANAGER_HPP
#define SYSTEMS_PLAYER_MANAGER_HPP

#include "../../Model/Component/Component.hpp"
#include "../../Config/Settings.hpp"
#include <fstream>

namespace systems{
    using namespace components;

    class PlayerManager : public Component{
        private:
            bool bReloading = false;
            float fTicks = 0.0f;

            int nHealth = MAX_PLAYER_HEALTH;
            std::string strPlayerName = DEFAULT_PLAYER_NAME;

        public:
            void perform();
            void reload(float fTime);
            void checkEndGame();

        public:
            int getHealth();
            std::string getPlayerName();

            void healPlayer();
            void damagePlayer();

            bool isReloading();
            void setReloading(bool bState);

            void setPlayerName(std::string strPlayerName); 

        private:
            static PlayerManager* P_SHARED_INSTANCE;

        private:
            PlayerManager(std::string strName);
            PlayerManager(const PlayerManager&);
            PlayerManager& operator = (const PlayerManager&);

        public:
            static PlayerManager* getInstance();
            static void initialize(std::string strName, GameObject* pParent);
    };
}

#endif