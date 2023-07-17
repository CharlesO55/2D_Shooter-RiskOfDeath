#ifndef MODELS_TOP_STAMEN_HPP
#define MODELS_TOP_STAMEN_HPP

#include "../../../GameObject.hpp"
#include "../../../Component/Component.hpp"
#include "../../../Component/Script/IdleMovement.hpp"

namespace models {
    using namespace components;
    
    class TopStamen : public GameObject {
        public:
            TopStamen(std::string strName, AnimatedTexture* pTexture);
            ~TopStamen();

        public:
            void initialize();
    };
}

#endif