#pragma once

#include "../View.hpp"
#include "../Text.hpp"
#include "../../../Controller/System/ViewManager.hpp"

namespace views{
    class LoadingScreen : public View {
        public:
            LoadingScreen();
            ~LoadingScreen();

        public:
            void initialize();
    };
}