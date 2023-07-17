#ifndef COMPONENTS_SHIP_CONTROLS_HPP
#define COMPONENTS_SHIP_CONTROLS_HPP

#include "../Component.hpp"
#include "../Input/ShipInput.hpp"

#include "../../Enum/EnumComponentType.hpp"
#include "../../Enum/EnumPoolTag.hpp"

#include "../../../Controller/System/ObjectPoolManager.hpp"

namespace components {
    using namespace controllers;
    using namespace systems;

    class ShipControls : public Component {
        private:
            float fSpeed;
            
        public:
            ShipControls(std::string strName);

        public:
            void perform();
    };
}

#endif