#pragma once

#include "../../View/Screen/MainMenu.hpp"
#include "../Scene.hpp"


namespace scenes {
    using namespace models;
    using namespace views;

    class LeaderboardScene : public Scene {
        public:
            LeaderboardScene();
            ~LeaderboardScene();

        private:
            void createBackground(){};

        public:
            void onLoadObjects();
    };
}