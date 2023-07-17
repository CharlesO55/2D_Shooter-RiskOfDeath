#ifndef MODELS_BOTTOM_STAMEN_HPP
#define MODELS_BOTTOM_STAMEN_HPP

#include "../../../GameObject.hpp"
#include "../../../Component/Component.hpp"
#include "../../../Component/Script/IdleMovement.hpp"

namespace models {
    using namespace components;
    
    class BottomStamen : public GameObject {
        public:
            BottomStamen(std::string strName, AnimatedTexture* pTexture);
            ~BottomStamen();

        public:
            void initialize();
    };
}

#endif