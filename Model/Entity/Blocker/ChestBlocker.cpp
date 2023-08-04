#include "ChestBlocker.hpp"

using namespace models;
using namespace components;

ChestBlocker::ChestBlocker(std::string strName, sf::FloatRect CArea, sf::Vector2f vecDir, float fZMin, float fZMax) : 
    BaseBlocker(strName, new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CHEST)), 0.08f){
        this->vecStartDir = vecDir;
        this->initialize();
        this->randomizeSpawn(CArea, fZMin, fZMax);
    }

ChestBlocker::~ChestBlocker(){}

void ChestBlocker::initialize(){
    BaseBlocker::initialize();

    int nMaxDistance = 9999;
    MoveXY *pMovement = new MoveXY(this->strName + " MoveXY", nMaxDistance, vecStartDir, 50, false);
    this->attachComponent(pMovement); 
}

void ChestBlocker::createHitboxes(){
    this->pHitbox = new Hitbox(this->strName + " Hitbox", ShapeType::RECTANGLE, {0,0,0,0});
    this->attachChild(pHitbox);
}