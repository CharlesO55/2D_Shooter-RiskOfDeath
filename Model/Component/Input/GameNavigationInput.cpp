#include "GameNavigationInput.hpp"

using namespace components;

GameNavigationInput::GameNavigationInput(std::string strName) : GeneralInput(strName){}

GameNavigationInput::~GameNavigationInput(){}

void GameNavigationInput::perform(){
    if (this->eEvent.type == sf::Event::KeyPressed){
        this->processKeyInput();
    }
}

void GameNavigationInput::processKeyInput(){
    switch (this->eEvent.key.code){
        case sf::Keyboard::A:
            this->bChangeToFront = true;
            break;
        case sf::Keyboard::D:
            this->bChangeToRight = true;
            break;
        default:
            break;
    }
}

void GameNavigationInput::resetAllFlags(){
    this->bChangeToFront = false;
    this->bChangeToRight = false;
}


bool GameNavigationInput::isNeedChangeFront(){ return this->bChangeToFront; }
bool GameNavigationInput::isNeedChangeRight(){ return this->bChangeToRight; }