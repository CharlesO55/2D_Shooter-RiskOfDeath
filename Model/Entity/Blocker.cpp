#include "Blocker.hpp"

using namespace models;

Blocker::Blocker(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
}

Blocker::~Blocker(){

}

void Blocker::initialize(){    
    this->setFrame(0);
    this->getSprite()->setScale(10.0f, 10.0f);
    this->centerSpriteOrigin();

    RendererSpawnable* pRendererSpawanable = new RendererSpawnable(this->strName + " Sprite");
    pRendererSpawanable->assignDrawable(this->pSprite);

    this->attachComponent(pRendererSpawanable);
}