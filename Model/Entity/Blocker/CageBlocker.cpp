#include "CageBlocker.hpp"

using namespace models;
using namespace components;

CageBlocker::CageBlocker(std::string strName, sf::FloatRect CArea, sf::Vector2f vecDir, float fZMin, float fZMax) : 
    BaseBlocker(strName, new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CAGE)), 1.f){
        this->vecStartDir = vecDir;
        this->initialize();
        this->randomizeSpawn(CArea, fZMin, fZMax);
    }

CageBlocker::~CageBlocker(){}

void CageBlocker::initialize(){
    BaseBlocker::initialize();

    int nMaxDistance = this->nRNG(300 , SCREEN_WIDTH/2);
    MoveXY *pMovement = new MoveXY(this->strName + " MoveXY", nMaxDistance, vecStartDir, 50, false);
    this->attachComponent(pMovement); 
}

void CageBlocker::createHitboxes(){
    this->pHitbox = new Hitbox(this->strName + " Hitbox", ShapeType::RECTANGLE, {0,1100,0,-1100});
    this->attachChild(pHitbox);
}