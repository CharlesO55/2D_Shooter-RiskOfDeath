#pragma once

#include "ScrollBlocker.hpp"
#include "../../Component/Script/MoveScroll.hpp"

namespace models{
    class PlaneBlocker : public ScrollBlocker{ //TO BE REMOVED
        private:
            sf::Vector2f vecStartDir;
            
        public:
            PlaneBlocker(sf::FloatRect CArea = sf::FloatRect(0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2), float fZMin = 20, float fZMax = 50);
            ~PlaneBlocker();

        public:
            void initialize();
    };
}