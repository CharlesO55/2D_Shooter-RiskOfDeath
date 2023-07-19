#ifndef VIEWS_MENU_BAR_HPP
#define VIEWS_MENU_BAR_HPP

#include "../Image.hpp"
#include "../Text.hpp"
#include "../View.hpp"

#include "../../Model/AnimatedTexture.hpp"
#include "../../Model/Enum/EnumAssetType.hpp"
#include "../../Model/Enum/EnumFontType.hpp"
#include "../../Model/Enum/EnumViewTag.hpp"

#include "../../Controller/Singleton/TextureManager.hpp"
#include "../../Controller/Singleton/FontManager.hpp"
#include "../../Controller/System/ViewManager.hpp"

#include "../Interface/ButtonListener.hpp"

namespace views {
    using namespace controllers;
    using namespace models;
    using namespace listeners;

    class MenuBar : public View , public ButtonListener{
        private:
            Text* pText;
            int nScore;
            int nHeart;

        public:
            MenuBar();
            ~MenuBar();
        
        public:
            void initialize();

        public:
            void incrementScore();
            void decrementHeart();

        public:
            void onClick(Button* pButton);
            void onRelease(Button* pButton){};
    };
}

#endif