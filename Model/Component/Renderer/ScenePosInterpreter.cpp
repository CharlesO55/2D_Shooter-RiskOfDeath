#include "ScenePosInterpreter.hpp"

using namespace components;
using namespace systems;

ScenePosInterpreter::ScenePosInterpreter(std::string strName) : Component(strName, ComponentType::SCRIPT){}

ScenePosInterpreter::~ScenePosInterpreter(){}


void ScenePosInterpreter::perform(){
    BaseEnemy* pOwnerEnemy = (BaseEnemy*)this->pOwner;

    sf::Vector2f vecSpritePos;
    float fScale;
    
    
    if (ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->isEnabled()){
        vecSpritePos = {
            pOwnerEnemy->getScenePos().z * (SCREEN_WIDTH / 100.f),
            pOwnerEnemy->getScenePos().y
        };
        fScale = pOwnerEnemy->getDefaultScale();
    }


    else {
        vecSpritePos = {
            pOwnerEnemy->getScenePos().x, 
            pOwnerEnemy->getScenePos().y
        }; 
        fScale = pOwnerEnemy->getDefaultScale() * ((100 - pOwnerEnemy->getScenePos().z) / 25);
    }


    pOwnerEnemy->getSprite()->setPosition(vecSpritePos);
    pOwnerEnemy->getSprite()->setScale(fScale, fScale);
}