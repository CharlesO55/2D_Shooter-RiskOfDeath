#ifndef MODELS_HEALTH_BOOST_HPP
#define MODELS_HEALTH_BOOST_HPP

#include "BaseItem.hpp"

namespace models {
    using namespace components;
    using namespace systems;

    class HealthBoost : public BaseItem {
        public:
            HealthBoost(std::string strName, AnimatedTexture* pTexture);

        public:
            PoolableObject* clone();
    };
}

#endif