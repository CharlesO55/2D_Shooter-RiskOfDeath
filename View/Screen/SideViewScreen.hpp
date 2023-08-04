#ifndef VIEWS_SIDE_VIEW_SCREEN_HPP
#define VIEWS_SIDE_VIEW_SCREEN_HPP

#include "../View.hpp"
#include "../Text.hpp"
#include "../../Controller/System/ViewManager.hpp"

namespace views{
    using namespace listeners;
    class SideViewScreen : public View{
        public:
            SideViewScreen();
            ~SideViewScreen();

        public:
            void initialize();
    };
}

#endif