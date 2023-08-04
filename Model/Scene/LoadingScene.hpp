#ifndef SCENES_LOADING_SCENE_HPP
#define SCENES_LOADING_SCENE_HPP

#include "../Scene.hpp"
#include "../../../View/Screen/LoadingScreen.hpp"

namespace scenes{
    using namespace models;
    class LoadingScene : public Scene{
        public:
            LoadingScene();
            ~LoadingScene();
        
        public:
            void onLoadObjects();
    };
}

#endif