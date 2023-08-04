#ifndef SYSTEMS_LAYER_MANAGER_HPP
#define SYSTEMS_LAYER_MANAGER_HPP

#include "../Singleton/GameObjectManager.hpp"
#include "../System/ViewManager.hpp"

#include "../../../Model/Component/Component.hpp"
#include "../../../Model/Component/Script/Interface/Shootable.hpp"

/**************************************/
/*Assitant in sorting the render order*/
/**************************************/

namespace systems{
    using namespace components;
    using namespace interfaces;
    using namespace models;

    class LayerManager : public Component{
        private:
            int nTicks = 0;
            std::vector <GameObject*>* vecGameObjectRef = NULL;     //USE ONLY FOR SORTING. DO NOT DELETE OR ADD ANY OBJECTS
            std::vector<GameObject*>::iterator itr_Start;
            std::vector<GameObject*>::iterator itr_End;
            
            //FOR SORTING SHOOTABLES
            int nIndexFirstBoulder;
            int nIndexLastEnemy;
            int nIndexLastItem;


        private:
            void findIndices();


        public:
            void sortGameObjects();
            Shootable* getFrontmostHit(sf::Vector2f vecMouse);
            std::vector <Shootable*> getAllLineHit(sf::Vector2f vecMouse);


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

#endif