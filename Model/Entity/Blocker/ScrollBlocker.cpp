#include "ScrollBlocker.hpp"

using namespace models;

ScrollBlocker::ScrollBlocker(std::string strName, AnimatedTexture* pTexture, EnumBlockerType Etype, float fDefaultScale) : GameObject(strName, pTexture) {
    this->Etype = Etype;
    this->fDefaultScale = fDefaultScale;
    this->vecScenePos = {0.f, 0.f, 0.f};
    this->bIsReversed = nRNG(0,1);
}


ScrollBlocker::~ScrollBlocker(){}


void ScrollBlocker::initialize(){    
    this->setFrame(0);
    this->centerSpriteOrigin();
    
    RendererSpawnable* pRendererSpawanable = new RendererSpawnable(this->strName + " Sprite");
    pRendererSpawanable->assignDrawable(this->pSprite);

    ScenePosInterpreter* pPosInterpreter = new ScenePosInterpreter(this->strName + " Interpreter");

    this->attachComponent(pRendererSpawanable);
    this->attachComponent(pPosInterpreter);
}


void ScrollBlocker::randomizeSpawn(sf::FloatRect CArea, float fZMin, float fZMax){
    if(this->Etype == EnumBlockerType::VERTICAL){
        this->vecScenePos.x = this->nRNG(CArea.left + 150, CArea.left + CArea.width - 150);
        if(!this->bIsReversed)
            this->vecScenePos.y = CArea.top - 100.f;
        else
            this->vecScenePos.y = CArea.top + CArea.height + 100.f;
    } 
    else{
        
        if(!this->bIsReversed)
            this->vecScenePos.x = CArea.left - 100.f;
        else
            this->vecScenePos.x = CArea.left + CArea.width + 100.f;
        this->vecScenePos.y = this->nRNG(CArea.top + 150, CArea.top + CArea.height - 150);
    }
    this->vecScenePos.z = this->nRNG(fZMin, fZMax);
}

int ScrollBlocker::nRNG(int nMin, int nMax){
    return std::rand() % (nMax + 1 - nMin) + nMin;
}
