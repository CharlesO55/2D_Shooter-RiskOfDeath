#include "MainMenu.hpp"

using namespace views;
using namespace systems;

MainMenu::MainMenu() : View(ViewTag::MAIN_MENU, "Main Menu View") { ViewManager::getInstance()->registerView(this);}

MainMenu::~MainMenu() {}

void MainMenu::initialize() {
    //GAME TITLE 
    this->attachChild (new 
        views::Text("Title", "Risk of Death",
            {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2.8},
            FontType::DEFAULT,
            DEFAULT_TEXT_SIZE * 3,
            true
        )
    );


    float fOffset = 100;
    this->createTextButton(this, "Start Button", "Start", {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + fOffset}, DEFAULT_TEXT_SIZE * 1.5);
    this->createTextButton(this, "Leaderboard Button", "Leaderboard", {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + fOffset * 2}, DEFAULT_TEXT_SIZE * 1.5);
    this->createTextButton(this, "Quit Button", "Quit Game", {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + fOffset * 3}, DEFAULT_TEXT_SIZE * 1.5);
    this->createTextButton(this, "Debug Button", "Old Debug", {150.f, 50.f});


    //SCREEN TOGGLE SETTINGS
    int nDim[2] = {ViewManager::getInstance()->getScreenRows(), ViewManager::getInstance()->getScreenCols()}; 
    int nFontSize = 20;

    this->pScreenCountText[0] = new views::Text("Rows Text", "Screen Rows: " + std::to_string(nDim[0]), {SCREEN_WIDTH - 200, DEFAULT_TEXT_SIZE}, FontType::DEFAULT, nFontSize, true);
    this->pScreenCountText[1] = new views::Text("Cols Text", "Screen Cols: " + std::to_string(nDim[1]), {SCREEN_WIDTH - 200, DEFAULT_TEXT_SIZE * 2.5}, FontType::DEFAULT, nFontSize, true);

    this->createTextButton(this, "Change Rows Button", "Change", {SCREEN_WIDTH - 50, DEFAULT_TEXT_SIZE}, nFontSize);
    this->createTextButton(this, "Change Cols Button", "Change", {SCREEN_WIDTH - 50, DEFAULT_TEXT_SIZE * 2.5}, nFontSize);

    this->attachChild(this->pScreenCountText[0]);
    this->attachChild(this->pScreenCountText[1]);
}

void MainMenu::onClick(Button* pButton) {
    if (pButton->getName() == "Start Button")
        systems::SceneManager::getInstance()->loadScene(SceneTag::GAME_PROPER);
    
    else if (pButton->getName() == "Leaderboard Button")
        systems::SceneManager::getInstance()->loadScene(SceneTag::LEADERBOARD);

    else if (pButton->getName() == "Quit Button")
        GameStateManager::getInstance()->closeGame();

    else if (pButton->getName() == "Change Rows Button"){
        ViewManager::getInstance()->incrementRows();
        this->pScreenCountText[0]->setText("Screen Rows: " + std::to_string(ViewManager::getInstance()->getScreenRows()));
    }

    else if (pButton->getName() == "Change Cols Button"){
        ViewManager::getInstance()->incrementCols();
        this->pScreenCountText[1]->setText("Screen Cols: " + std::to_string(ViewManager::getInstance()->getScreenCols()));
    }
}

void MainMenu::onRelease(Button* pButton) {}