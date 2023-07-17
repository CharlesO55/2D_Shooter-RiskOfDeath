#ifndef COMPONENTS_PLAYER_BULLET_MOVEMENT_HPP
#define COMPONENTS_PLAYER_BULLET_MOVEMENT_HPP

#include "../../../Config/Settings.hpp"
#include "../../Enum/EnumComponentType.hpp"
#include "../../Pooling/PoolableObject.hpp"
#include "../Component.hpp"
#include "../Physics/Collider.hpp"

namespace components {
    using namespace models;

    class PlayerBulletMovement : public Component {
        private:
            float fFrameInterval;
            float fTicks;
            float fSpeed;

        public:
            PlayerBulletMovement(std::string strName);

        public:
            void perform();
    };
}

#endif