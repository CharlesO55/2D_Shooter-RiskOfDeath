#pragma once

#include "../Component.hpp"
#include "../Input/GameNavigationInput.hpp"
#include "../Input/CrosshairMouseInput.hpp"
#include "../../../Controller/System/ViewManager.hpp"

namespace components{
    class GameScreenNavigation : public Component{
        private:
            GameNavigationInput* pNavInputRef;


            int nCooldownTicker = 0;
            const int nSwitchCooldown = 20;


        public:
            GameScreenNavigation(GameNavigationInput* pNavInputRef);
            ~GameScreenNavigation();

        public:
            void perform();

        private:
            void resetInputFlags();
            void keepInBounds(float *pValue, float fMin, float fMax);
    };
}