#include "MoveScroll.hpp"

using namespace components;
using namespace interfaces;

MoveScroll::MoveScroll(std::string strName, float fMaxDistance, sf::Vector2f vecMoveDir, float fSpeed, bool bReversed) : Component(strName, ComponentType::SCRIPT){
    this->fMaxDistance = fMaxDistance;
    this->vecMoveDir = vecMoveDir;
    this->fSpeed = fSpeed;
    if(bReversed)
        this->vecMoveDir = sf::Vector2f(this->vecMoveDir.x * -1, this->vecMoveDir.y * -1);

    
}

MoveScroll::~MoveScroll(){}

void MoveScroll::perform(){
    Positionable* pTarget = dynamic_cast<Positionable*>(this->pOwner);
    ScrollBlocker* pScroll = dynamic_cast<ScrollBlocker*>(this->pOwner);
    
    float fMove = this->tDeltaTime.asSeconds() * this->fSpeed; 
    this->fTravelled += fMove;

    std::cout<< this->fTravelled <<std::endl;

    if (this->fTravelled > this->fMaxDistance){
        pScroll->randomizeSpawn(pScroll->getCArea(), pScroll->getZMin(), pScroll->getZMax());
        this->fTravelled = 0.f;
    }
    
    sf::Vector3f vec3 = pTarget->getScenePos();
    vec3.x += fMove * vecMoveDir.x;
    vec3.y += fMove * vecMoveDir.y;

    pTarget->setScenePos(vec3);
}