#include "PlaneBlocker.hpp"

using namespace models;
using namespace components;

PlaneBlocker::PlaneBlocker(sf::FloatRect CArea, float fZMin, float fZMax) : 
    ScrollBlocker("Plane Blocker", new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLANE)), EnumBlockerType::HORIZONTAL, 0.5f){
        if(this->getEType() == EnumBlockerType::HORIZONTAL)
            this->vecStartDir = sf::Vector2f{1,0};
        else    
            this->vecStartDir = sf::Vector2f{0,1};
        
        //this->initialize();
        this->randomizeSpawn(CArea, fZMin, fZMax);

    this->CArea = CArea;
    this->fZMin = fZMin;
    this->fZMax = fZMax;
}

PlaneBlocker::~PlaneBlocker(){}

void PlaneBlocker::initialize(){
    ScrollBlocker::initialize();

    //int nMaxDistance = this->nRNG(300 , SCREEN_WIDTH/2);
    int nMaxDistance = SCREEN_WIDTH + 200;
    //MoveXY *pMovement = new MoveXY(this->strName + " MoveXY", nMaxDistance, vecStartDir, 50, true);
    MoveScroll *pMovement = new MoveScroll(this->strName + " MoveScroll", nMaxDistance, vecStartDir,  this->nRNG(100, 300), this->getIsReversed());
    this->attachComponent(pMovement); 
}