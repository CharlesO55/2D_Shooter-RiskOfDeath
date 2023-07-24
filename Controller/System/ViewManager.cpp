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
