#include "Blinker.hpp"

using namespace components;

Blinker::Blinker(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->pBlinkable = NULL;
    this->bBlinking = false;
    
    this->nBlinkCount = 0;
    this->nMaxBlinks = 4;

    this->fFrameInterval = 0.05f;
    this->fTicks = 0.0f;
}

void Blinker::perform() {
    if(this->bBlinking) {
        this->fTicks += this->tDeltaTime.asSeconds();

        if(this->fTicks > this->fFrameInterval) {
            this->fTicks = 0.0f;
            this->blink();
        }
    }
}

void Blinker::start() {
    this->bBlinking = true;
}

void Blinker::blink() {
    if(this->pBlinkable == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
        this->reset();
    }
    else {
        if(this->nBlinkCount < this->nMaxBlinks) {
            this->pBlinkable->blink();
            this->nBlinkCount++;
        }
        else
            this->reset();
    }
}

void Blinker::reset() {
    this->bBlinking = false;
    this->nBlinkCount = 0;
}

void Blinker::setBlinkable(Blinkable* pBlinkable) {
    this->pBlinkable = pBlinkable;
}

bool Blinker::isBlinking() {
    return this->bBlinking;
}


int Blinker::getBlinksRemaining(){
    return this->nMaxBlinks - this->nBlinkCount;
}