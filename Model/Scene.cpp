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

/* Unloading a scene involves DELETING all
 * objects in the [GameObjectManager]. */
void Scene::onUnloadObjects() {
    GameObjectManager::getInstance()->deleteAllObjects();
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
