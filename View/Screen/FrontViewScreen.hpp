#pragma once

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

    class FrontViewScreen : public View/* , public ButtonListener */ {
   /*      private:
            views::Text* pScoreText;
 */
        public:
            FrontViewScreen();
            ~FrontViewScreen();

        public:
            void initialize();
            void update(sf::Time tDeltaTime);

/*             void createHearts();
            void createBullets();

            void onClick(Button* pButton);
            void onRelease(Button* pButton); */
    };
}