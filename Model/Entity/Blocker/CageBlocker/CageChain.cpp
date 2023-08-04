#include "CageChain.hpp"

using namespace models;

CageChain::CageChain(std::string strName) : 
            BaseBlocker(strName, new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CAGE_CHAIN)), 1.f)
{
}

CageChain::~CageChain(){}

void CageChain::initialize(){
    this->setFrame(0);
    this->centerSpriteOrigin();
    
    RendererSpawnable* pRendererSpawanable = new RendererSpawnable(this->strName + " Sprite");
    pRendererSpawanable->assignDrawable(this->pSprite);

    ScenePosInterpreter* pPosInterpreter = new ScenePosInterpreter(this->strName + " Interpreter");

    this->attachComponent(pRendererSpawanable);
    this->attachComponent(pPosInterpreter);

}

void CageChain::createHitboxes(){}


