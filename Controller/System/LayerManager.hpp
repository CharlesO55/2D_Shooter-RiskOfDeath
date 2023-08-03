#pragma once

#include "../Singleton/GameObjectManager.hpp"
#include "../System/ViewManager.hpp"

#include "../../../Model/Component/Component.hpp"

/**************************************/
/*Assitant in sorting the render order*/
/**************************************/

namespace systems{
    using namespace components;
    using namespace models;

    class LayerManager : public Component{
        private:
            int nTicks = 0;
            std::vector <GameObject*>* vecGameObjectRef = NULL;     //USE ONLY FOR SORTING. DO NOT DELETE OR ADD ANY OBJECTS
            std::vector<GameObject*>::iterator itr_Start;
            std::vector<GameObject*>::iterator itr_End;
        
        private:
            void findIndices();
            void sortGameObjects();

        public:
            void initialize();
            void perform();
            static LayerManager* getInstance();

        private:
            static LayerManager* P_SHARED_INSTANCE;

            LayerManager();
            LayerManager(const LayerManager&) = delete;
            LayerManager& operator = (const LayerManager&) = delete;
    };
}