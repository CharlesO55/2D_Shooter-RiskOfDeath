#ifndef INTERFACES_BLINKABLE_HPP
#define INTERFACES_BLINKABLE_HPP

#include "../../../AnimatedTexture.hpp"

namespace interfaces {
    using namespace models;

    class Blinkable {
        public:
            ~Blinkable() {}

        public:
            virtual void blink() = 0;
    };
}

#endif