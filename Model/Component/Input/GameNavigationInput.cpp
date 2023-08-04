#include "GameNavigationInput.hpp"

using namespace components;
using namespace systems;
using namespace controllers;

GameNavigationInput::GameNavigationInput(std::string strName) : GeneralInput(strName){}

GameNavigationInput::~GameNavigationInput(){}

void GameNavigationInput::perform(){
    if (this->eEvent.type == sf::Event::KeyPressed){
        this->processKeyInput();
    }
    else if (this->eEvent.type == sf::Event::MouseButtonPressed){
        this->processMouseInput();
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
        case sf::Keyboard::Space:
            this->processScreenPause();
            break;
        case sf::Keyboard::Tab:
            this->processDebugCommand();
            break;
        default:
            break;
    }
}
 
void GameNavigationInput::processMouseInput(){ 
    if (this->eEvent.mouseButton.button == sf::Mouse::Right && ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->isEnabled()){
        this->bZoomClick = true;
        this->vecMousePos = {
            (float)this->eEvent.mouseButton.x,
            (float)this->eEvent.mouseButton.y
        };
    } 
}

void GameNavigationInput::processScreenPause(){
    if(GameStateManager::getInstance()->isPaused()){
        GameStateManager::getInstance()->resume();
    }
    else{
        GameStateManager::getInstance()->pause();
    }
}

void GameNavigationInput::resetAllFlags(){
    this->bChangeToFront = false;
    this->bChangeToRight = false;
    this->bZoomClick = false;
}


bool GameNavigationInput::isNeedChangeFront(){ return this->bChangeToFront; }
bool GameNavigationInput::isNeedChangeRight(){ return this->bChangeToRight; }
bool GameNavigationInput::isZoomClick()      { return this->bZoomClick; }
bool GameNavigationInput::isZooming()      { return this->bZooming; }
void GameNavigationInput::setZooming(bool bState) { this->bZooming = bState; }


sf::Vector2f GameNavigationInput::getMouseLoc(){ return this->vecMousePos; }







/*
    FOR DEBUGGING ONLY, NOT MEANT TO BE FOR RELEASE
*/
using namespace controllers;
void GameNavigationInput::processDebugCommand(){

    //FOR TESTING GAMEOBJECT SORTING
    GameObjectManager::getInstance()->printAllItemsDebug();
    
    //PAUSE
    this->processScreenPause();
}