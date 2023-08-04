#ifndef VIEWS_FRONT_VIEW_SCREEN_HPP
#define VIEWS_FRONT_VIEW_SCREEN_HPP

#include "../View.hpp"
#include "../Interface/ButtonListener.hpp"
#include "../../Controller/System/SceneManager.hpp"
#include "../../Controller/System/ScoreManager.hpp"
#include "../../Controller/System/ViewManager.hpp"

#include "../Text.hpp"
#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace views{
    using namespace listeners;

    class FrontViewScreen : public View {
        public:
            FrontViewScreen();
            ~FrontViewScreen();

        public:
            void initialize();
            void update(sf::Time tDeltaTime);
    };
}

#endif