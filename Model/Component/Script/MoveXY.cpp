#include "MoveXY.hpp"

using namespace components;
using namespace interfaces;

MoveXY::MoveXY(std::string strName, float fMaxDistance, sf::Vector2f vecMoveDir, float fSpeed, bool bRotating, bool bCanFlip, bool bReboundsFromScreenEdge) : Component(strName, ComponentType::SCRIPT){
    this->fMaxDistance = fMaxDistance;
    this->vecMoveDir = vecMoveDir;
    this->bRotate = bRotating;
    this->bCanFlip = bCanFlip;
    this->fSpeed = fSpeed;
    this->bReboundsFromScreenEdge = bReboundsFromScreenEdge;
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
    if(this->bCanFlip){
        this->pOwner->getSprite()->setScale({this->pOwner->getSprite()->getScale().x * vecMoveDir.x, this->pOwner->getSprite()->getScale().y});
    }

    
    sf::Vector3f vec3 = pTarget->getScenePos();
    
    if (this->bReboundsFromScreenEdge){
        if(this->pOwner->getSprite()->getPosition().x > SCREEN_WIDTH ||
        this->pOwner->getSprite()->getPosition().x < 0)
            vecMoveDir.x *= -1;
            
        if(this->pOwner->getSprite()->getPosition().y > SCREEN_HEIGHT || 
        this->pOwner->getSprite()->getPosition().y < 0)
            vecMoveDir.y *= -1;
    }

    vec3.x += fMove * vecMoveDir.x;
    vec3.y += fMove * vecMoveDir.y;

    pTarget->setScenePos(vec3);
}

void MoveXY::setMoveDir(sf::Vector2f vecDir){
    this->vecMoveDir = vecDir;
}