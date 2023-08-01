#pragma once

#include "../GameObject.hpp"

#include "../Component/Renderer/RendererSpawnable.hpp"
#include "../Component/Script/ScriptBlocker.hpp"

namespace models{

    class Blocker : public GameObject {
        private:
            sf::Vector3f vecScenePos;

        public:
            Blocker(std::string strName, AnimatedTexture* pTexture);
            ~Blocker();

        public:
            void initialize();
    };
}
