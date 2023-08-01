#include "ScenePosInterpreter.hpp"

using namespace components;
using namespace systems;

ScenePosInterpreter::ScenePosInterpreter(std::string strName) : Component(strName, ComponentType::SCRIPT){}

ScenePosInterpreter::~ScenePosInterpreter(){}


void ScenePosInterpreter::perform(){
    interfaces::Positionable *pTarget = dynamic_cast<interfaces::Positionable*> (this->pOwner);

    // BaseEnemy* pTarget = (BaseEnemy*)this->pOwner;

    sf::Vector2f vecSpritePos;
    float fScale;
    
    //USE SIDEVIEW WITH NORMAL SIZE
    if (ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->isEnabled()){
        vecSpritePos = {
            pTarget->getScenePos().z * (SCREEN_WIDTH / 100.f),
            pTarget->getScenePos().y
        };
        fScale = pTarget->getDefaultScale();
    }

    //USE FRONTVIEW WITH CORRESPONDING SIZE
    else {
        vecSpritePos = {
            pTarget->getScenePos().x, 
            pTarget->getScenePos().y
        }; 
        fScale = pTarget->getDefaultScale() * ((100 - pTarget->getScenePos().z) / 90);
        if(fScale > 5)
        {fScale = 5.f;}
    }


    this->pOwner->getSprite()->setPosition(vecSpritePos);
    this->pOwner->getSprite()->setScale(fScale, fScale);
}