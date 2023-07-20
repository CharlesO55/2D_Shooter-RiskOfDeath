#include "TextureManager.hpp"

using namespace controllers;

void TextureManager::loadAll(SceneTag EScene) {
    this->EScene = EScene;

    this->loadBackgroundFolder();
    this->loadUIFolder();
    this->loadPlayerFolder();
    this->loadMrAlienFolder();
}

void TextureManager::unloadAll(){
    std::cout << "UNLOADING TEXTURE_MANAGER: ";
    //CLEAR THE MAP OF VECTORS
    for (auto [EAsset, vecTex] : this->mapTexture){
        //DELETE THE VECTOR OF TEXTURES
        for (auto tex : vecTex){
            delete tex;
        }
        vecTex.clear();
    }
    this->mapTexture.clear();
    std::cout << "SUCCESS\n";
}


void TextureManager::loadTexture(AssetType ETag, std::string strAddress){
    sf::Texture* pTexture = new sf::Texture();
    if (!pTexture->loadFromFile(strAddress)){
        pTexture->loadFromFile("View/Image/error.png");
    }    
    this->mapTexture[ETag].push_back(pTexture);
}


void TextureManager::loadBackgroundFolder() {
    /* sf::Texture* pTexture = NULL;

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Background/main_menu.png");
    this->mapTexture[AssetType::BACKGROUND].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Background/game_space.png");
    this->mapTexture[AssetType::BACKGROUND].push_back(pTexture); */
    

    switch (this->EScene){
        case SceneTag::MAIN_MENU:
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/test_bg.png");
            break;
        case SceneTag::LEADERBOARD:
            {
                for (int i = 0; i <= 20/*64*/; i++){
                    std::string strNum = std::to_string(i);
                    if(i < 10){
                        strNum.insert(0, 1, '0');
                    }
                    this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/Omedetou/" + strNum + ".png");
                }
            }
            break;
        case SceneTag::GAME_PROPER:
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/test_bg3.png");
            break;
        

        //OBSOLETE
        case SceneTag::GAME_SCENE:
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/game_space.png");
            break;
        default:
            break;
    }
}

void TextureManager::loadUIFolder() {

    switch (this->EScene) {
        case SceneTag::MAIN_MENU:
            this->loadTexture(AssetType::BUTTON_START, "View/Image/UI/button_start.png");
            break;
        case SceneTag::GAME_PROPER:
            //this->loadTexture(AssetType::BULLET_LOGO, "View/Image/UI/bullet_logo.png");
            //this->loadTexture(AssetType::BULLET_TICK, "View/Image/UI/bullet_tick.png");
            this->loadTexture(AssetType::BULLET, "View/Image/UI/Bullet.png");
            this->loadTexture(AssetType::BULLET_CASE, "View/Image/UI/Bullet_Case.png");

            this->loadTexture(AssetType::HEART, "View/Image/UI/heart.png");
            this->loadTexture(AssetType::HEART_CASE, "View/Image/UI/Heart_Case.png");
            break;
        default:
            break;
    }
}

void TextureManager::loadPlayerFolder() {
    switch (this->EScene) {
        case SceneTag::MAIN_MENU:
            break;
        case SceneTag::GAME_PROPER:
            this->loadTexture(AssetType::SHIP, "View/Image/Player/this_ship_be_otp.png");
            //this->loadTexture(AssetType::BULLET, "View/Image/Player/bullet.png");
            this->loadTexture(AssetType::CROSSHAIR, "View/Image/Player/Crosshair.png");
            break;
        default:
            break;
    }
}

void TextureManager::loadMrAlienFolder() {
    switch (this->EScene) {
        case SceneTag::MAIN_MENU:
            break;
        case SceneTag::GAME_SCENE:
            this->loadTexture(AssetType::MR_ALIEN_BASE, "View/Image/Mr. Alien/mr_alien_base.png");
            this->loadTexture(AssetType::MR_ALIEN_TOP_STAMEN, "View/Image/Mr. Alien/mr_alien_top_stamen.png");
            this->loadTexture(AssetType::MR_ALIEN_BOTTOM_STAMEN, "View/Image/Mr. Alien/mr_alien_bottom_stamen.png");
            this->loadTexture(AssetType::MR_ALIEN_TOP_TENTACLE, "View/Image/Mr. Alien/mr_alien_top_tentacle.png");
            this->loadTexture(AssetType::MR_ALIEN_BOTTOM_TENTACLE, "View/Image/Mr. Alien/mr_alien_bottom_tentacle.png");
            break;
        default:
            break;
    }
}

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EType, int nStart, int nEnd) {
    if(nStart == -1)
        return this->mapTexture[EType];

    else {
        std::vector<sf::Texture*> vecTexture = this->mapTexture[EType];
        std::vector<sf::Texture*>::const_iterator iStart = vecTexture.begin() + nStart;

        if(nEnd == -1)
            nEnd = nStart + 1;

        std::vector<sf::Texture*>::const_iterator iEnd = vecTexture.begin() + nEnd + 1;
        std::vector<sf::Texture*> vecSublist = std::vector(iStart, iEnd);

        return vecSublist;
    }
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;
TextureManager::TextureManager() {}
TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new TextureManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */
