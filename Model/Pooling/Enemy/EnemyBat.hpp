#ifndef MODELS_ENEMY_BAT_HPP
#define MODELS_ENEMY_BAT_HPP

#include "BaseEnemy.hpp"

namespace models {
    using namespace components;
    using namespace systems;

    class EnemyBat : public BaseEnemy {
        public:
            EnemyBat(std::string strName, AnimatedTexture* pTexture);

        public:
            void onRelease();
            PoolableObject* clone();
    };
}

#endif