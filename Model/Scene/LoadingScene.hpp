#pragma once

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