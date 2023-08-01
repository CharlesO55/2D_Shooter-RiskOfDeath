#include "MoveXY.hpp"

using namespace components;
using namespace interfaces;

MoveXY::MoveXY(std::string strName, float fMaxDistance, sf::Vector2f vecMoveDir, float fSpeed, bool bRotating ) : Component(strName, ComponentType::SCRIPT){
    this->fMaxDistance = fMaxDistance;
    this->vecMoveDir = vecMoveDir;
    this->bRotate = bRotating;
    this->fSpeed = fSpeed;
}

MoveXY::~MoveXY(){}

void MoveXY::perform(){
    Positionable* pTarget = dynamic_cast<Positionable*>(this->pOwner);

    
    float fMove = this->tDeltaTime.asSeconds() * this->fSpeed; 
    this->fTravelled += fMove;

    

    if (this->fTravelled > fMaxDistance){
        vecMoveDir.x *= -1;
        vecMoveDir.y *= -1;
        this->fTravelled = 0.f;
    }
    
    if(this->bRotate){
        float fRot = this->pOwner->getSprite()->getRotation() + fMove * vecMoveDir.x;
        this->pOwner->getSprite()->setRotation(fRot);
    }

    
    sf::Vector3f vec3 = pTarget->getScenePos();
    vec3.x += fMove * vecMoveDir.x;
    vec3.y += fMove * vecMoveDir.y;

    pTarget->setScenePos(vec3);
}