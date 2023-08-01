#include "GameScreenNavigation.hpp"

using namespace components;
using namespace systems;

GameScreenNavigation::GameScreenNavigation(GameNavigationInput* pNavInputRef) : Component("Game Screen Navigation", ComponentType::SCRIPT){
    this->pNavInputRef = pNavInputRef;
    this->bFreeZoomMode = (ViewManager::getInstance()->getScreenRows() == 1 && ViewManager::getInstance()->getScreenCols() == 1) ? true : false;
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

        EnemyManager::getInstance()->switchEnemiesTexture(ViewTag::FRONTVIEW_SCREEN);

        //RESET INPUT FLAGS
        this->resetInputFlags();
    }
    else if(this->pNavInputRef->isNeedChangeRight()){
        std::cout << "\n [VIEW]: RIGHT";
        //DISABLE FRONT VIEW
        ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->setEnabled(false);
        //ENABLE SIDE VIEW
        ViewManager::getInstance()->getView(ViewTag::SIDEVIEW_SCREEN)->setEnabled(true);
        EnemyManager::getInstance()->switchEnemiesTexture(ViewTag::SIDEVIEW_SCREEN);

        //RESET INPUT FLAGS
        this->resetInputFlags();
    }

    else if (this->pNavInputRef->isZoomClick()){
        sf::Vector2f vecZoom = ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite()->getScale();
        //ONLY ZOOM WHEN NOT ZOOMED IN
        if (vecZoom.x == 1 && vecZoom.y == 1){

            //SWTICH EITHER FREE ZOOM OR SCREEN DETERMINED
            if (this->bFreeZoomMode){
                this->freeZoomScreen();
            }
            else{
                this->screenLockedZoomScreen();
            }
        }
        
        //RESET INPUT FLAGS
        this->resetInputFlags();
    }
}


void GameScreenNavigation::freeZoomScreen(){
    //ZOOMS IN ANYWHERE AS WITH 2x SCALE

    std::cout << "\n [VIEW] FREE ZOOM";
    float fZoom = 2.f;

    //GET FRONT VIEW
    sf::Sprite* pViewSprite = ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite();

    //CALCULATE ZOOM 
    sf::Vector2f vecOrigin = pNavInputRef->getMouseLoc();
    sf::Vector2f vecMaxOffset = {SCREEN_WIDTH/4, SCREEN_HEIGHT/4};  //BASED ON 2X ZOOM
    this->keepInBounds(&(vecOrigin.x), SCREEN_WIDTH/2 - vecMaxOffset.x, SCREEN_WIDTH/2 + vecMaxOffset.x);
    this->keepInBounds(&(vecOrigin.y), SCREEN_HEIGHT/2 - vecMaxOffset.y, SCREEN_HEIGHT/2 + vecMaxOffset.y);

    //1.x 640   :   640-0
    //1.25 510  :   640-130
    //1.5x 430  :   640-210
    //2.x 320   :   640-320
    //3.x 215   :   640-425

    std::cout << vecOrigin.x << " : " << vecOrigin.y << std::endl;

    //UPDATE FRONT VIEW
    pViewSprite->setOrigin(vecOrigin);
    pViewSprite->setScale(fZoom , fZoom);
}


void GameScreenNavigation::screenLockedZoomScreen(){
    std::cout << "\n [VIEW] SCREEN-LOCK ZOOM";

    //GET FRONT VIEW
    sf::Sprite* pViewSprite = ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite();

    //CALCULATE ZOOM 
    
    //FIND WHERE THE ORIGIN SHOULD BE
    sf::Vector2f vecOrigin = pNavInputRef->getMouseLoc();

    //DETERMINE WHERE ORIGIN SHOULD BE
    int aScreenDimension[2] = { 
        SCREEN_WIDTH / ViewManager::getInstance()->getScreenRows(),
        SCREEN_HEIGHT / ViewManager::getInstance()->getScreenCols()
    };

    int aScreenIndex[2] = {
        (int)(vecOrigin.x / aScreenDimension[0]),
        (int)(vecOrigin.y / aScreenDimension[1])
    };

    std::cout << "\nSCREEN : [" << aScreenIndex[0] << ", " << aScreenIndex[1] << "]\n";
    
    vecOrigin.x = aScreenDimension[0] * aScreenIndex[0] + (aScreenDimension[0] / 2);
    vecOrigin.y = aScreenDimension[1] * aScreenIndex[1] + (aScreenDimension[1] / 2);

    std::cout << "\nCENTER : [" << vecOrigin.x << ", " << vecOrigin.y << "]\n";

    pViewSprite->setOrigin(vecOrigin);
    pViewSprite->setScale(ViewManager::getInstance()->getScreenRows(), ViewManager::getInstance()->getScreenCols());
}


void GameScreenNavigation::resetInputFlags(){
    this->pNavInputRef->resetAllFlags();
    this->nCooldownTicker = 0;
}


void GameScreenNavigation::keepInBounds(float *pValue, float fMin, float fMax){
    if(*pValue < fMin)
        { *pValue = fMin;}
    else if(*pValue > fMax)
        { *pValue = fMax;}
}