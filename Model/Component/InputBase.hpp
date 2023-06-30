#pragma once

#include "Component.hpp"
namespace components{
    class InputBase : public Component{
        private:
            sf::Event EEvent;

        public:
            InputBase(std::string strName, models::GameObject* pOwner);
            virtual void perform() = 0;

            void assignOnProcessInput(sf::Event EEvent);
    };
}