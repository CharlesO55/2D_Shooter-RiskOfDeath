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
        pTexture->loadFromFile("View/Image/Background/game_space.png");
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
        case SceneTag::GAME_SCENE:
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/game_space.png");
            break;
        default:
            break;
    }
}

void TextureManager::loadUIFolder() {
    sf::Texture* pTexture = NULL;

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/UI/bullet_logo.png");
    this->mapTexture[AssetType::BULLET_LOGO].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/UI/bullet_tick.png");
    this->mapTexture[AssetType::BULLET_TICK].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/UI/heart.png");
    this->mapTexture[AssetType::HEART].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/UI/button_start.png");
    this->mapTexture[AssetType::BUTTON_START].push_back(pTexture);
    
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/UI/button_start.png");
    this->mapTexture[AssetType::BUTTON_START].push_back(pTexture);
}

void TextureManager::loadPlayerFolder() {
    sf::Texture* pTexture = NULL;

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Player/this_ship_be_otp.png");
    this->mapTexture[AssetType::SHIP].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Player/bullet.png");
    this->mapTexture[AssetType::BULLET].push_back(pTexture);
}

void TextureManager::loadMrAlienFolder() {
    sf::Texture* pTexture = NULL;

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Mr. Alien/mr_alien_base.png");
    this->mapTexture[AssetType::MR_ALIEN_BASE].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Mr. Alien/mr_alien_top_stamen.png");
    this->mapTexture[AssetType::MR_ALIEN_TOP_STAMEN].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Mr. Alien/mr_alien_bottom_stamen.png");
    this->mapTexture[AssetType::MR_ALIEN_BOTTOM_STAMEN].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Mr. Alien/mr_alien_top_tentacle.png");
    this->mapTexture[AssetType::MR_ALIEN_TOP_TENTACLE].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Mr. Alien/mr_alien_bottom_tentacle.png");
    this->mapTexture[AssetType::MR_ALIEN_BOTTOM_TENTACLE].push_back(pTexture);
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
