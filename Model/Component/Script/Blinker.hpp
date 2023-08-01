#ifndef COMPONENTS_BLINKER_HPP
#define COMPONENTS_BLINKER_HPP

#include "../../Enum/EnumComponentType.hpp"
#include "../Component.hpp"
#include "Interface/Blinkable.hpp"

namespace components {
    using namespace interfaces;

    class Blinker : public Component {
        private:
            Blinkable* pBlinkable;
            bool bBlinking;
            int nBlinkCount;
            int nMaxBlinks;

            float fFrameInterval;
            float fTicks;

        public:
            Blinker(std::string strName);

        public:
            void perform();
            void start();
        
        private:
            void blink();
            void reset();

        public:
            void setBlinkable(Blinkable* pBlinkable);
            bool isBlinking();
            int getBlinksRemaining();
    };
}

#endif