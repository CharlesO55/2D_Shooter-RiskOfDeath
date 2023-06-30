#pragma once

#include "Component.hpp"

namespace components{
    class CompRenderer : public Component{
        private:
            sf::Drawable *pDrawable;
            sf::RenderWindow *pWindow;
            sf::RenderStates CTransform;

        public:
            CompRenderer(std::string strName, models::GameObject* pOwner);
            void assignOnDraw(sf::RenderWindow *pWindow, sf::RenderStates CTransform);

        public:
            void perform();
    };
}