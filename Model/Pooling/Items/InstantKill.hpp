#ifndef MODELS_INSTANT_KILL_HPP
#define MODELS_INSTANT_KILL_HPP

#include "BaseItem.hpp"

namespace models {
    using namespace components;
    using namespace systems;

    class InstantKill : public BaseItem {
        public:
            InstantKill(std::string strName, AnimatedTexture* pTexture);

        public:
            PoolableObject* clone();
    };
}

#endif