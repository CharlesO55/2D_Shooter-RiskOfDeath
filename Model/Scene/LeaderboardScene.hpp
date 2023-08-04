#ifndef SCENES_LEADERBOARD_SCENE_HPP
#define SCENES_LEADERBOARD_SCENE_HPP

#include "../../View/Screen/Leaderboard.hpp"
#include "../Scene.hpp"

namespace scenes {
    using namespace models;
    using namespace views;

    class LeaderboardScene : public Scene {
        public:
            LeaderboardScene();
            ~LeaderboardScene();

        public:
            void onLoadObjects();
            void onLoadResources();
            void onUnloadResources();
    };
}

#endif