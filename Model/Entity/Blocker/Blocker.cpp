#include "Blocker.hpp"

using namespace models;

Blocker::Blocker(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
}

Blocker::~Blocker(){

}

void Blocker::initialize(){    
    this->setFrame(0);
    this->getSprite()->setScale(0.5f, 0.5f);
    this->centerSpriteOrigin();

    RendererSpawnable* pRendererSpawanable = new RendererSpawnable(this->strName + " Sprite");
    pRendererSpawanable->assignDrawable(this->pSprite);

    // ScenePosInterpreter* pPosInterpreter = new ScenePosInterpreter(this->strName + " Interpreter");

    this->attachComponent(pRendererSpawanable);
    // this->attachComponent(pPosInterpreter);

    this->randomizeSpawn();
/* 
    sf::CircleShape CCircle(20);
    CCircle.setp */
}


void Blocker::randomizeSpawn(sf::FloatRect CArea){
    // this->vecScenePos.x = 0;
    // this->vecScenePos.y = 0;
    this->vecScenePos.x = std::rand() % (int)((CArea.left + CArea.width) + 1 - CArea.left) + CArea.left;
    this->vecScenePos.y = std::rand() % (int)((CArea.top + CArea.height) + 1 - CArea.top) + CArea.top;

    // std::cout <<
    // rand() % (max_number + 1 - minimum_number) + minimum_number
}