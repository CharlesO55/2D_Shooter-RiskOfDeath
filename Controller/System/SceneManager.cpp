#include "SceneManager.hpp"

using namespace systems;

/* * * * * * * [NEW CONTENT] * * * * * * */
/* Adds [pScene] to the [mapScene]. This is
 * to be done at the Game Loop's constructor
 * (i.e. in the [Game] class). */
void SceneManager::registerScene(Scene* pScene) {
    this->mapScene[pScene->getTag()] = pScene;
}

/* Raises the INTENT to load the scene given
 * by [ETag]. The ACTUAL scene loading occurs
 * at the [checkLoadScene()] function call. */
void SceneManager::loadScene(SceneTag ETag) {
    this->bLoading = true;
    this->ESceneToLoad = ETag;
    /* You can show a [LoadingScreen] here. */
}

/* Unloads the current scene, given by
 * [pActiveScene]. Take note that you MUST
 * unload the OBJECTS before unloading the
 * RESOURCES (i.e. Textures, Fonts, SFXs). */
void SceneManager::unloadScene() {
    if(this->pActiveScene != NULL) {
        this->pActiveScene->onUnloadObjects();
        this->pActiveScene->onUnloadResources();
    }
}

/* Checks if an INTENT to load a new scene
 * has been raised (i.e. if [bLoading] is true).
 * If so, it unloads the current scene, then
 * switches [pActiveScene] to the current scene
 * whose tag is held by [ESceneToLoad]. */
void SceneManager::checkLoadScene() {
    if(this->bLoading) {
        this->unloadScene();
        this->pActiveScene = this->mapScene[this->ESceneToLoad];

        /* When LOADING a scene, load the RESOURCES
         * before the OBJECTS. This is the OPPOSITE
         * of what is done when UNLOADING a scene. */
        this->pActiveScene->onLoadResources();
        this->pActiveScene->onLoadObjects();

        /* Remember to set this to false, else your
         * scene will keep getting reloaded again
         * and again. */
        this->bLoading = false;
    }
}

/* A helper function that returns whether
 * [ETag] is the currently loaded scene or
 * not. Sample use cases include knowing
 * when to hide a [LoadingScreen]. */
bool SceneManager::isLoaded(SceneTag ETag) {
    return this->pActiveScene->getTag() == ETag;
}
/* * * * * * * * * * * * * * * * * * * * */

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
