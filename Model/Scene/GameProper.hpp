#pragma once

#include "../Scene.hpp"
#include "../Entity/Crosshair.hpp"
#include "../Pooling/Enemy/BaseEnemy.hpp"
#include "../Pooling/Enemy/EnemySlime.hpp"

#include "../EmptyGameObject.hpp"

#include "../Component/Input/GameNavigationInput.hpp"
#include "../Component/Script/GameScreenNavigation.hpp"


#include "../../View/Screen/PlayerUI.hpp"
#include "../../View/Screen/FrontViewScreen.hpp"
#include "../../View/Screen/SideViewScreen.hpp"

#include "../../Controller/System/ObjectPoolManager.hpp"
#include "../../Controller/System/ScoreManager.hpp"

namespace scenes{
    using namespace models;
    using namespace systems;

    class GameProper : public Scene{        
        public:
            GameProper();
            ~GameProper();

        public:
            void onLoadObjects();
        public:
            void createNullObjectComponents();
            void createCrosshair();
            void createObjectPools();
    };
}