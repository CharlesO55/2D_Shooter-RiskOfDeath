#pragma once

namespace interfaces{
    class Shootable{
        public:
            ~Shootable(){};

        public:
            virtual void onShot(int nKnockbackPower = 5) = 0;
            virtual bool isVecInHitbox(sf::Vector2f vecLoc) = 0; 
    };
}