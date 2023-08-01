#ifndef INTERFACES_BLINKABLE_HPP
#define INTERFACES_BLINKABLE_HPP

#include "../../../AnimatedTexture.hpp"

namespace components{
    class Blinker;
}

namespace interfaces {
    using namespace models;

    class Blinkable {
        protected:
            components::Blinker* pBlinker;

        public:
            ~Blinkable() {}

        public:
            virtual void blink() = 0;

        public:
            components::Blinker* getBlinker() { return this->pBlinker;}
    };
}

#endif