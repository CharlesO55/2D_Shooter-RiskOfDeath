#ifndef MODELS_ENEMY_SLIME_HPP
#define MODELS_ENEMY_SLIME_HPP

#include "BaseEnemy.hpp"

namespace models {
    using namespace components;
    using namespace systems;

    class EnemySlime : public BaseEnemy {
        public:
            EnemySlime(std::string strName, AnimatedTexture* pTexture);

        public:
            PoolableObject* clone();
    };
}

#endif