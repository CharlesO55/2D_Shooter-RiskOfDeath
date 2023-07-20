#ifndef COMPONENTS_CROSSHAIR_MOVEMENT_HPP
#define COMPONENTS_CROSSHAIR_MOVEMENT_HPP

#include "../../Enum/EnumComponentType.hpp"
#include "../Component.hpp"
#include "GeneralInput.hpp"

namespace components {
    class CrosshairMovement : public GeneralInput {
        public:
            CrosshairMovement(std::string strName);

        public:
            void perform();
    };
}

#endif