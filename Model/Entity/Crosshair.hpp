#ifndef MODELS_CROSSHAIR_HPP
#define MODELS_CROSSHAIR_HPP

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"

#include "../Component/Input/CrosshairMovement.hpp"
#include "../Component/Input/CrosshairMouseInput.hpp"

#include "../Component/Renderer/Renderer.hpp"

namespace models {
    class Crosshair : public GameObject {
        public:
            Crosshair(std::string strName, AnimatedTexture* pTexture);
            ~Crosshair();

        public:
            void initialize();
    };
}

#endif