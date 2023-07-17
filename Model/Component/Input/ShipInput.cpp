#include "ShipInput.hpp"

using namespace components;

ShipInput::ShipInput(std::string strName) : GeneralInput(strName) {
    this->bSpace = false;
    this->bUp = false;
    this->bDown = false;
    this->bLeft = false;
    this->bRight = false;
}

void ShipInput::perform() {
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

void ShipInput::processKeyInput(bool bPressed) {
    sf::Keyboard::Key inKey = this->eEvent.key.code;

    switch(inKey) {
        case sf::Keyboard::Space:
            this->bSpace = bPressed;
            break;

        case sf::Keyboard::W:
            this->bUp = bPressed;
            break;

        case sf::Keyboard::S:
            this->bDown = bPressed;
            break;

        case sf::Keyboard::A:
            this->bLeft = bPressed;
            break;

        case sf::Keyboard::D:
            this->bRight = bPressed;
            break;

        default:
            break;
    }
}

void ShipInput::resetSpace() {
    this->bSpace = false;
}

bool ShipInput::isSpace() {
    return this->bSpace;
}

bool ShipInput::isUp() {
    return this->bUp;
}

bool ShipInput::isDown() {
    return this->bDown;
}

bool ShipInput::isLeft() {
    return this->bLeft;
}

bool ShipInput::isRight() {
    return this->bRight;
}
