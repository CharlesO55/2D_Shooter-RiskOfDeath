#ifndef SCENES_GAME_PROPER_HPP
#define SCENES_GAME_PROPER_HPP

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
#include "../Pooling/Items/InfinityAmmo.hpp"
#include "../Pooling/Items/InstantKill.hpp"

#include "../EmptyGameObject.hpp"

#include "../Component/Input/GameNavigationInput.hpp"
#include "../Component/Input/PlayerInput.hpp"
#include "../Component/Script/GameScreenNavigation.hpp"

#include "../../View/Screen/PlayerUI.hpp"
#include "../../View/Screen/FrontViewScreen.hpp"
#include "../../View/Screen/SideViewScreen.hpp"
#include "../../View/Screen/PauseScreen.hpp"

#include "../../Controller/System/BlockerManager.hpp"
#include "../../Controller/System/ObjectPoolManager.hpp"
#include "../../Controller/System/ScoreManager.hpp"
#include "../../Controller/System/LayerManager.hpp"

#include "../Entity/Blocker/BaseBlocker.hpp"
#include "../Entity/Blocker/BoulderBlocker.hpp"
#include "../Entity/Blocker/CageBlocker/CageBlocker.hpp"
#include "../Entity/Blocker/CageBlocker/CageChain.hpp"
#include "../Entity/Blocker/ShadowBlocker.hpp"
#include "../Entity/Blocker/WispBlocker.hpp"

namespace scenes{
    using namespace models;
    using namespace systems;

    class GameProper : public Scene{        
        public:
            GameProper();
            ~GameProper();

        public:
            void onLoadObjects();
            void onLoadResources();
            void onUnloadResources();

        public:
            void createNullObjectComponents();
            void createCrosshair();
            void createBlockers();
            void createObjectPools();
            void createLayerManagerAsLast();
    };
}

#endif