#include "InputBase.hpp"

using namespace components;

InputBase::InputBase(std::string strName, models::GameObject* pOwner) : Component(strName, EnumComponentType::INPUT, pOwner){

}

void InputBase::assignOnProcessInput(sf::Event EEvent){
    this->EEvent = EEvent;
}