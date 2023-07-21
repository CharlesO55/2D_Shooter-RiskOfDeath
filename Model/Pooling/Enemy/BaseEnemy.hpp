#ifndef MODELS_BASE_ENEMY_HPP
#define MODELS_BASE_ENEMY_HPP

#include "../../AnimatedTexture.hpp"
#include "../../GameObject.hpp"

#include "../../Component/Renderer/Renderer.hpp"
#include "../../Component/Script/Killable.hpp"

#include "../PoolableObject.hpp"

#include "../../../Controller/System/ObjectPoolManager.hpp"
#include "../../../Controller/System/PhysicsManager.hpp"

namespace models {
    using namespace components;
    using namespace systems;

    class BaseEnemy : public PoolableObject {
        private:
            int nHealth;
            float fSpeed;
            float fKillableSpeed;

        public:
            BaseEnemy(std::string strName, AnimatedTexture* pTexture, PoolTag ETag);

        public:
            void initialize();
            void onActivate();
            void onRelease();
            PoolableObject* clone();

        private:
            void randomizePosition();

        public:
            float getSpeed();
            int getHealth();
            void setHealth(int nHealth);
    };
}

#endif