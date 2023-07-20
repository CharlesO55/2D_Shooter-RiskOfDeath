#pragma once

#include "../View.hpp"
#include "../Interface/ButtonListener.hpp"
#include "../../Controller/System/SceneManager.hpp"
#include "../../Controller/System/ScoreManager.hpp"

#include "../Text.hpp"
#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace views{
    using namespace listeners;

    class FrontViewUI : public View, public ButtonListener {
        private:
            views::Text* pScoreText;

        public:
            FrontViewUI();
            ~FrontViewUI();

        public:
            void initialize();
            void update(sf::Time tDeltaTime);

            void createHearts();
            void createBullets();

            void onClick(Button* pButton);
            void onRelease(Button* pButton);
    };
}