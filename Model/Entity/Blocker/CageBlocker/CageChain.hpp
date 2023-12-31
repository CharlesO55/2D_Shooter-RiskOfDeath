#ifndef MODELS_CAGE_CHAIN_HPP
#define MODELS_CAGE_CHAIN_HPP

#include "../../../GameObject.hpp"

#include "../../../Component/Renderer/RendererSpawnable.hpp"
#include "../../../Component/Renderer/ScenePosInterpreter.hpp"
#include "../../../Component/Script/Interface/Positionable.hpp"

#include "../../../Controller/Singleton/TextureManager.hpp"

namespace models{
    class CageChain : public BaseBlocker{
        public:
            CageChain(std::string strName);
            ~CageChain();
        
        public:
            void initialize();
            void createHitboxes();
    };
}

#endif