#pragma once

#include "GeneralInput.hpp"
#include "../../../Controller/System/ViewManager.hpp"
#include "../../../Controller/Singleton/GameStateManager.hpp"

namespace components{
    class GameNavigationInput : public GeneralInput{
        public:
            bool bChangeToFront = false; 
            bool bChangeToRight = false; 
            bool bZoomClick = false;
            
            sf::Vector2f vecMousePos;

        public:
            GameNavigationInput(std::string strName);
            ~GameNavigationInput();

        public:
            void perform();

        private:
            void processKeyInput();
            void processMouseInput();
            void processScreenPause();

        public:
            bool isNeedChangeFront();
            bool isNeedChangeRight();
            bool isZoomClick();
            void resetAllFlags();
            sf::Vector2f getMouseLoc();
    };
}