#pragma once

#include "../../Model/GameObject.hpp"
#include <unordered_map>


namespace singletons{
    using namespace models;
    class GameObjectManager{
        private:
            static GameObjectManager* P_SHARED_INSTANCE;
            std::vector <GameObject*> vecObjects;
            std::unordered_map <std::string, GameObject*> mapObjects;

        public:
            void registerObject(GameObject* pObject);
            void deleteObject(GameObject* pObject);
            void deleteAllObjects();

            void processEvents(sf::Event EEvent);
            void updateObjects(sf::Time CTime);
            void drawObjects(sf::RenderWindow *pWindow);




        //SINGLETON STUFF
        private:
            GameObjectManager(){};
            GameObjectManager(const GameObjectManager&) = delete;
            GameObjectManager& operator = (const GameObjectManager&) = delete;

        public:
            static GameObjectManager* getInstance();
    };
}