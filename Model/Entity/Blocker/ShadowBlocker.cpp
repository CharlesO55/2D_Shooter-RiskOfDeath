#include "ShadowBlocker.hpp"

using namespace models;
using namespace components;

ShadowBlocker::ShadowBlocker(std::string strName, sf::FloatRect CArea, sf::Vector2f vecDir, float fZMin, float fZMax) : 
    BaseBlocker(strName, new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CHEST)), 0.4f){
        this->vecStartDir = vecDir;
        this->initialize();
        this->randomizeSpawn(CArea, fZMin, fZMax);
    }

ShadowBlocker::~ShadowBlocker(){}

void ShadowBlocker::initialize(){
    BaseBlocker::initialize();

    int nMaxDistance = this->nRNG(300 , SCREEN_WIDTH/2);
    MoveXY *pMovement = new MoveXY(this->strName + " MoveXY", nMaxDistance, vecStartDir, 50, false, true);
    this->attachComponent(pMovement); 
}

void ShadowBlocker::createHitboxes(){
    this->pHitbox = new Hitbox(this->strName + " Hitbox", ShapeType::RECTANGLE, {90,0,-130,0});
    this->attachChild(pHitbox);
}