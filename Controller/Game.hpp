#pragma once

#include <SFML/Graphics.hpp>
#include "../Config/Settings.h"

#include "Singleton/TextureManager.hpp"
#include "Singleton/GameObjectManager.hpp"
#include "../Model/GameObject.hpp"
#include "../Model/Entity/Monster.hpp"

#include "../View/UI/TextButton.hpp"

namespace controllers {
    class Game{
        private:
            sf::RenderWindow CWindow;
            bool bEndGame = false;

            models::GameObject *pObj;

        public:
            Game();
            ~Game();
            void run();

        private:
            void processEvents();
            void update(sf::Time CTime);
            void render();
    };

        
}