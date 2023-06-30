#pragma once

#include <SFML/Graphics.hpp>

#include "Enum/EnumObjTypes.hpp"

#include "Component/Component.hpp"
#include "Component/CompRenderer.hpp"
#include "Component/ScriptIdle.hpp"



namespace models{
    using namespace components;

    class GameObject{
        protected:
            sf::Drawable* pDrawable;
            EnumObjTypes eType;
            bool bEnabled;

            GameObject* pParent;
            std::vector <GameObject*> vecChildren;
            std::vector <Component*> vecComponents;


        public:
            std::string strName;

        public:
            GameObject(sf::Texture* pTexture, std::string strName, GameObject* pParent = NULL, float fX = 0, float fY = 0);
            
        public:
            virtual void initialize();
            virtual void update(sf::Time CTime){};
            void draw(sf::RenderWindow* pWindow);


        public:
            std::vector <GameObject*> getChildren(){return this->vecChildren;};
            std::vector <Component*> getComponents(EnumComponentType EType);
            std::vector <Component*> getChildrenComponents(EnumComponentType EType);

            bool isEnabled() {return this->bEnabled;};
            void setEnabled(bool bTOF) {this->bEnabled = bTOF;};


            sf::Drawable* getDrawable();
            sf::Sprite* getSprite();
    };
}