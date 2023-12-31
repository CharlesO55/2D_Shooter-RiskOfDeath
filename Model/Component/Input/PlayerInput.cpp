#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName) {
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
            pUI->updateInventory(1);
            break;

        case sf::Keyboard::Num2:
            pUI->updateInventory(2);
            break;

        case sf::Keyboard::Num3:
            pUI->updateInventory(3);
            break;

        case sf::Keyboard::R:
            PlayerManager::getInstance()->setReloading(true);
            break;

        default:
            break;
    }
}
