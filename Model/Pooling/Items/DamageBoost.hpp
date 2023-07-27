#ifndef MODELS_DAMAGE_BOOST_HPP
#define MODELS_DAMAGE_BOOST_HPP

#include "BaseItem.hpp"

namespace models {
    using namespace components;
    using namespace systems;

    class DamageBoost : public BaseItem {
        public:
            DamageBoost(std::string strName, AnimatedTexture* pTexture);

        public:
            PoolableObject* clone();
    };
}

#endif