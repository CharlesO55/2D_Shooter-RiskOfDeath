#include "Monster.hpp"

using namespace entities;

Monster::Monster(sf::Texture* pTexture, std::string strName, GameObject* pParent, float fX, float fY):
    GameObject(pTexture, strName + " Monster", pParent, fX, fY){

    }

void Monster::initialize(){
    //CREATES RENDER COMPONENT
    GameObject::initialize();

    ScriptIdle* pScript = new ScriptIdle(this->strName, this);
    this->vecComponents.push_back(pScript);
}

void Monster::update(sf::Time CTime){
    ScriptIdle* pScript;
    for (auto pComp : this->getComponents(EnumComponentType::SCRIPT)){
        pScript = (ScriptIdle*) pComp;
        pScript->assignOnUpdate(CTime);
        pScript->perform();
    }
}