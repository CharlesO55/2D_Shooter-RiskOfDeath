#pragma once

#include "../Component.hpp"
#include "Interface/Positionable.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace components{
    class MoveXY : public Component{
        private:
            bool bRotate;
            bool bCanFlip;
            sf::Vector2f vecMoveDir;
            float fMaxDistance;
            float fTravelled = 0;
            float fSpeed;
        
        public:
            MoveXY(std::string strName, float fMaxDistance, sf::Vector2f vecMoveDir = {1, 0}, float fSpeed = 50, bool bRotating = false, bool bCanFlip = false);
            ~MoveXY();

        public:
            void perform();
    };
}