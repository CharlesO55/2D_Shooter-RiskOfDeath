#ifndef MODELS_BACKGROUND_HPP
#define MODELS_BACKGROUND_HPP

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"

#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Renderer/Animator.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace models {
    using namespace components;

    class Background : public GameObject {
        public:
            Background(std::string strName, AnimatedTexture* pTexture);
            ~Background();
            
        public:
            void initialize();
            // void draw(sf::RenderWindow* pWindow, sf::RenderStates CRenderStates);
    };
}

#endif