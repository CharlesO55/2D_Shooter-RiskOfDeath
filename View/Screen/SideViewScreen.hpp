#pragma once


#include "../View.hpp"
#include "../Interface/ButtonListener.hpp"
#include "../../Controller/System/ViewManager.hpp"
#include "../../Controller/Singleton/TextureManager.hpp"

#include "../Text.hpp"

#include "../../Model/Entity/Background.hpp"

namespace views{
    using namespace listeners;
    class SideViewScreen : public View{
        public:
            SideViewScreen();
            ~SideViewScreen();

        public:
            void initialize();
            void update(sf::Time tDeltaTime);
    };
}