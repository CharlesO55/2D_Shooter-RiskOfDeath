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
    this->createButton(this, 
        this->strName + " Start Button", 
        AssetType::BUTTON_START, 
        {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}
    );

    this->pText = new views::Text(
        "Title",
        "Risk of Death",
        {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2.8},
        FontType::DEFAULT,
        DEFAULT_TEXT_SIZE * 3
    );
    this->pText->centerTextOrigin();
    this->attachChild(pText);
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
    if (pButton->getName().find("Start Button") != std::string::npos){
        systems::SceneManager::getInstance()->loadScene(SceneTag::GAME_SCENE);
    }
}

void MainMenu::onRelease(Button* pButton) {}
/* * * * * * * * * * * * * * * * * * * * */
