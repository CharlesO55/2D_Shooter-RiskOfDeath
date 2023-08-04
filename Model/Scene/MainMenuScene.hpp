#ifndef SCENES_MAIN_MENU_SCENE_HPP
#define SCENES_MAIN_MENU_SCENE_HPP

#include "../../View/Screen/MainMenu.hpp"
#include "../../View/Screen/LoadingScreen.hpp"
#include "../Scene.hpp"


namespace scenes {
    using namespace models;
    using namespace views;

    class MainMenuScene : public Scene {
        public:
            MainMenuScene();
            ~MainMenuScene();

        private:
            // void createBackground();

        public:
            void onLoadObjects();
            void onLoadResources();
            void onUnloadResources();
    };
}

#endif