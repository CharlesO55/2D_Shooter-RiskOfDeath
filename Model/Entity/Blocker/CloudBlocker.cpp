#include "CloudBlocker.hpp"

using namespace models;
using namespace components;

CloudBlocker::CloudBlocker(sf::FloatRect CArea, float fZMin, float fZMax) : 
    ScrollBlocker("Cloud Blocker", new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CLOUD)), EnumBlockerType::VERTICAL, 0.5f){
        if(this->getEType() == EnumBlockerType::HORIZONTAL)
            this->vecStartDir = sf::Vector2f{1,0};
        else    
            this->vecStartDir = sf::Vector2f{0,1};
        
        this->randomizeSpawn(CArea, fZMin, fZMax);

    this->CArea = CArea;
    this->fZMin = fZMin;
    this->fZMax = fZMax;
}

CloudBlocker::~CloudBlocker(){}

void CloudBlocker::initialize(){
    ScrollBlocker::initialize();

    int nMaxDistance = SCREEN_WIDTH + 200;
    MoveScroll *pMovement = new MoveScroll(this->strName + " MoveScroll", nMaxDistance, vecStartDir, this->nRNG(50, 100), this->getIsReversed());
    this->attachComponent(pMovement); 
}