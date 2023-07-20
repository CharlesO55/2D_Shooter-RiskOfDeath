#pragma once

#include "../Scene.hpp"
#include "../Entity/Crosshair.hpp"

#include "../../View/Screen/FrontViewUI.hpp"

#include "../../Controller/System/ScoreManager.hpp"

namespace scenes{
    using namespace models;

    class GameProper : public Scene{
        public:
            GameProper();
            ~GameProper();

        public:
            void onLoadObjects();

        public:
            void createCrosshair();
    };
}