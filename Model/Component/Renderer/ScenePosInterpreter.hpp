#ifndef COMPONENTS_SCENE_POS_INTERPRETER_HPP
#define COMPONENTS_SCENE_POS_INTERPRETER_HPP

#include "../Component.hpp"
#include "../../Pooling/Enemy/BaseEnemy.hpp"
#include "../../../Controller/System/ViewManager.hpp"

#include "../Script/Interface/Positionable.hpp"

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

#endif