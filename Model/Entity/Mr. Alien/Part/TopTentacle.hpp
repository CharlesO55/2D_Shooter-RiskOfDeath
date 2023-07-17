#ifndef MODELS_TOP_TENTACLE_HPP
#define MODELS_TOP_TENTACLE_HPP

#include "../../../GameObject.hpp"
#include "../../../Component/Component.hpp"
#include "../../../Component/Script/IdleMovement.hpp"

namespace models {
    using namespace components;
    
    class TopTentacle : public GameObject {
        public:
            TopTentacle(std::string strName, AnimatedTexture* pTexture);
            ~TopTentacle();

        public:
            void initialize();
    };
}

#endif