#include "InputButton.hpp"

using namespace components;

InputButton::InputButton(std::string strName, models::GameObject* pButton) : Component(strName, EnumComponentType::INPUT, pButton){

}

void InputButton::assignOnProcessInput(sf::Event EEvent){
    this->EEvent = EEvent;
}

void InputButton::perform(){
    if(this->getOwner()->getSubtype() != EnumObjSubTypes::TEXTBUTTON){
        std::cout << this->strName << "IS NOT ASSIGNED TO A TEXTBUTTON";
        throw "MISMATCH";
    }
    
    TextButton *pButton = (TextButton*)this->pOwner;
    //HIGHLIGHT HOVER
    pButton->setHighlight(pButton->getGenericGlobalBounds().contains(this->EEvent.mouseMove.x, this->EEvent.mouseMove.y));

    //CLICK
    if (EEvent.MouseButtonPressed && EEvent.mouseButton.button == sf::Mouse::Left &&
    pButton->getGenericGlobalBounds().contains(EEvent.mouseButton.x, EEvent.mouseButton.y)){
        pButton->setClicked(true);
    }
}