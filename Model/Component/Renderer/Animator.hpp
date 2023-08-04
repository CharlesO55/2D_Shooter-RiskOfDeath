#ifndef COMPONENTS_ANIMATOR_HPP
#define COMPONENTS_ANIMATOR_HPP

#include "../Component.hpp"
#include "../../GameObject.hpp"

#include "../../../Config/Settings.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace components{
    class Animator : public Component{
        private:
            int nMaxTick;
            int nTick;

        public:
            Animator(std::string strName);
            ~Animator();

        public:
            void perform();
    };
}

#endif