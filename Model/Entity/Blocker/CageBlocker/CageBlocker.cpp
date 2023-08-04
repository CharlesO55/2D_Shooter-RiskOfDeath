#include "CageBlocker.hpp"

using namespace models;
using namespace components;

CageBlocker::CageBlocker(std::string strName, sf::FloatRect CArea, sf::Vector2f vecDir, float fZMin, float fZMax) : 
    BaseBlocker(strName, new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CAGE_BODY)), 1.f){
        this->vecStartDir = vecDir;
        this->initialize();
        this->randomizeSpawn(CArea, fZMin, fZMax);
    }

CageBlocker::~CageBlocker(){}

void CageBlocker::initialize(){
    BaseBlocker::initialize();

    int nMaxDistance = 9999;
    MoveXY *pMovement = new MoveXY(this->strName + " MoveXY", nMaxDistance, vecStartDir, 500, false, false, false);
    this->attachComponent(pMovement); 

    CageChain *pCageChain = new CageChain(this->strName+"Chain");
    pCageChain->setScenePos({this->vecScenePos.x + 3,(this->vecScenePos.y - 7 * (100 - this->vecScenePos.z)) - 15,this->vecScenePos.z});
    this->attachChild(pCageChain);
}

void CageBlocker::createHitboxes(){
    this->pHitbox = new Hitbox(this->strName + " Hitbox", ShapeType::RECTANGLE, {0,0,0,0});
    this->attachChild(pHitbox);
}

void CageBlocker::onShot(int nKnockbackPower){
    MoveXY* pMoveComp = (MoveXY*) this->findComponentByName(this->strName + " MoveXY");
    
    //DROPS THE CAGE WHEN SHOT
    if(pMoveComp!= NULL){
        pMoveComp->setMoveDir({0, 1});
    }
}

void CageBlocker::update(sf::Time tDeltaTime){
    //STOP IT WHEN OUT OF SCREEN
    BaseBlocker::update(tDeltaTime);
    if(this->getScenePos().y > SCREEN_HEIGHT + this->pSprite->getGlobalBounds().height){
        MoveXY* pMoveComp = (MoveXY*) this->findComponentByName(this->strName + " MoveXY");
        pMoveComp->setComponentEnabled(false);
    }
}