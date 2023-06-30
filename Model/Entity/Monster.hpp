#pragma once

#include "../GameObject.hpp"

namespace entities{
    using namespace models;

    class Monster : public GameObject{
        public:
            Monster(sf::Texture* pTexture, std::string strName, GameObject* pParent = NULL, float fX = 0, float fY = 0);
            
        public:
            void initialize();
            void update(sf::Time CTime);
    };
}