#pragma once

#include <SFML/Graphics.hpp>

#include "Enum/EnumObjTypes.hpp"
#include "Enum/EnumObjSubTypes.hpp"

#include "Component/Component.hpp"
#include "Component/CompRenderer.hpp"
#include "Component/InputBase.hpp"
#include "Component/ScriptIdle.hpp"
#include "Component/ScriptBlocker.hpp"



namespace models{
    using namespace components;

    class GameObject{
        protected:
            sf::Drawable* pDrawable;
            EnumObjTypes EType;
            EnumObjSubTypes ESubtype;

            bool bEnabled;

            GameObject* pParent;
            std::vector <GameObject*> vecChildren;
            std::vector <Component*> vecComponents;


        public:
            std::string strName;

        public:
            //FOR SPRITES
            GameObject(sf::Texture* pTexture, std::string strName, GameObject* pParent = NULL, float fX = 0, float fY = 0);
            
            //FOR TEXT AND OTHERS
            GameObject(std::string strName, EnumObjTypes EType, EnumObjSubTypes ESubtype, GameObject* pParent = NULL, float fX = 0, float fY = 0);
            
        public:
            virtual void initialize();
            virtual void processEvent(sf::Event EEvent);
            virtual void update(sf::Time CTime){};
            void draw(sf::RenderWindow* pWindow);
            //void centerSpriteOrigin();

        protected:
            void addChild(GameObject* pParent);

        public:
            std::vector <GameObject*> getChildren(){return this->vecChildren;};
            std::vector <Component*> getComponents(EnumComponentType EType);
            std::vector <Component*> getChildrenComponents(EnumComponentType EType);

            const EnumObjSubTypes getSubtype() {return this->ESubtype;};
            bool isEnabled() {return this->bEnabled;};
            void setEnabled(bool bTOF) {this->bEnabled = bTOF;};


            sf::Drawable* getDrawable();
            sf::Sprite* getSprite();

            const sf::Transform getGenericTransform();
            const sf::FloatRect getGenericGlobalBounds();
    };
}