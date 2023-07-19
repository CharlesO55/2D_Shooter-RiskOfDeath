#include "Animator.hpp"

using namespace components;

Animator::Animator(std::string strName) : Component(strName, ComponentType::SCRIPT){
     this->nTick = 0;
     this->nMaxTick = FRAME_RATE_LIMIT / 15;
}

Animator::~Animator(){}

void Animator::perform(){
    nTick++;

    if (this->nTick >= this->nMaxTick){
        nTick = 0;
        this->pOwner->incrementFrame();
    }
}