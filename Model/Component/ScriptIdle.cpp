#include "ScriptIdle.hpp"

using namespace components;

ScriptIdle::ScriptIdle(std::string strName, models::GameObject* pOwner, sf::Vector2f vecMinBounds, sf::Vector2f vecMaxBounds, float fSpeed) :
    Component(strName + " Script", EnumComponentType::SCRIPT, pOwner)
{
    this->vecMinBounds = vecMinBounds;
    this->vecMaxBounds = vecMaxBounds;
    this->fSpeed = fSpeed;

    this->vecDir = {1.f, 1.f};
}

void ScriptIdle::perform(){
    sf::Vector2f vecMove = vecDir * this->fSpeed * this->CTime.asSeconds();


    sf::Sprite *pSprite = this->pOwner->getSprite();
    if (pSprite->getGlobalBounds().left + pSprite->getGlobalBounds().width + vecMove.x > this->vecMaxBounds.x){
        vecMove.x = this->vecMaxBounds.x - (pSprite->getGlobalBounds().left + pSprite->getGlobalBounds().width);
        vecDir.x *= -1;
    }

    if (pSprite->getGlobalBounds().top + pSprite->getGlobalBounds().height + vecMove.y > this->vecMaxBounds.y){
        vecMove.y = this->vecMaxBounds.y - (pSprite->getGlobalBounds().top + pSprite->getGlobalBounds().height);
        vecDir.y *= -1;
    }

    if (pSprite->getGlobalBounds().left + vecMove.x < this->vecMinBounds.x){
        vecMove.x = this->vecMinBounds.x - pSprite->getGlobalBounds().left;
        vecDir.x *= -1;
    }
    
    if (pSprite->getGlobalBounds().top + vecMove.y < this->vecMinBounds.y){
        vecMove.y = this->vecMinBounds.y - pSprite->getGlobalBounds().top;
        vecDir.y *= -1;
    }

    pSprite->move(vecMove);
}