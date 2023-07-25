#pragma once

#include "../Component.hpp"
#include "../../Pooling/Enemy/BaseEnemy.hpp"
#include "../../../Controller/System/ViewManager.hpp"

namespace components{
    using namespace models;
    class ScenePosInterpreter : public Component{
        public:
            ScenePosInterpreter(std::string strName);
            ~ScenePosInterpreter();

        public:
            void perform();
    };
}