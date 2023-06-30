#include "TextureManager.hpp"

using namespace singletons;

TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;

TextureManager* TextureManager::getInstance(){
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new TextureManager;

    return P_SHARED_INSTANCE;
}


void TextureManager::loadTexture(std::string strAddress, EnumTextures ETag){
    sf::Texture* pTexture = new sf::Texture;
    if(!pTexture->loadFromFile(strAddress)){
        std::cout << "[TEXTURE ERROR] " << strAddress;
        this->mapTextures[ETag] = this->mapTextures[EnumTextures::DEFAULT];
        return;
    }
    this->mapTextures[ETag] = pTexture;
}


sf::Texture* TextureManager::getTexture(EnumTextures ETag){
    sf::Texture* pTexture = this->mapTextures[ETag];
    return pTexture;
}

void TextureManager::loadAll(){
    //BASE TEXTURE IN CASE OF ERROR
    this->loadTexture("Library/Images/test_default.png", EnumTextures::DEFAULT);

    //OTHER TEXTURES
    this->loadTexture("Library/Images/test_sprite.png", EnumTextures::TEST1);
    this->loadTexture("Library/Images/test2.png", EnumTextures::TEST2);
    this->loadTexture("Library/Images/test3.jpg", EnumTextures::TEST3);
    this->loadTexture("Library/Images/test_mon.png", EnumTextures::TEST_MONSTER);
}