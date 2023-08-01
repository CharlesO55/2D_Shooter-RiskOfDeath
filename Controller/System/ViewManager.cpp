#include "ViewManager.hpp"

using namespace systems;

void ViewManager::registerView(View* pView) {
    this->mapView[pView->getTag()] = pView;
}

void ViewManager::unregisterView(View* pView) {
    this->mapView.erase(pView->getTag());
}

View* ViewManager::getView(ViewTag ETag) {
    if (this->mapView[ETag] == NULL){
        std::cout << "[ERROR] ViewManager getView failed to find ViewTag";
        throw 0;
    }

    return this->mapView[ETag];
}

int ViewManager::getScreenRows(){ return this->nScreenRows; }
int ViewManager::getScreenCols(){ return this->nScreenCols; }

void ViewManager::incrementRows(){ 
    this->nScreenRows++;

    if (nScreenRows > 6){
        this->nScreenRows = 1;
    }
}

void ViewManager::incrementCols(){  
    this->nScreenCols++;

    if (nScreenCols > 6){
        this->nScreenCols = 1;
    }
}


/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
ViewManager* ViewManager::P_SHARED_INSTANCE = NULL;
ViewManager::ViewManager() {}
ViewManager::ViewManager(const ViewManager&) {}

ViewManager* ViewManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new ViewManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */
