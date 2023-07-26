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
        std::cout << "\n [VIEW]: FRONT";
        //DISABLE SIDE VIEW
        ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->setEnabled(false);     

        //RESET FRONT VIEW
        ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->setEnabled(true);     
        ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->centerSpriteOrigin();
        ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite()->setScale(1.f, 1.f);     

        //RESET INPUT FLAGS
        this->resetInputFlags();
    }
    else if(this->pNavInputRef->isNeedChangeRight()){
        std::cout << "\n [VIEW]: RIGHT";
        //DISABLE FRONT VIEW
        ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->setEnabled(false);
        //ENABLE SIDE VIEW
        ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->setEnabled(true);     

        //RESET INPUT FLAGS
        this->resetInputFlags();
    }

    else if (this->pNavInputRef->isZoomClick()){
        std::cout << "\n [VIEW] ZOOM";

        //UPDATE FRONT VIEW
        sf::Sprite* pViewSprite = ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite();

        
        float fZoom = 1.25f;
        sf::Vector2f vecOrigin = pNavInputRef->getMouseLoc();

        std::cout << vecOrigin.x << " : " << vecOrigin.y << std::endl;



        pViewSprite->setOrigin(vecOrigin);
        pViewSprite->setScale(fZoom , fZoom);

        //WIP
/* 
        sf::RenderStates CRender = pViewSprite->getTransform();
        sf::FloatRect rect = pViewSprite->getTransform().transformRect();
 */
        //RESET INPUT FLAGS
        this->resetInputFlags();
    }
}

void GameScreenNavigation::resetInputFlags(){
    this->pNavInputRef->resetAllFlags();
    this->nCooldownTicker = 0;
}