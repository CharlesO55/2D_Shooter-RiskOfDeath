#pragma once

#include "../Scene.hpp"
#include "../Entity/Crosshair.hpp"

#include "../Pooling/Enemy/BaseEnemy.hpp"
#include "../Pooling/Enemy/EnemySlime.hpp"
#include "../Pooling/Enemy/EnemyBat.hpp"
#include "../Pooling/Enemy/EnemyGhost.hpp"

#include "../Pooling/Items/BaseItem.hpp"
#include "../Pooling/Items/DamageBoost.hpp"
#include "../Pooling/Items/HealthBoost.hpp"
#include "../Pooling/Items/PiercingShot.hpp"

#include "../EmptyGameObject.hpp"

#include "../Component/Input/GameNavigationInput.hpp"
#include "../Component/Input/PlayerInput.hpp"
#include "../Component/Script/GameScreenNavigation.hpp"

#include "../../View/Screen/PlayerUI.hpp"
#include "../../View/Screen/FrontViewScreen.hpp"
#include "../../View/Screen/SideViewScreen.hpp"

#include "../../Controller/System/BlockerManager.hpp"
#include "../../Controller/System/ObjectPoolManager.hpp"
#include "../../Controller/System/ScoreManager.hpp"

#include "../Entity/Blocker/BaseBlocker.hpp"
#include "../Entity/Blocker/ScrollBlocker.hpp"
#include "../Entity/Blocker/BoulderBlocker.hpp"
#include "../Entity/Blocker/WispBlocker.hpp"
#include "../Entity/Blocker/PlaneBlocker.hpp"
#include "../Entity/Blocker/CloudBlocker.hpp"

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
            void createBlockers();
            void createObjectPools();
    };
}