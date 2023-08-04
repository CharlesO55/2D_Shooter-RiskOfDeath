#ifndef COMPONENTS_MOVE_FORWARD_HPP
#define COMPONENTS_MOVE_FORWARD_HPP

#include "../../Pooling/Enemy/BaseEnemy.hpp"
#include "../Component.hpp"

namespace components{
    class MoveForward : public Component {
        public:
            MoveForward(std::string strName);
            ~MoveForward();

        public:
            void perform();
    };
}

#endif