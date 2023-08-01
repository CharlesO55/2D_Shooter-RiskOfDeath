#pragma once

#include "../../GameObject.hpp"

#include "../../Component/Renderer/RendererSpawnable.hpp"
#include "../../Component/Renderer/ScenePosInterpreter.hpp"


#include "../../Component/Script/ScriptBlocker.hpp"

#include <SFML/Graphics.hpp>

namespace models{

    class Blocker : public GameObject {
        private:
            sf::Vector3f vecScenePos;

        public:
            Blocker(std::string strName, AnimatedTexture* pTexture);
            ~Blocker();

        public:
            void initialize();

        protected:
            void randomizeSpawn(sf::FloatRect CArea = sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    };
}