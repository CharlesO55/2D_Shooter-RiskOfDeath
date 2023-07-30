#include "MainMenu.hpp"

using namespace views;

/* * * * * * * [NEW CONTENT] * * * * * * */
/* This class renders a [MainMenu] screen
 * containing a [Background] and a START
 * [Button]. */
MainMenu::MainMenu() : View(ViewTag::MAIN_MENU, "Main Menu View") {
    ViewManager::getInstance()->registerView(this);
}

MainMenu::~MainMenu() {}

/* Creates the [Background] and [Button],
 * and layouts it in the screen. */
void MainMenu::initialize() {
    /* AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BUTTON_START));
    Button* pButton = new Button(this->getName() + " Start Button", pTexture);
    
    pButton->getSprite()->setScale(0.6f, 0.6f);
    pButton->getSprite()->setPosition(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT * 0.79);
    pButton->centerSpriteOrigin();

    pButton->setListener(this);
    this->attachChild(pButton); */
    /* this->createButton(this, 
        this->strName + " Start Button", 
        AssetType::BUTTON_START, 
        {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}
    ); */

    //GAME TITLE 
    this->attachChild (new 
        views::Text("Title", "Risk of Death",
            {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2.8},
            FontType::DEFAULT,
            DEFAULT_TEXT_SIZE * 3,
            true
        )
    );
/* 
    views::Text* pQuitText = new views::Text("Quit Text", "QUIT", {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 1.5}, FontType::DEFAULT, DEFAULT_TEXT_SIZE * 2, true);
    Button* pQuitButton = new Button("Quit Button", pQuitText->getText());
    pQuitButton->setListener(this);
    this->attachChild(pQuitButton); */
    float fOffset = 100;
    this->createTextButton(this, "Start Button", "Start", {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + fOffset}, DEFAULT_TEXT_SIZE * 1.5);
    this->createTextButton(this, "Leaderboard Button", "Leaderboard", {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + fOffset * 2}, DEFAULT_TEXT_SIZE * 1.5);
    this->createTextButton(this, "Quit Button", "Quit Game", {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + fOffset * 3}, DEFAULT_TEXT_SIZE * 1.5);
    this->createTextButton(this, "Debug Button", "Old Debug", {150.f, 50.f});
}

void MainMenu::onClick(Button* pButton) {
    /* * * * *  [PRACTICE EXERCISE]  * * * * */
    /* Check if [pButton] (which is the clicked
     * [Button]) is equal to your START [Button].
     * If so, LOAD the [GameScene].
     * 
     * You must use [SceneManager] in your
     * solution. Also, try to do this WITHOUT
     * making the START [Button] into a
     * field. */
    /* * * * * * * * * * * * * * * * * * * * */
    if (pButton->getName() == "Start Button"){
        systems::SceneManager::getInstance()->loadScene(SceneTag::GAME_PROPER);
        
        MusicManager::getInstance()->getMusic(MusicType::MAIN_MENU)->stop();
        MusicManager::getInstance()->getMusic(MusicType::GAME_PROPER)->setVolume(40.0f);
        MusicManager::getInstance()->getMusic(MusicType::GAME_PROPER)->play();
        MusicManager::getInstance()->getMusic(MusicType::GAME_PROPER)->setLoop(true);
    }
    else if (pButton->getName() == "Leaderboard Button"){
        systems::SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);

        MusicManager::getInstance()->getMusic(MusicType::MAIN_MENU)->stop();
        MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->setVolume(40.0f);
        MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->play();
        MusicManager::getInstance()->getMusic(MusicType::LEADERBOARDS)->setLoop(true);
    }
    else if (pButton->getName() == "Quit Button"){
        bCloseGame = true;
    }
    else if (pButton->getName() == "Debug Button"){
        systems::SceneManager::getInstance()->loadScene(SceneTag::GAME_SCENE);
    }
}

void MainMenu::onRelease(Button* pButton) {}
/* * * * * * * * * * * * * * * * * * * * */
