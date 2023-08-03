#include "CrosshairMouseInput.hpp"

using namespace components;

CrosshairMouseInput::CrosshairMouseInput(std::string strName) : GeneralInput(strName) {
    this->bLeftClick = false;
    this->bRightClick = false;
    this->vecLocation = sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
}


void CrosshairMouseInput::perform() {
    if(this->bResetFlags){
        this->bLeftClick = false;
        this->bRightClick = false;
        this->bResetFlags = false;
    }

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

void CrosshairMouseInput::resetRightClick() {
    this->bRightClick = false;
}

void CrosshairMouseInput::processMouseInput(sf::Mouse::Button inMouse, bool bPressed) {
    if (ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->isEnabled()) {
        switch(inMouse) {
            case sf::Mouse::Left:
                this->bLeftClick = bPressed;
                if (bPressed) {
                    std::cout << "[LMB] : Pressed" << std::endl;
                    SFXManager::getInstance()->getSound(SFXType::PLAYER_BULLET)->play();
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

     else   
        std::cout << "[CROSSHAIR MOUSE INPUT] : Shooting Unavailable for Side View" << std::endl;
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


void CrosshairMouseInput::flagForReset(){
    this->bResetFlags = true;
}