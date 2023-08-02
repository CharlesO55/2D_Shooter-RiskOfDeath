#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName) {
    this->bOne = false;
    this->bTwo = false;
    this->bThree = false;
    this->bR = false;
}

void PlayerInput::perform() {
    switch(this->eEvent.type) {
        case sf::Event::KeyPressed:
            this->processKeyInput(true);
            break;
            
        case sf::Event::KeyReleased:
            this->processKeyInput(false);
            break;

        default:
            break;
    }
}

void PlayerInput::processKeyInput(bool bPressed) {
    sf::Keyboard::Key inKey = this->eEvent.key.code;
    PlayerUI* pUI = (PlayerUI*)GameObjectManager::getInstance()->findObjectByName("Player UI");

    switch(inKey) {
        case sf::Keyboard::Num1:
            this->bOne = bPressed;
            break;

        case sf::Keyboard::Num2:
            this->bTwo = bPressed;
            break;

        case sf::Keyboard::Num3:
            this->bThree = bPressed;
            break;

        case sf::Keyboard::R:
            pUI->reloadBullets();
            break;

        default:
            break;
    }
}

void PlayerInput::resetKeyPress() {
    this->bOne = false;
}