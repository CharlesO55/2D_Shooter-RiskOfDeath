#ifndef SYSTEMS_ITEM_MANAGER_HPP
#define SYSTEMS_ITEM_MANAGER_HPP

#include "../../Model/Component/Component.hpp"
#include "../../Model/Component/Input/CrosshairMouseInput.hpp"
#include "../../Model/Component/Script/Obtainable.hpp"

#include "../../Model/Pooling/Items/BaseItem.hpp"
#include "../../Model/Enum/EnumPoolTag.hpp"
#include "../../Model/Entity/Crosshair.hpp"
#include "../../Model/GameObject.hpp"

#include "../Pooling/GameObjectPool.hpp"

namespace systems {
    using namespace components;
    using namespace models;

    class ItemManager : public Component {
        private:
            float fTime = 0.0f;
            std::vector<Obtainable*> vecObtainable;

        public:
            void obtain(sf::Vector2f vecLocation);
            void spawn();

            void perform();
            PoolTag getRandomPool();

            void registerComponent(Obtainable* pObtainable);
            void unregisterComponent(Obtainable* pObtainable);

        private:
            static ItemManager* P_SHARED_INSTANCE;

        private:
            ItemManager(std::string strName);
            ItemManager(const ItemManager&);
            ItemManager& operator = (const ItemManager&);

        public:
            static ItemManager* getInstance();
            static void initialize(std::string strName, GameObject* pParent);
    };
}

#endif