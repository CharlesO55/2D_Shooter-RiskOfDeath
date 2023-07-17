#ifndef SCENES_GAME_SCENE_HPP
#define SCENES_GAME_SCENE_HPP

#include "../../Config/Settings.hpp"

#include "../../Controller/Singleton/TextureManager.hpp"
#include "../../Controller/Singleton/SFXManager.hpp"
#include "../../Controller/Singleton/FontManager.hpp"

#include "../../Controller/System/ObjectPoolManager.hpp"
#include "../../Controller/System/PhysicsManager.hpp"
#include "../../Controller/System/ViewManager.hpp"

#include "../../Controller/Pooling/GameObjectPool.hpp"

#include "../Enum/EnumAssetType.hpp"
#include "../Enum/EnumSceneTag.hpp"

#include "../AnimatedTexture.hpp"
#include "../Scene.hpp"
#include "../Pooling/Bullet/PlayerBullet.hpp"
#include "../AnimatedTexture.hpp"
#include "../EmptyGameObject.hpp"
#include "../Entity/Background.hpp"
#include "../Entity/Ship.hpp"
#include "../Entity/Mr. Alien/MrAlien.hpp"
#include "../Entity/Mr. Alien/Part/BottomStamen.hpp"
#include "../Entity/Mr. Alien/Part/BottomTentacle.hpp"
#include "../Entity/Mr. Alien/Part/TopStamen.hpp"
#include "../Entity/Mr. Alien/Part/TopTentacle.hpp"
#include "../Entity/Border/Border.hpp"

#include "../../View/Screen/MenuBar.hpp"

namespace scenes {
    using namespace controllers;
    using namespace models;
    using namespace systems;
    using namespace views;

    class GameScene : public Scene {
        public:
            GameScene();
            ~GameScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
        
        private:
            void createNullObjectComponents();
            void createObjectPools();
            void createUserInterface();
            void createBackground();
            void createShip();
            void createAlien();
            void createBorders();
    };
}

#endif