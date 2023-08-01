#pragma once

#include "ScrollBlocker.hpp"
#include "../../Component/Script/MoveScroll.hpp"

namespace models{
    class CloudBlocker : public ScrollBlocker{
        private:
            sf::Vector2f vecStartDir;
            
        public:
            CloudBlocker(sf::FloatRect CArea = sf::FloatRect(0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2), float fZMin = 20, float fZMax = 50);
            ~CloudBlocker();

        public:
            void initialize();
    };
}