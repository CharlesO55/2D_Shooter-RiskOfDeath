#pragma once

#include "../View.hpp"
#include "../Interface/ButtonListener.hpp"
#include "../../Controller/System/SceneManager.hpp"
#include "../../Controller/System/ScoreManager.hpp"
#include "../../Controller/System/ViewManager.hpp"
#include "../../Controller/Singleton/GameStateManager.hpp"

#include "../Text.hpp"
#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace views{
    using namespace listeners;

    class PlayerUI : public View, public ButtonListener {
        private:
            int nHearts;
            int nBullets;
            int nItems;

            ItemType Inventory1;
            ItemType Inventory2;
            ItemType Inventory3;

            views::Text *pScoreText;

        public:
            PlayerUI();
            ~PlayerUI();

        public:
            void initialize();
            void update(sf::Time tDeltaTime);

        private:
            void createHearts();
            void createBullets();

            void createInventory();
            void createStatus();

        public:
            void restoreHealth();
            void decrementHealth();

            void reloadBullets();
            void decrementBullets();

            void updateActiveEffects();

            void addItemToInventory(ItemType EType);
            void updateInventory(int nInventoryNumber);

        public:
            int getHealth();
            int getBullets();

        public:
            void onClick(Button* pButton);
            void onRelease(Button* pButton);
    };
}