#ifndef CONTROLLERS_GAME_H
#define CONTROLLERS_GAME_H

#include "../Config/Settings.hpp"
#include "../Model/Enum/EnumSceneTag.hpp"

#include "Singleton/GameObjectManager.hpp"
#include "Singleton/TextureManager.hpp"
#include "Singleton/MusicManager.hpp"
#include "Singleton/SFXManager.hpp"
#include "Singleton/FontManager.hpp"

#include "System/SceneManager.hpp"

#include "../Model/Scene/MainMenuScene.hpp"
#include "../Model/Scene/GameProper.hpp"
#include "../Model/Scene/LeaderboardScene.hpp"
#include "../Model/Scene/LoadingScene.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace controllers {
    using namespace models;
    using namespace scenes;
    using namespace systems;

    class Game {
        private:
            sf::RenderWindow rwWindow;

        public:
            Game();

        public:
            void run();
        
        private:
            void processEvents();
            void update(sf::Time tDeltaTime);
            void render();
    };
}

#endif