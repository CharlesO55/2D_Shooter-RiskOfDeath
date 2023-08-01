#include "BaseBlocker.hpp"

using namespace models;

BaseBlocker::BaseBlocker(std::string strName, AnimatedTexture* pTexture, float fDefaultScale) : GameObject(strName, pTexture) {
    this->fDefaultScale = fDefaultScale;
    this->vecScenePos = {0.f, 0.f, 0.f};
}


BaseBlocker::~BaseBlocker(){}


void BaseBlocker::initialize(){    
    this->setFrame(0);
    this->centerSpriteOrigin();
    
    RendererSpawnable* pRendererSpawanable = new RendererSpawnable(this->strName + " Sprite");
    pRendererSpawanable->assignDrawable(this->pSprite);

    ScenePosInterpreter* pPosInterpreter = new ScenePosInterpreter(this->strName + " Interpreter");

    this->attachComponent(pRendererSpawanable);
    this->attachComponent(pPosInterpreter);
}


void BaseBlocker::randomizeSpawn(sf::FloatRect CArea, float fZMin, float fZMax){
    this->vecScenePos.x = this->nRNG(CArea.left , CArea.left + CArea.width);
    this->vecScenePos.y = this->nRNG(CArea.top  , CArea.top + CArea.height);
    this->vecScenePos.z = this->nRNG(fZMin, fZMax);
}

int BaseBlocker::nRNG(int nMin, int nMax){
    return std::rand() % (nMax + 1 - nMin) + nMin;
}
