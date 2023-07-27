#ifndef MODELS_PIERCING_SHOT_HPP
#define MODELS_PIERCING_SHOT_HPP

#include "BaseItem.hpp"

namespace models {
    using namespace components;
    using namespace systems;

    class PiercingShot : public BaseItem {
        public:
            PiercingShot(std::string strName, AnimatedTexture* pTexture);

        public:
            PoolableObject* clone();
    };
}

#endif