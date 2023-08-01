#include "BoulderBlocker.hpp"

using namespace models;
using namespace components;

BoulderBlocker::BoulderBlocker(sf::FloatRect CArea, sf::Vector2f vecDir, float fZMin, float fZMax) : 
    BaseBlocker("Boulder Blocker", new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BOULDER_ROUND)), 0.5f){
        this->vecStartDir = vecDir;
        this->initialize();
        this->randomizeSpawn(CArea, fZMin, fZMax);
    }

BoulderBlocker::~BoulderBlocker(){}

void BoulderBlocker::initialize(){
    BaseBlocker::initialize();

    int nMaxDistance = this->nRNG(300 , SCREEN_WIDTH/2);
    MoveXY *pMovement = new MoveXY(this->strName + " MoveXY", nMaxDistance, vecStartDir, 50, true);
    this->attachComponent(pMovement); 
}