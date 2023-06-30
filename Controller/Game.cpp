#include "Game.hpp"



using namespace controllers;
using namespace singletons;

using namespace entities;

Game::Game() : CWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "MP [Ursua, Ong]", sf::Style::Titlebar | sf::Style::Close) {
    this->CWindow.setFramerateLimit(FRAME_LIMIT);

    //SINGLETONS
    
    
    this->pObj = new models::GameObject(TextureManager::getInstance()->getTexture(EnumTextures::TEST2), "test", NULL, 5, 9);
    GameObjectManager::getInstance()->registerObject(this->pObj);

    GameObjectManager::getInstance()->registerObject(new GameObject(TextureManager::getInstance()->getTexture(EnumTextures::TEST3), "esr", NULL, 500.f));
    
    GameObject *pOC = new GameObject(TextureManager::getInstance()->getTexture(EnumTextures::TEST1), "Tsada", pObj);
    pObj->getSprite()->setPosition(0.f, 500.f);
    pObj->getSprite()->setRotation(90.f);
    pOC->getSprite()->setRotation(-90.f);

    Monster* pMonster = new Monster(TextureManager::getInstance()->getTexture(EnumTextures::TEST_MONSTER), "Blunt");
    GameObjectManager::getInstance()->registerObject(pMonster);

    GameObjectManager::getInstance()->registerObject(new ui::TextButton("TESSSSSSST", "NAEEEEEEEE"));
}

Game::~Game(){}

void Game::run(){
    sf::Clock CClock;
    sf::Time CDeltaTime = sf::Time::Zero;
    sf::Time CTimePerFrame = sf::seconds(1.f / FRAME_LIMIT);

    while (!this->bEndGame){        
        this->processEvents();

        CDeltaTime += CClock.restart();
        while (CDeltaTime > CTimePerFrame){
            CDeltaTime -= CTimePerFrame;
            this->update(CTimePerFrame);
        }        
        this->render();
    }
}

void Game::processEvents(){
    sf::Event eEvent;

    while(this->CWindow.pollEvent(eEvent)){
        if (eEvent.key.code == sf::Keyboard::Escape || eEvent.type == sf::Event::Closed) {
            std::cout << "\nCLOSING GAME";
            this->bEndGame = true;
            break;
        }
        GameObjectManager::getInstance()->processEvents(eEvent);
    };
}

void Game::update(sf::Time CTime){
    GameObjectManager::getInstance()->updateObjects(CTime);
}

void Game::render(){
    this->CWindow.clear();
    singletons::GameObjectManager::getInstance()->drawObjects(&CWindow);
    this->CWindow.display();
}