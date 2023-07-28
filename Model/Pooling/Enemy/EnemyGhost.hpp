#ifndef MODELS_ENEMY_GHOST_HPP
#define MODELS_ENEMY_GHOST_HPP

#include "BaseEnemy.hpp"

namespace models {
    using namespace components;
    using namespace systems;

    class EnemyGhost : public BaseEnemy {
        public:
            EnemyGhost(std::string strName, AnimatedTexture* pTexture);

        public:
            void onRelease();
            PoolableObject* clone();
    };
}

#endif