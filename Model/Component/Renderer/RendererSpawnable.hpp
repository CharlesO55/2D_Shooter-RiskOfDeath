#pragma once

/*
ALTERNATE RENDERER FOR SPAWANABLE OBJ: ENEMY, BLOCKERS, AND ITEMS
CAN ARRANGE/SORT 
CAN RESIZE BASED ON BACKGROUND TRANSFORM
*/


#include "Renderer.hpp"
#include "../../../Controller/System/ViewManager.hpp"

namespace components{
    class RendererSpawnable : public Renderer{
        public:
            RendererSpawnable(std::string strName);
            ~RendererSpawnable();

        public:
            void perform();
    };
}