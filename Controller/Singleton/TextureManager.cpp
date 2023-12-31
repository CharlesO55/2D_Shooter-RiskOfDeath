#include "TextureManager.hpp"

using namespace controllers;

void TextureManager::loadAll(SceneTag EScene) {
    this->EScene = EScene;

    this->loadBackgroundFolder();
    this->loadUIFolder();
    this->loadPlayerFolder();
    this->loadEnemyFolder();
    this->loadBlockerFolder();
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
    if (!pTexture->loadFromFile(strAddress))
        pTexture->loadFromFile("View/Image/error.png");  

    this->mapTexture[ETag].push_back(pTexture);
}


void TextureManager::loadBackgroundFolder() {
 switch (this->EScene){
        case SceneTag::LOADING:
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/LoadingScreen.png");
            break;

        case SceneTag::MAIN_MENU:
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/ENTRANCE.png");
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
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/FRONT_VIEW.png");
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/SIDE_VIEW.png");
            this->loadTexture(AssetType::BACKGROUND, "View/Image/Background/PAUSE_VIEW.png");
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
            this->loadTexture(AssetType::BULLET, "View/Image/UI/Bullet_Case.png");

            this->loadTexture(AssetType::HEART, "View/Image/UI/heart.png");
            this->loadTexture(AssetType::HEART, "View/Image/UI/Heart_Case.png");

            this->loadTexture(AssetType::INVENTORY_1, "View/Image/UI/Inventory_1.png");
            this->loadTexture(AssetType::INVENTORY_1, "View/Image/UI/Inventory_1_Damage.png");
            this->loadTexture(AssetType::INVENTORY_1, "View/Image/UI/Inventory_1_Piercing.png");
            this->loadTexture(AssetType::INVENTORY_1, "View/Image/UI/Inventory_1_Infinity.png");

            this->loadTexture(AssetType::INVENTORY_2, "View/Image/UI/Inventory_2.png");
            this->loadTexture(AssetType::INVENTORY_2, "View/Image/UI/Inventory_2_Damage.png");
            this->loadTexture(AssetType::INVENTORY_2, "View/Image/UI/Inventory_2_Piercing.png");
            this->loadTexture(AssetType::INVENTORY_2, "View/Image/UI/Inventory_2_Infinity.png");

            this->loadTexture(AssetType::INVENTORY_3, "View/Image/UI/Inventory_3.png");
            this->loadTexture(AssetType::INVENTORY_3, "View/Image/UI/Inventory_3_Damage.png");
            this->loadTexture(AssetType::INVENTORY_3, "View/Image/UI/Inventory_3_Piercing.png");
            this->loadTexture(AssetType::INVENTORY_3, "View/Image/UI/Inventory_3_Infinity.png");

            this->loadTexture(AssetType::DAMAGE_BOOST, "View/Image/UI/Damage_Boost.png");
            this->loadTexture(AssetType::PIERCING_AMMO, "View/Image/UI/Piercing_Ammo.png");
            this->loadTexture(AssetType::INFINITY_AMMO, "View/Image/UI/Infinity_Ammo.png");
            this->loadTexture(AssetType::HEALTH_BOOST, "View/Image/UI/Health_Boost.png");
            this->loadTexture(AssetType::INSTANT_KILL, "View/Image/UI/Instant_Kill.png");
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
            this->loadTexture(AssetType::SLIME, "View/Image/Enemy/Slime_Side.png");

            this->loadTexture(AssetType::BAT, "View/Image/Enemy/Bat.png");
            this->loadTexture(AssetType::BAT, "View/Image/Enemy/Bat_Side.png");

            this->loadTexture(AssetType::GHOST, "View/Image/Enemy/Ghost.png");
            this->loadTexture(AssetType::GHOST, "View/Image/Enemy/Ghost_Side.png");

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
            this->loadTexture(AssetType::CAGE_BODY, "View/Image/Blocker/Cage_body.png");
            this->loadTexture(AssetType::CAGE_CHAIN, "View/Image/Blocker/Cage_chain.png");
            this->loadTexture(AssetType::CHEST, "View/Image/Blocker/Shadow.png");
            this->loadTexture(AssetType::WISP, "View/Image/Blocker/Wisp.png");
            this->loadTexture(AssetType::PLANE, "View/Image/Blocker/Plane.png");
            this->loadTexture(AssetType::CLOUD, "View/Image/Blocker/Cloud.png");
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
