#include "Animator.hpp"

using namespace components;

Animator::Animator(std::string strName) : Component(strName, ComponentType::SCRIPT){
     this->nTick = 0;

    //SINCE 60 FRAME_LIMIT, EVERY 0.166666s ANIMATOR WILL TICK
     this->nMaxTick = 4;
}

Animator::~Animator(){}

void Animator::perform(){
    nTick++;

    if (this->nTick >= this->nMaxTick){
        nTick = 0;
        this->pOwner->incrementFrame();
    }
}