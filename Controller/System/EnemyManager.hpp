#ifndef SYSTEMS_ENEMY_MANAGER_HPP
#define SYSTEMS_ENEMY_MANAGER_HPP

#include "../../Model/Component/Component.hpp"
#include "../../Model/Component/Input/CrosshairMouseInput.hpp"
#include "../../Model/Component/Script/Killable.hpp"

#include "../../Model/Pooling/Enemy/BaseEnemy.hpp"
#include "../../Model/Enum/EnumPoolTag.hpp"
#include "../../Model/Entity/Crosshair.hpp"
#include "../../Model/GameObject.hpp"

#include "../Pooling/GameObjectPool.hpp"

#include "ViewManager.hpp"

// #   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
// #   endif

namespace systems {
    using namespace components;
    using namespace models;

    class EnemyManager : public Component {
        private:
            float fTime = 0.0f;
            std::vector<Killable*> vecKillable;

        public:
            void kill(sf::Vector2f vecLocation);
            void killAll();

            void perform();
            void spawnWave();

            void registerComponent(Killable* pKillable);
            void unregisterComponent(Killable* pKillable);

            bool isLocInSprite(GameObject* pTarget, sf::Vector2f vecLocation);
            void switchEnemiesTexture(ViewTag EDir);
            

        private:
            static EnemyManager* P_SHARED_INSTANCE;

        private:
            EnemyManager(std::string strName);
            EnemyManager(const EnemyManager&);
            EnemyManager& operator = (const EnemyManager&);

        public:
            static EnemyManager* getInstance();
            static void initialize(std::string strName, GameObject* pParent);
    };
}

#endif