#ifndef COMPONENTS_SHIP_INPUT_HPP
#define COMPONENTS_SHIP_INPUT_HPP

#include "GeneralInput.hpp"

namespace components {
    class ShipInput : public GeneralInput {
        private:
            bool bSpace;
            bool bUp;
            bool bDown;
            bool bLeft;
            bool bRight;
            
        public:
            ShipInput(std::string strName);

        public:
            void perform();
            void resetSpace();

        private:
            void processKeyInput(bool bPressed);

        public:
            bool isSpace();
            bool isUp();
            bool isDown();
            bool isLeft();
            bool isRight();
    };
}

#endif