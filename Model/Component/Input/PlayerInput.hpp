#ifndef COMPONENTS_PLAYER_INPUT_HPP
#define COMPONENTS_PLAYER_INPUT_HPP

#include "../Component.hpp"
#include "GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bR;

        public:
            PlayerInput(std::string strName);

        public:
            void perform();

        private:
            void processKeyInput(bool bPressed);
    };
}


#endif