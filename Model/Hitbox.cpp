#include "Hitbox.hpp"

using namespace models;

Hitbox::Hitbox(std::string strName, ShapeType EShape) : GameObject(strName, NULL){
    if (EShape == ShapeType::IRREGULAR){
        std::cout << "\n[WARNING] TO CREATE IRREGULAR SHAPES, PASS A VECTOR OF POINTS";
        throw 0;
    }
    this->EShape = EShape;
}
 
Hitbox::Hitbox(std::string strName, std::vector <sf::Vector2f> vecVerts) : GameObject(strName, NULL) {
    this->EShape = ShapeType::IRREGULAR;
    this->vecVerts = vecVerts;
}


Hitbox::~Hitbox(){}

void Hitbox::initialize(){
    this->createShape();
    
    if (RENDER_HITBOXES){
        this->pShape->setFillColor(sf::Color(255, 100, 100, 100));

        Renderer* pRenderer = new Renderer(this->strName + " Sprite");
        pRenderer->assignDrawable(this->pShape);
        this->attachComponent(pRenderer);
    }
}

void Hitbox::createShape(){
    sf::Sprite* pParentSprite = this->pParent->getSprite();

    switch(EShape){
        case ShapeType::CIRCLE:
            this->pShape = new sf::CircleShape(pParentSprite->getLocalBounds().width / 2);
            break;
        case ShapeType::RECTANGLE:
            this->pShape = new sf::RectangleShape({pParentSprite->getLocalBounds().width, pParentSprite->getLocalBounds().height});
            break;
        case ShapeType::TRIANGLE:
        {
            sf::CircleShape *pTriangle = new sf::CircleShape(pParentSprite->getLocalBounds().width / 2);
            pTriangle->setPointCount(3);
            this->pShape = pTriangle;
        }
            break;

        case ShapeType::IRREGULAR:
        {
            /* this->vecVerts = {
                {2, 137},
                {46, 39},
                {120, 2},
                {230, 54},
                {253, 130}
            }; */
            sf::ConvexShape* pConvex = new sf::ConvexShape(this->vecVerts.size());
            
            for (int i = 0; i < this->vecVerts.size(); i++){
                pConvex->setPoint(i, this->vecVerts[i]);
            }
            this->pShape = pConvex;
        }
            break;
        default:
            std::cout << "\n [ERROR] UNRECOGNIZED SHAPE";
            throw 0;
    }
}

bool Hitbox::contains(sf::Vector2f vecMouse){
    switch (this->EShape){
        case ShapeType::RECTANGLE:
            return this->foundInRectangle(vecMouse);
        case ShapeType::CIRCLE:
            return this->foundInCircle(vecMouse);
        case ShapeType::TRIANGLE:
            return this->foundInTriangle(vecMouse);
        default:
            return false;
    }
}

bool Hitbox::foundInRectangle(sf::Vector2f vecMouse){
    sf::FloatRect CTransformedBounds = this->extractParentTransformedBounds();

    return CTransformedBounds.contains(vecMouse);
}


bool Hitbox::foundInCircle(sf::Vector2f vecMouse){
    sf::FloatRect CTransformedBounds = this->extractParentTransformedBounds();

    sf::Vector2f vecOrigin = {
        CTransformedBounds.left + CTransformedBounds.width/2,
        CTransformedBounds.top + CTransformedBounds.height/2
    };
    

    sf::Vector2f vecDist = vecMouse - vecOrigin;
    float fDistance = sqrt((vecDist.x * vecDist.x) + (vecDist.y * vecDist.y));

    if (fDistance > CTransformedBounds.width/2){
        // std::cout << "\n[Circle Collide] NO";
        return false;
    }
    // std::cout << "\n[Circle Collide] YES";
    return true;
}


bool Hitbox::foundInTriangle(sf::Vector2f vecMouse){
    sf::FloatRect CTransformedBounds = this->extractParentTransformedBounds();

    if (!CTransformedBounds.contains(vecMouse)){
        return false;
    }

    float fCenterX = CTransformedBounds.left + CTransformedBounds.width/2;
    float fY = vecMouse.y - CTransformedBounds.top;

    //FOR SQUARE DIMENSION IMAGES
    if (fY > CTransformedBounds.width * 0.75){
        // std::cout << "\nEXCEED HALF WIDTH";
        return false;
    } 

    if (fCenterX + fY/2 > vecMouse.x && vecMouse.x > fCenterX - fY/2){
        // std::cout << "\n\nINISDE";
        return true;
    }
    
    return false;
}



sf::FloatRect Hitbox::extractParentTransformedBounds(){
    views::View* pView = systems::ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN);
    if(pView == NULL){
        std::cout << "[ERROR] FRONT VIEW MISSING";
        throw 0;
    }

    return this->pParent->getTransformedBounds(pView->getBackground()->getSprite()->getTransform());
}