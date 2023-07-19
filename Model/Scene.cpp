#include "Scene.hpp"

using namespace models;

/* * * * * * * [NEW CONTENT] * * * * * * */
/* Similar to [PoolableObjects], scenes
 * need a TAG to retrieve them from the
 * [SceneManager]. */
Scene::Scene(SceneTag ETag) {
    this->ETag = ETag;
}

Scene::~Scene() {}

void Scene::onLoadResources(){
    TextureManager::getInstance()->loadAll(this->ETag);
}


/* Unloading a scene involves DELETING all
 * objects in the [GameObjectManager]. */
void Scene::onUnloadObjects() {
    GameObjectManager::getInstance()->deleteAllObjects();
}

void Scene::onUnloadResources(){
    TextureManager::getInstance()->unloadAll();
}


void models::Scene::createBackground(std::string strName, int nStart){
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BACKGROUND, -1));

    Background* pBackground = new Background(strName, pTexture);
    this->registerObject(pBackground);
}


/* Registering [GameObjects] to a scene involves
 * adding them to the [GameObjectManager]. */
void Scene::registerObject(GameObject* pGameObject) {
    GameObjectManager::getInstance()->addObject(pGameObject);
}

SceneTag Scene::getTag() {
    return this->ETag;
}
/* * * * * * * * * * * * * * * * * * * * */
