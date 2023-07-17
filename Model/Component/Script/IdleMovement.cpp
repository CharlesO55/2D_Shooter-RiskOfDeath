#include "IdleMovement.hpp"

using namespace components;

IdleMovement::IdleMovement(std::string strName,
                           float fLowerBound,
                           float fUpperBound,
                           bool bUpwards,
                           float fSpeed,
                           float fFrameInterval)
             : Component(strName, ComponentType::SCRIPT) {
    this->fFrameInterval = fFrameInterval;
    this->fTicks = 0.0f;

    this->fSpeed = fSpeed;
    this->fLowerBound = fLowerBound;
    this->fUpperBound = fUpperBound;

    this->bIdle = true;
    this->bUpwards = bUpwards;
}

void IdleMovement::perform() {
    if(this->bIdle) {
        this->fTicks += this->tDeltaTime.asSeconds();
        
        if(this->fTicks > this->fFrameInterval) {
            this->fTicks = 0.0f;
            float fX = this->pOwner->getSprite()->getPosition().x;
            float fY = this->pOwner->getSprite()->getPosition().y;

            if(this->bUpwards) {
                if(fY > this->fLowerBound) {
                    fY = this->normalize(fY - this->fSpeed);
                    this->pOwner->getSprite()->setPosition(fX, fY);
                }
                else
                    this->bUpwards = false;
            }
            else {
                if(fY < this->fUpperBound) {
                    fY = this->normalize(fY + this->fSpeed);
                    this->pOwner->getSprite()->setPosition(fX, fY);
                }
                else
                    this->bUpwards = true;
            }
        }
    }
}

float IdleMovement::normalize(float fValue) {
    if(fValue < this->fLowerBound)
        fValue = this->fLowerBound;

    if(fValue > this->fUpperBound)
        fValue = this->fUpperBound;

    return fValue;
}

bool IdleMovement::isIdle() {
    return this->bIdle;
}

void IdleMovement::setIdle(bool bIdle) {
    this->bIdle = bIdle;
}
