#include "CrosshairMouseInput.hpp"

using namespace components;

CrosshairMouseInput::CrosshairMouseInput(std::string strName) : GeneralInput(strName) {
    this->bLeftClick = false;
    this->bRightClick = false;
    this->vecLocation = sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
}

void CrosshairMouseInput::perform() {
    switch(this->eEvent.type) {
        case sf::Event::MouseButtonPressed:
            this->processMouseInput(this->eEvent.mouseButton.button, true);
            break;
            
        case sf::Event::MouseButtonReleased:
            this->processMouseInput(this->eEvent.mouseButton.button, false);
            break;

        case sf::Event::MouseMoved:
            this->vecLocation.x = this->eEvent.mouseMove.x;
            this->vecLocation.y = this->eEvent.mouseMove.y;
            break;

        default:
            break;
    }
}

void CrosshairMouseInput::resetLeftClick() {
    this->bLeftClick = false;
}

void CrosshairMouseInput::processMouseInput(sf::Mouse::Button inMouse, bool bPressed) {
    switch(inMouse) {
        case sf::Mouse::Left:
            this->bLeftClick = bPressed;
            if (bPressed) {
                //Can also add an additional condition about the bullet count
                //MenuBar can be accessed via ViewManager. decrement bullets here
                //Implement an input for keyboard buttons that can also reload the bullets in a separate component
                SFXManager::getInstance()->getSound(SFXType::PLAYER_BULLET)->play();
                std::cout << "[LMB] : Pressed" << std::endl;
            }
            break;

        case sf::Mouse::Right:
            this->bRightClick = bPressed;
            if (bPressed) {
                std::cout << "[RMB] : Pressed" << std::endl;
            }
            break;

        default:
            break;
    }
}

bool CrosshairMouseInput::isLeftClick() {
    return this->bLeftClick;
}

bool CrosshairMouseInput::isRightClick() {
    return this->bRightClick;
}

sf::Vector2f CrosshairMouseInput::getLocation() {
    return this->vecLocation;
}
