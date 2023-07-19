#pragma once

#include "../View.hpp"
#include "../Interface/ButtonListener.hpp"
#include "../../Controller/System/SceneManager.hpp"

namespace views{
    using namespace listeners;

    class Leaderboard : public View, public ButtonListener{
        public:
            Leaderboard();
            ~Leaderboard();

        public:
            void initialize();
            void onClick(Button* pButton);
            void onRelease(Button* pButton);
    };
}