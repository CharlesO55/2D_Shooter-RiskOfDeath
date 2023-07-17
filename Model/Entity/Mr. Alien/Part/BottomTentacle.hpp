#ifndef MODELS_BOTTOM_TENTACLE_HPP
#define MODELS_BOTTOM_TENTACLE_HPP

#include "../../../GameObject.hpp"
#include "../../../Component/Component.hpp"
#include "../../../Component/Script/IdleMovement.hpp"

namespace models {
    using namespace components;
    
    class BottomTentacle : public GameObject {
        public:
            BottomTentacle(std::string strName, AnimatedTexture* pTexture);
            ~BottomTentacle();

        public:
            void initialize();
    };
}

#endif