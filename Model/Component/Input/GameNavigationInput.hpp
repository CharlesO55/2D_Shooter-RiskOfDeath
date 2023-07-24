#pragma once

#include "GeneralInput.hpp"

namespace components{
    class GameNavigationInput : public GeneralInput{
        public:
            bool bChangeToFront = false; 
            bool bChangeToRight = false; 

        public:
            GameNavigationInput(std::string strName);
            ~GameNavigationInput();

        public:
            void perform();

        private:
            void processKeyInput();

        public:
            bool isNeedChangeFront();
            bool isNeedChangeRight();
            void resetAllFlags();
    };
}