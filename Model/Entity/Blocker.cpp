#include "Blocker.hpp"

using namespace models;

Blocker::Blocker(sf::Texture* pTexture, std::string strName, GameObject* pParent, float fX, float fY) 
        : GameObject(pTexture, strName + " Blocker", pParent, fX, fY){
        
    
}

Blocker::~Blocker(){

}

void Blocker::initialize(){
    GameObject::initialize();

    
}