#ifndef VIEWS_LEADERBOARD_HPP
#define VIEWS_LEADERBOARD_HPP

#include "../View.hpp"
#include "../Text.hpp"
#include "../Interface/ButtonListener.hpp"
#include "../../Controller/System/SceneManager.hpp"
#include "../../Controller/System/ScoreManager.hpp"

// #include "../Animator.hpp"

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

        private:
            std::string convertToScoreString(int nValue);
            std::string convertToTenthsString(int nValue);
    };
}

#endif