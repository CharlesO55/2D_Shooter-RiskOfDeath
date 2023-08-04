#include "WispBlocker.hpp"

using namespace models;
using namespace components;

WispBlocker::WispBlocker(std::string strName, sf::FloatRect CArea, sf::Vector2f vecDir, float fZMin, float fZMax) : 
    BaseBlocker(strName, new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::WISP)), 0.3f){
        this->vecStartDir = vecDir;
        this->initialize();
        this->randomizeSpawn(CArea, fZMin, fZMax);
    }

WispBlocker::~WispBlocker(){}

void WispBlocker::initialize(){
    BaseBlocker::initialize();

    int nMaxDistance = this->nRNG(300 , SCREEN_HEIGHT/2);
    MoveXY *pMovement = new MoveXY(this->strName + " MoveXY", nMaxDistance, vecStartDir, 20, false, false);
    this->attachComponent(pMovement); 
}

void WispBlocker::createHitboxes(){
    this->pHitbox = new Hitbox(this->strName + " Hitbox", ShapeType::TRIANGLE, {50,25,0,0});
    this->attachChild(pHitbox);
}