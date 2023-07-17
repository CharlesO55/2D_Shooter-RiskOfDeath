#include "MainMenuScene.hpp"

using namespace scenes;

/* * * * *  [PRACTICE EXERCISE]  * * * * */
/* COMPLETE this class. This class is meant
 * to be a SCENE that shows a simple
 * [MainMenu]. You may use [GameScene] as
 * your reference.
 * 
 * When LOADING this scene, it should create
 * a [Background], as well as a [MainMenu]
 * [View].
 * 
 * The [createBackground()] function is
 * already provided for you. But you
 * must create and register the [MainMenu]
 * [View] on your own.*/

MainMenuScene::MainMenuScene() {}

MainMenuScene::~MainMenuScene() {}

void MainMenuScene::createBackground() {
    AssetType EType = AssetType::BACKGROUND;
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(EType, 0));

    Background* pBackground = new Background("Main Menu Scene Background", pTexture);
    /* Don't forget to REGISTER your [Background]
     * after you have properly setup this class. */
}

/* * * * * * * * * * * * * * * * * * * * */
