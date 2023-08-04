#pragma once

#include "BaseBlocker.hpp"
#include "../../Component/Script/MoveXY.hpp"

namespace models{
    class CageBlocker : public BaseBlocker{
        private:
            sf::Vector2f vecStartDir;
            
        public:
            CageBlocker(std::string strName, sf::FloatRect CArea = sf::FloatRect(0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2), sf::Vector2f vecDir = {1, 0}, float fZMin = 20, float fZMax = 50);
            ~CageBlocker();

        public:
            void initialize();
            void createHitboxes();
    };
}