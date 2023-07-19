#include "Game.hpp"

using namespace controllers;

Game::Game() : rwWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Title", sf::Style::Titlebar | sf::Style::Close) {
    this->rwWindow.setFramerateLimit(FRAME_RATE_LIMIT);
    AnimatedTexture* pTexture;
    /* [IMPORTANT] : Typically, we add a TAG to
     * these RESOURCE Managers, telling them
     * which scene-specific resources to load.
     * Then, we do their call in a scene's
     * [onLoadResources()] function. Since this
     * sample project is small, there's no need
     * to do that yet. However, remember to do
     * so in your MP. */
    // TextureManager::getInstance()->loadAll();
    SFXManager::getInstance()->loadAll();
    FontManager::getInstance()->loadAll();

    /* * * * *  [PRACTICE EXERCISE]  * * * * */
    /* Create ALL your scenes. Once you have
     * properly implemented [MainMenuScene],
     * remember to register it here. */
    SceneManager::getInstance()->registerScene(new MainMenuScene());
    SceneManager::getInstance()->registerScene(new GameScene());
    SceneManager::getInstance()->registerScene(new GameProper());
    SceneManager::getInstance()->registerScene(new scenes::LeaderboardScene());
    /* * * * * * * * * * * * * * * * * * * * */
    
    /* * * * *  [PRACTICE EXERCISE]  * * * * */
    /* Once you have properly implemented
     * [MainMenuScene], change this part of the
     * code such that the first scene loaded
     * is [MainMenuScene] as opposed to the
     * [GameScene]. */
    SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU);
    /* * * * * * * * * * * * * * * * * * * * */
}

void Game::run() {
    sf::Clock CClock = sf::Clock();
    sf::Time tLastUpdate = sf::Time::Zero;
    sf::Time tTimePerFrame = sf::seconds(1.0f / FRAME_RATE_LIMIT);

    while(this->rwWindow.isOpen()) {
        this->processEvents();
        tLastUpdate += CClock.restart();

        while(tLastUpdate > tTimePerFrame) {
            tLastUpdate -= tTimePerFrame;
            this->update(tTimePerFrame);
        }
        
        /* * * * * * * [NEW CONTENT] * * * * * * */
        /* Check the [Slides] for more information
         * about this function call placement. */
        SceneManager::getInstance()->checkLoadScene();
        /* * * * * * * * * * * * * * * * * * * * */
        this->render();
    }
}

void Game::processEvents() {
    sf::Event eEvent;
    if(bCloseGame){
        std::cout << "\nQUIT";
        this->rwWindow.close();
    }

    while(this->rwWindow.pollEvent(eEvent)) {
        switch(eEvent.type) {
            case sf::Event::Closed:
                SFXManager::getInstance()->unloadAll();
                this->rwWindow.close();
                break;
  
            default:
                GameObjectManager::getInstance()->processInput(eEvent);
                break;
        }
    }
}

void Game::update(sf::Time tDeltaTime) {
    GameObjectManager::getInstance()->update(tDeltaTime);
}

void Game::render() {
    this->rwWindow.clear();
    GameObjectManager::getInstance()->draw(&this->rwWindow);
    this->rwWindow.display();
}
