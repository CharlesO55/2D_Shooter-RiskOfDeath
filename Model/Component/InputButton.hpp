#pragma once

#include "Component.hpp"

namespace components{
    class InputButton : public Component{
        public:
            sf::Event EEvent;
        
        public:
            InputButton(std::string strName, models::GameObject* pButton);

        public:
            void assignOnProcessInput(sf::Event EEvent);
            void perform();

    };
}