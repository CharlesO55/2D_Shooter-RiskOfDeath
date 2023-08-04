#ifndef VIEWS_PAUSE_SCREEN_HPP
#define VIEWS_PAUSE_SCREEN_HPP

#include "../View.hpp"
#include "../Text.hpp"
#include "../../../Controller/System/ViewManager.hpp"


namespace views{
    class PauseScreen : public View{
        public:
            PauseScreen();
            ~PauseScreen();

        public:
            void initialize();
    };
}

#endif