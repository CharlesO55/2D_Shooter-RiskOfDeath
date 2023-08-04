#ifndef COMPONENTS_CROSSHAIR_MOUSE_INPUT_HPP
#define COMPONENTS_CROSSHAIR_MOUSE_INPUT_HPP

#include "../../../Config/Settings.hpp"
#include "../../Enum/EnumComponentType.hpp"

#include "../../../Controller/Singleton/SFXManager.hpp"
#include "../../Scene.hpp"

#include "GeneralInput.hpp"
#include "GameNavigationInput.hpp"

namespace components {
    using namespace controllers;
    class CrosshairMouseInput : public GeneralInput {
        private:
            bool bLeftClick;
            bool bRightClick;
            sf::Vector2f vecLocation;
            bool bResetFlags = false;

        public:
            CrosshairMouseInput(std::string strName);

        public:
            void perform();
            void resetLeftClick();
            void resetRightClick();
            void flagForReset();
            
        private:
            void processMouseInput(sf::Mouse::Button inMouse, bool bPressed);

        public:
            bool isLeftClick();
            bool isRightClick();
            sf::Vector2f getLocation();
    };
}

#endif