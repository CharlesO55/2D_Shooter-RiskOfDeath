#pragma once

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