#ifndef VIEWS_MAIN_MENU_HPP
#define VIEWS_MAIN_MENU_HPP

#include "../../Config/Settings.hpp"

#include "../Button.hpp"
#include "../Image.hpp"
#include "../Text.hpp"
#include "../View.hpp"

#include "../../Model/AnimatedTexture.hpp"
#include "../../Model/Enum/EnumAssetType.hpp"
#include "../../Model/Enum/EnumFontType.hpp"
#include "../../Model/Enum/EnumSceneTag.hpp"
#include "../../Model/Enum/EnumViewTag.hpp"

#include "../../Controller/Singleton/TextureManager.hpp"
#include "../../Controller/Singleton/FontManager.hpp"
#include "../../Controller/System/ViewManager.hpp"

namespace views {
    using namespace controllers;
    using namespace models;
    using namespace systems;

    class MainMenu : public View, public ButtonListener {
        private:
            Text* pText;

        public:
            MainMenu();
            ~MainMenu();
        
        public:
            void initialize();
            void onClick(Button* pButton);
            void onRelease(Button* pButton);
    };
}

#endif