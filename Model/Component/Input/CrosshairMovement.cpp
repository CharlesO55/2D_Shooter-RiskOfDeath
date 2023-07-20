#include "CrosshairMovement.hpp"

using namespace components;

CrosshairMovement::CrosshairMovement(std::string strName) : GeneralInput(strName) {}

void CrosshairMovement::perform() {
    switch(this->eEvent.type) {
        case sf::Event::MouseMoved:
            this->pOwner->getSprite()->setPosition(this->eEvent.mouseMove.x, this->eEvent.mouseMove.y);
            break;

        default:
            break;
    }
}
