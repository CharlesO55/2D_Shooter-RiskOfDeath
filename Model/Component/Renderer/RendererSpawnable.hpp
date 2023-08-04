#ifndef COMPONENTS_RENDERER_SPAWNABLE
#define COMPONENTS_RENDERER_SPAWNABLE

/*
ALTERNATE RENDERER FOR SPAWANABLE OBJ: ENEMY, BLOCKERS, AND ITEMS
CAN ARRANGE/SORT 
CAN RESIZE BASED ON BACKGROUND TRANSFORM
*/

//DO NOT USE IF NOT INTENDED FOR OBJECT TO CHANGE Z POS AND SCALE DUE TO SCREEN SWITCH

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

#endif