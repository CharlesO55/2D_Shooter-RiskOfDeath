#ifndef MODELS_HITBOX_HPP
#define MODELS_HITBOX_HPP

#include "GameObject.hpp"
#include "Component/Renderer/Renderer.hpp"
#include "Enum/EnumShape.hpp"

#include "../../../Config/Settings.hpp"

#include "../../../Controller/System/ViewManager.hpp"


namespace models{
    class Hitbox : public GameObject{
        private:
            sf::Shape* pShape;
            ShapeType EShape;
            std::vector <sf::Vector2f> vecVerts;
            sf::FloatRect rectModify;

        public:
            Hitbox(std::string strName, ShapeType EShape, sf::FloatRect rectModify);
            // Hitbox(std::string strName, std::vector <sf::Vector2f> vecVerts);    //Cancelled. No convex shapes
            ~Hitbox();

        public:
            void initialize();
            bool contains(sf::Vector2f vecMouse);
            void modifyShape(sf::FloatRect rectModify);

        private:
            void createShape();
            bool foundInRectangle(sf::Vector2f vecMouse);
            bool foundInCircle(sf::Vector2f vecMouse);
            bool foundInTriangle(sf::Vector2f vecMouse);
            sf::FloatRect extractParentTransformedBounds();
    };
}

#endif