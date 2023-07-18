#ifndef VIEWS_VIEW_HPP
#define VIEWS_VIEW_HPP

#include "../Model/AnimatedTexture.hpp"
#include "../Model/GameObject.hpp"
#include "../Model/Enum/EnumViewTag.hpp"

#include "Image.hpp"
#include "../Config/Settings.hpp"
#include "../Controller/Singleton/TextureManager.hpp"
#include "Interface/ButtonListener.hpp"

namespace views {
    using namespace models;

    class View : public GameObject {
        protected:
            ViewTag ETag;

        public:
            View(ViewTag ETag, std::string strName);
            ~View();

        protected:
            void createImage(std::string strName, AnimatedTexture* pTexture, float fScale = 1.0f, float fX = 0.0f, float fY = 0.0f);
            void createButton(listeners::ButtonListener* pListener, std::string strName, AssetType EAsset, sf::Vector2f vecPos, float fScale = 1.f);

        public:
            ViewTag getTag();
    };
}

#endif