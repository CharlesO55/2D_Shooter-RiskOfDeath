#ifndef SCENES_MAIN_MENU_SCENE_HPP
#define SCENES_MAIN_MENU_SCENE_HPP

#include "../../View/Screen/MainMenu.hpp"

namespace scenes {
    using namespace models;
    using namespace views;

    class MainMenuScene {
        public:
            MainMenuScene();
            ~MainMenuScene();

        private:
            void createBackground();
    };
}

#endif