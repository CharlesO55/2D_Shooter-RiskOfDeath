#ifndef MODELS_INFINITY_AMMO_HPP
#define MODELS_INFINITY_AMMO_HPP

#include "BaseItem.hpp"

namespace models {
    using namespace components;
    using namespace systems;

    class InfinityAmmo : public BaseItem {
        public:
            InfinityAmmo(std::string strName, AnimatedTexture* pTexture);

        public:
            PoolableObject* clone();
    };
}

#endif