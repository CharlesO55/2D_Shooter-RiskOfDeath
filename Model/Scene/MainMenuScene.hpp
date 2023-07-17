#ifndef SCENES_MAIN_MENU_SCENE_HPP
#define SCENES_MAIN_MENU_SCENE_HPP

#include "../../View/Screen/MainMenu.hpp"
#include "../Scene.hpp"


namespace scenes {
    using namespace models;
    using namespace views;

    class MainMenuScene : public Scene {
        public:
            MainMenuScene();
            ~MainMenuScene();

        private:
            void createBackground();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
    };
}

#endif