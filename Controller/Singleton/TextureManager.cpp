#include "TextureManager.hpp"

using namespace controllers;

void TextureManager::loadAll(SceneTag EScene) {
    this->EScene = EScene;

    this->loadBackgroundFolder();
    this->loadUIFolder();
    this->loadPlayerFolder();
    this->loadEnemyFolder();
    this->loadBlockerFolder();

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
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/test_front.png");
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/test_side.png");
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
            this->loadTexture(AssetType::BULLET, "View/Image/UI/Bullet.png");
            this->loadTexture(AssetType::BULLET_CASE, "View/Image/UI/Bullet_Case.png");

            this->loadTexture(AssetType::HEART, "View/Image/UI/heart.png");
            this->loadTexture(AssetType::HEART_CASE, "View/Image/UI/Heart_Case.png");

            this->loadTexture(AssetType::INVENTORY_1, "View/Image/UI/Inventory_1.png");
            this->loadTexture(AssetType::INVENTORY_2, "View/Image/UI/Inventory_2.png");
            this->loadTexture(AssetType::INVENTORY_3, "View/Image/UI/Inventory_3.png");

            this->loadTexture(AssetType::STATUS_DAMAGE, "View/Image/UI/Damage_Boost.png");
            this->loadTexture(AssetType::STATUS_PIERCE, "View/Image/UI/Piercing_Ammo.png");
            this->loadTexture(AssetType::STATUS_INFINITE, "View/Image/UI/Infinity_Ammo.png");
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

void TextureManager::loadEnemyFolder() {
    switch (this->EScene) {
        case SceneTag::MAIN_MENU:
            break;

        case SceneTag::GAME_PROPER:
            this->loadTexture(AssetType::SLIME, "View/Image/Enemy/Slime.png");
            this->loadTexture(AssetType::BAT, "View/Image/Enemy/Bat.png");
            this->loadTexture(AssetType::GHOST, "View/Image/Enemy/Ghost.png");

            
            this->loadTexture(AssetType::SLIME, "View/Image/Enemy/Slime_Side.png");
            this->loadTexture(AssetType::BAT, "View/Image/Enemy/Bat_Side.png");
            this->loadTexture(AssetType::GHOST, "View/Image/Enemy/Ghost_Side.png");
/* 
            this->loadTexture(AssetType::SLIME_SIDE, "View/Image/Enemy/Slime_Side.png");
            this->loadTexture(AssetType::BAT_SIDE, "View/Image/Enemy/Bat_Side.png");
            this->loadTexture(AssetType::GHOST_SIDE, "View/Image/Enemy/Ghost_Side.png"); */

        default:
            break;
    }
}



void TextureManager::loadBlockerFolder() {
    switch (this->EScene) {
        case SceneTag::MAIN_MENU:
            break;
        case SceneTag::GAME_PROPER:
            this->loadTexture(AssetType::BOULDER_ROUND, "View/Image/Blocker/Boulder_Round.png");
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
