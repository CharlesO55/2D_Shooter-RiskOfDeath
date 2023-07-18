#include "ScriptBlocker.hpp"

using namespace components;

ScriptBlocker::ScriptBlocker(std::string strName, models::GameObject* pOwner, EnumBlockerType EBlockerType) 
                : Component(strName + " Script", ComponentType::SCRIPT){
                // : Component(strName + " Script", EnumComponentType::SCRIPT, pOwner){

    this->fSpeed = 35.f;
    switch(EBlockerType){
        case EnumBlockerType::VERTICAL:
            this->fUpperBound = this->getOwner()->getSprite()->getPosition().y + 50.f;
            this->fLowerBound = this->getOwner()->getSprite()->getPosition().y - 50.f;
            this->nMoveHorizontal = 0;
            this->nMoveVertical = 1;
            break;
        case EnumBlockerType::HORIZONTAL:
            this->fUpperBound = this->getOwner()->getSprite()->getPosition().x + 50.f;
            this->fLowerBound = this->getOwner()->getSprite()->getPosition().x - 50.f;
            this->nMoveHorizontal = 1;
            this->nMoveVertical = 0;
            break;
    }
}

void ScriptBlocker::perform(){
    sf::Vector2f vecMove = sf::Vector2f(this->nMoveHorizontal, this->nMoveVertical) * this->fSpeed * this->CTime.asSeconds();

    sf::Sprite *pSprite = this->pOwner->getSprite();
    if (pSprite->getGlobalBounds().left + pSprite->getGlobalBounds().width + vecMove.x > this->fUpperBound){
        this->nMoveHorizontal *= -1;
    }

    if (pSprite->getGlobalBounds().top + pSprite->getGlobalBounds().height + vecMove.y > this->fUpperBound){
       // vecMove.y = this->vecMaxBounds.y - (pSprite->getGlobalBounds().top + pSprite->getGlobalBounds().height);
        this->nMoveVertical *= -1;
    }

    if (pSprite->getGlobalBounds().left + vecMove.x < this->fLowerBound){
        this->nMoveHorizontal *= -1;
    }
    
    if (pSprite->getGlobalBounds().top + vecMove.y < this->fLowerBound){
        //vecMove.y = this->vecMinBounds.y - pSprite->getGlobalBounds().top;
        this->nMoveVertical *= -1;
    }
    std::cout<<this->getOwner()->getSprite()->getPosition().x<<" ";
    std::cout<<this->getOwner()->getSprite()->getPosition().y<<std::endl;
    pSprite->move(vecMove);
}