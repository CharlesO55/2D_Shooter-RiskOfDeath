#ifndef SYSTEMS_BLOCKER_MANAGER_HPP
#define SYSTEMS_BLOCKER_MANAGER_HPP

#include "../../Model/Component/Component.hpp"


#include "../../Model/Entity/Crosshair.hpp"
#include "../../Model/Entity/Blocker/BaseBlocker.hpp"
#include "../../Model/Component/Input/CrosshairMouseInput.hpp"

#include "../Singleton/GameObjectManager.hpp"

namespace systems{
    using namespace components;

    class BlockerManager : public Component{
        private:
            CrosshairMouseInput *pCrosshairRef;
            std::vector <BaseBlocker*> vecBlockers;

        public:
            void perform();
            void registerBlocker(BaseBlocker* pBlocker);
            void unregisterAll();

        private:
            // void findCrosshairRef();

        private:
            static BlockerManager* P_SHARED_INSTANCE;

            BlockerManager(std::string strName);
            BlockerManager(const BlockerManager&) = delete;
            BlockerManager& operator = (const BlockerManager&) = delete; 

        public:
            static BlockerManager* getInstance();
            static void initialize(std::string strName, GameObject* pHolder);
    };
}

#endif