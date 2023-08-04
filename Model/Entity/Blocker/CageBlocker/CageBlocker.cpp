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

    int nMaxDistance = this->nRNG(300 , SCREEN_WIDTH/2);
    MoveXY *pMovement = new MoveXY(this->strName + " MoveXY", nMaxDistance, vecStartDir, 50, false, false);
    this->attachComponent(pMovement); 

    CageChain *pCageChain = new CageChain(this->strName+"Chain");
    pCageChain->setScenePos({this->vecScenePos.x + 3,(this->vecScenePos.y - 7 * (100 - this->vecScenePos.z)) - 15,this->vecScenePos.z});
    this->attachChild(pCageChain);
}

void CageBlocker::createHitboxes(){
    this->pHitbox = new Hitbox(this->strName + " Hitbox", ShapeType::RECTANGLE, {0,0,0,0});
    this->attachChild(pHitbox);
}