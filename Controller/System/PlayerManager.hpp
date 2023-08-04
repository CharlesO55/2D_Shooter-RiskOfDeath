#ifndef SYSTEMS_PLAYER_MANAGER_HPP
#define SYSTEMS_PLAYER_MANAGER_HPP

#include "../../Config/Settings.hpp"

#include "../../Model/Component/Component.hpp"
#include "../../Model/Component/Input/CrosshairMouseInput.hpp"
#include "../../Model/Component/Script/Interface/Shootable.hpp"

#include "../../View/Screen/PlayerUI.hpp"

#include "../../Controller/Singleton/SFXManager.hpp"
#include "../../Controller/Singleton/GameObjectManager.hpp"
#include "../../Controller/System/LayerManager.hpp"
#include "../../Controller/System/ItemManager.hpp"



#include <fstream>

namespace systems{
    using namespace components;

    class PlayerManager : public Component{
        private:
            CrosshairMouseInput* pCrosshairRef = NULL; //External reference from GameObjects
            PlayerUI* pUI_Ref = NULL;

        private:
            int nBullets;
            bool bReloading = false;
            int nHealth = MAX_PLAYER_HEALTH;
            
            float fTicks = 0.0f;

            std::string strPlayerName = DEFAULT_PLAYER_NAME;

        public:
            void perform();
            void reload(float fTime);
            void shoot();

        private:
            void findDependencies();    //PSEUDO INITIALIZER
            void checkEndGame();

            bool isAmmoEmpty();

        public:
            int getHealth();
            std::string getPlayerName();

            void healPlayer();
            void damagePlayer();

            int getBullets();
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