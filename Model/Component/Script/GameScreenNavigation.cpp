#include "GameScreenNavigation.hpp"

using namespace components;
using namespace systems;

GameScreenNavigation::GameScreenNavigation(GameNavigationInput* pNavInputRef) : Component("Game Screen Navigation", ComponentType::SCRIPT){
    this->pNavInputRef = pNavInputRef;
}

GameScreenNavigation::~GameScreenNavigation() {}

void GameScreenNavigation::perform(){
    this->nCooldownTicker++;

    if (this->nCooldownTicker < this->nSwitchCooldown){
        return;
    }

    if(this->pNavInputRef->isNeedChangeFront()){
        pNavInputRef->resetAllFlags();
        this->nCooldownTicker = 0;
        
        std::cout << "\n [VIEW]: FRONT";
        ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->setEnabled(true);     
        ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->setEnabled(false);     
    }
    else if(this->pNavInputRef->isNeedChangeRight()){
        pNavInputRef->resetAllFlags();
        this->nCooldownTicker = 0;

        std::cout << "\n [VIEW]: RIGHT";
        ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->setEnabled(false);
        ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->setEnabled(true);     
    }
}