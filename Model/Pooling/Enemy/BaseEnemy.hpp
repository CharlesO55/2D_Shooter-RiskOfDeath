#ifndef MODELS_BASE_ENEMY_HPP
#define MODELS_BASE_ENEMY_HPP

#include "../../AnimatedTexture.hpp"
#include "../../GameObject.hpp"

#include "../../Component/Renderer/Renderer.hpp"
#include "../../Component/Renderer/RendererSpawnable.hpp"
#include "../../Component/Renderer/ScenePosInterpreter.hpp"
#include "../../Component/Script/Killable.hpp"
#include "../../Component/Script/MoveForward.hpp"

#include "../PoolableObject.hpp"

#include "../../../View/Text.hpp"

#include "../../../Controller/System/ObjectPoolManager.hpp"
#include "../../../Controller/System/EnemyManager.hpp"

#include "../../Component/Script/Blinker.hpp"
#include "../../Component/Script/Interface/Positionable.hpp"
#include "../../Component/Script/Interface/Shootable.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace models {
    using namespace components;
    using namespace systems;
    using namespace interfaces;

    class BaseEnemy : public PoolableObject , public Blinkable, public Positionable, public Shootable {
        protected:
            int nHealth;
            int nMaxHealth;
            float fSpeed;
            float fSpeedScaling;
            Killable* pKillableRef;

        public:
            BaseEnemy(std::string strName, AnimatedTexture* pTexture, PoolTag ETag, int nHealth = 1, float fScale = 1.f, float fSpeed = 1.f, float fSpeedScaling = 0.1f);

        public:
            virtual void initialize();
            void onActivate();
            virtual void onRelease() = 0;
            virtual PoolableObject* clone() = 0;

            //INTERFACES
            void blink();
            void onShot(int nKnockbackPower = 5);
            bool isVecInHitbox(sf::Vector2f vecLoc); 

        protected:
            void randomizePosition();

        public:
            float getSpeed();
            void scaleSpeed();

            int getHealth();
            void setHealth(int nHealth);
    };
}

#endif