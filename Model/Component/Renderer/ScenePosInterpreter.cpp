#include "ScenePosInterpreter.hpp"

using namespace components;
using namespace systems;

ScenePosInterpreter::ScenePosInterpreter(std::string strName) : Component(strName, ComponentType::SCRIPT){}

ScenePosInterpreter::~ScenePosInterpreter(){}


void ScenePosInterpreter::perform(){
    BaseEnemy* pOwnerEnemy = (BaseEnemy*)this->pOwner;

    sf::Vector2f vecSpritePos;
    
    if (ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->isEnabled()){
        vecSpritePos = {
            pOwnerEnemy->getScenePos().z * (SCREEN_WIDTH / 100.f),
            pOwnerEnemy->getScenePos().y
        };
    }
    else {
        vecSpritePos = {
            pOwnerEnemy->getScenePos().x, 
            pOwnerEnemy->getScenePos().y
        }; 
    }
    pOwnerEnemy->getSprite()->setPosition(vecSpritePos);
}