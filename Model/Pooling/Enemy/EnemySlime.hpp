#ifndef MODELS_ENEMY_SLIME_HPP
#define MODELS_ENEMY_SLIME_HPP

#include "BaseEnemy.hpp"

namespace models {
    using namespace components;
    using namespace systems;

    class EnemySlime : public BaseEnemy {
        private:
            int nHealth;
            float fSpeed;
            float fKillableSpeed;

        public:
            EnemySlime(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
            void onActivate();
            void onRelease();
            PoolableObject* clone();

        private:
            void randomizePosition();
    };
}

#endif