#include "Component.hpp"

using namespace components;

Component::Component(std::string strName, EnumComponentType EType, models::GameObject* pOwner){
    this->EType = EType;
    this->strName = strName;
    this->pOwner = pOwner;
}

Component::~Component(){
    this->pOwner = NULL;
    this->EType = EnumComponentType::NONE;
}

models::GameObject* Component::getOwner() {
    if(this->pOwner == NULL){
        std::cout << this->strName << " OWNER IS NULL";
        throw "NO OWNER SET";
    }

    return this->pOwner;
}