#pragma once

#include "../../GameObject.hpp"

#include "../../Enum/EnumBlockerType.hpp"

#include "../../Component/Renderer/RendererSpawnable.hpp"
#include "../../Component/Renderer/ScenePosInterpreter.hpp"
#include "../../Component/Script/Interface/Positionable.hpp"

#include "../../../Controller/Singleton/TextureManager.hpp"

#include "../../Component/Script/ScriptBlocker.hpp"


#include <SFML/Graphics.hpp>

namespace models{
    using namespace interfaces;
    class ScrollBlocker : public GameObject , public Positionable { //TO BE REMOVED
        protected:
            EnumBlockerType Etype;
            bool bIsReversed;

            sf::FloatRect CArea;
            float fZMin;
            float fZMax;

        public:
            ScrollBlocker(std::string strName, AnimatedTexture* pTexture, EnumBlockerType Etype, float fDefaultScale = 1.f);
            ~ScrollBlocker();

        public:
            virtual void initialize();

            void randomizeSpawn(sf::FloatRect CArea = sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), float fZMin = 20, float fZMax = 80);

        protected:
            int nRNG(int nMin, int nMax);

        public:

            EnumBlockerType getEType() {return this->Etype; }
            bool getIsReversed() {return this->bIsReversed; }
            sf::FloatRect getCArea() { return this->CArea; }
            float getZMin(){ return this->fZMin; }
            float getZMax(){ return this->fZMax; }
    };
}