#include "SceneManager.hpp"

using namespace systems;

void SceneManager::registerScene(Scene* pScene) {
    this->mapScene[pScene->getTag()] = pScene;
}

void SceneManager::loadScene(SceneTag ETag) {
    this->bLoading = true;
    this->ESceneToLoad = ETag;
}

void SceneManager::unloadScene() {
    if(this->pActiveScene != NULL) {
        this->pActiveScene->onUnloadObjects();
        this->pActiveScene->onUnloadResources();
    }
}

void SceneManager::checkLoadScene() {
    if(this->bLoading) {
        //UNLOAD CURRENT SCENE
        this->unloadScene();

        // ALLOW LOADING SCENE TO LOAD BETWEEN SCREEN SWITCHING
        if (pActiveScene == this->mapScene[SceneTag::LOADING]){
            //WHEN ALREADY LOADED LOADING SCENE, PROCEED TO LOAD TARGET SCENE
            this->pActiveScene = this->mapScene[this->ESceneToLoad];
            this->bLoading = false;
        }
        else{
            this->pActiveScene = this->mapScene[SceneTag::LOADING];
        }

        this->pActiveScene->onLoadResources();
        this->pActiveScene->onLoadObjects();
    }
}

bool SceneManager::isLoaded(SceneTag ETag) {
    return this->pActiveScene->getTag() == ETag;
}


/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
SceneManager* SceneManager::P_SHARED_INSTANCE = NULL;
SceneManager::SceneManager() {
    /* * * * * * * [NEW CONTENT] * * * * * * */
    /* [IMPORTANT] : Forgetting to set
     * [this->pActiveScene] to NULL was the
     * cause of the abrupt termination. For
     * some reason, this does not need to be
     * done in a Mac OS... */
    this->pActiveScene = NULL;
    /* * * * * * * * * * * * * * * * * * * * */
}
SceneManager::SceneManager(const SceneManager&) {}

SceneManager* SceneManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new SceneManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */
