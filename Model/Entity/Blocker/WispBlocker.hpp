#ifndef MODELS_WISP_BLOCKER_HPP
#define MODELS_WISP_BLOCKER_HPP

#include "BaseBlocker.hpp"
#include "../../Component/Script/MoveXY.hpp"

namespace models{
    class WispBlocker : public BaseBlocker{
        private:
            sf::Vector2f vecStartDir;
            
        public:
            WispBlocker(std::string strName, sf::FloatRect CArea = sf::FloatRect(0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2), sf::Vector2f vecDir = {1, 0}, float fZMin = 20, float fZMax = 50);
            ~WispBlocker();

        public:
            void initialize();
            void createHitboxes();
    };
}

#endif