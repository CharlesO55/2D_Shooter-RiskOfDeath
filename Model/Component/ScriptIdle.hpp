#pragma once

#include "Component.hpp"
#include "../../Config/Settings.h"

namespace components{
    class ScriptIdle : public Component{
        private:
            sf::Vector2f vecDir;
            sf::Vector2f vecMinBounds;
            sf::Vector2f vecMaxBounds;
            float fSpeed;

            sf::Time CTime;

        public:
            ScriptIdle(std::string strName, models::GameObject* pOwner, sf::Vector2f vecMinBounds = {0.f, 0.f}, sf::Vector2f vecMaxBounds =  {SCREEN_WIDTH, SCREEN_HEIGHT}, float fSpeed = 50.f);

            void assignOnUpdate(sf::Time CTime){this->CTime = CTime;};
            void perform();
    };
}