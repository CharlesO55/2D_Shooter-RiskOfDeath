#pragma once

#include "../Component.hpp"
#include "Interface/Positionable.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace components{
    class MoveScroll : public Component{
        private:
            sf::Vector2f vecMoveDir;
            float fMaxDistance;
            float fTravelled = 0;
            float fSpeed;
        
        public:
            MoveScroll(std::string strName, float fMaxDistance, sf::Vector2f vecMoveDir, float fSpeed = 50, bool bReversed = false);
            ~MoveScroll();

        public:
            void perform();
    };
}