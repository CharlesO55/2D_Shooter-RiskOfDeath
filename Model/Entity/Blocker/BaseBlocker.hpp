#pragma once

#include "../../GameObject.hpp"

#include "../../Component/Renderer/RendererSpawnable.hpp"
#include "../../Component/Renderer/ScenePosInterpreter.hpp"

#include "../../Component/Script/Interface/Positionable.hpp"
#include "../../Component/Script/Interface/Shootable.hpp"

#include "../../../Controller/Singleton/TextureManager.hpp"

#include "../../Component/Script/ScriptBlocker.hpp"

#include "../../Hitbox.hpp"

#include <SFML/Graphics.hpp>

namespace models{
    using namespace interfaces;
    class BaseBlocker : public GameObject , public Positionable , public Shootable{
        protected:
            Hitbox* pHitbox;

        public:
            BaseBlocker(std::string strName, AnimatedTexture* pTexture, float fDefaultScale = 1.f);
            ~BaseBlocker();

        public:
            virtual void initialize() = 0;
            virtual void createHitboxes() = 0;    //turned to pure virutal
            virtual void onShot(int nKnockbackPower = 5);
            bool isVecInHitbox(sf::Vector2f vecLoc);

        // private:
            // bool isColliding(sf::Vector2f vecMouse);

        protected:
            void randomizeSpawn(sf::FloatRect CArea = sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), float fZMin = 20, float fZMax = 80);
            int nRNG(int nMin, int nMax);
    };
}