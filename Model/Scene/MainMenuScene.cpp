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

MainMenuScene::MainMenuScene() : Scene(SceneTag::MAIN_MENU) {/* 
    MusicManager::getInstance()->getMusic(MusicType::MAIN_MENU)->setVolume(40.0f);
    MusicManager::getInstance()->getMusic(MusicType::MAIN_MENU)->play();
    MusicManager::getInstance()->getMusic(MusicType::MAIN_MENU)->setLoop(true); */
}

MainMenuScene::~MainMenuScene() {}

//  void MainMenuScene::createBackground() {
/*     AssetType EType = AssetType::BACKGROUND;
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(EType, 0));

    Background* pBackground = new Background("Main Menu Scene Background", pTexture);
    this->registerObject(pBackground); */
    /* Don't forget to REGISTER your [Background]
     * after you have properly setup this class. */

   /* AnimatedTexture *pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BACKGROUND, 0));
    Background* pBackground = new Background("SAs", pTexture);
    this->registerObject(pBackground);
} */



void MainMenuScene::onLoadObjects(){
    this->createBackground("Main Menu Background");
    this->registerObject(new MainMenu());
}

void MainMenuScene::onLoadResources(){
    Scene::onLoadResources();

    MusicManager::getInstance()->getMusic(MusicType::MAIN_MENU)->setVolume(40.0f);
    MusicManager::getInstance()->getMusic(MusicType::MAIN_MENU)->play();
    MusicManager::getInstance()->getMusic(MusicType::MAIN_MENU)->setLoop(true);
}


void MainMenuScene::onUnloadResources(){
    MusicManager::getInstance()->getMusic(MusicType::MAIN_MENU)->stop();

    Scene::onUnloadResources();
}