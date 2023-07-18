#include "ShipControls.hpp"

using namespace components;

ShipControls::ShipControls(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fSpeed = 300.0f;
}

void ShipControls::perform() {
    Ship* pShipOwner = (Ship*)this->pOwner;
    ShipInput* pInput = (ShipInput*)this->getOwner()->findComponentByName(this->pOwner->getName() + " Input");
    
    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();
        
        if(pInput->isUp() && pShipOwner->isTopBounds())
            this->getOwner()->getSprite()->move(0.0f, -fOffset);

        if(pInput->isDown() && pShipOwner->isBottomBounds())
            this->getOwner()->getSprite()->move(0.0f, fOffset);
        
        if(pInput->isLeft() && pShipOwner->isLeftBounds())
            this->getOwner()->getSprite()->move(-fOffset, 0.0f);

        if(pInput->isRight() && pShipOwner->isRightBounds())
            this->getOwner()->getSprite()->move(fOffset, 0.0f);

        if(pInput->isSpace()) {
            pInput->resetSpace();
            ObjectPoolManager::getInstance()->getPool(PoolTag::PLAYER_BULLET)->requestPoolable();
        }
    }
}