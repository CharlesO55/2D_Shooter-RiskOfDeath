#pragma once


#include "../View.hpp"
#include "../../Controller/System/ViewManager.hpp"

#include "../Text.hpp"


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