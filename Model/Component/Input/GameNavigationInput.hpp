#pragma once

#include "GeneralInput.hpp"
#include "../../../Controller/System/ViewManager.hpp"
#include "../../../Controller/Singleton/GameStateManager.hpp"

//DeBuG Utility
#include "../../../Controller/Singleton/GameObjectManager.hpp"

namespace components{
    class GameNavigationInput : public GeneralInput{
        private:
            bool bChangeToFront = false; 
            bool bChangeToRight = false; 
            bool bZoomClick = false;
            bool bZooming = false;
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
            void processDebugCommand();

        public:
            bool isNeedChangeFront();
            bool isNeedChangeRight();

            bool isZoomClick();
            bool isZooming();
            void setZooming(bool bState);

            void resetAllFlags();
            sf::Vector2f getMouseLoc();
    };
}