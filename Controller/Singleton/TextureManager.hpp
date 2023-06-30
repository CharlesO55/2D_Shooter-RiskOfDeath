#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../../Model/Enum/EnumTextures.hpp"

namespace singletons{
    class TextureManager{
        private:
            static TextureManager* P_SHARED_INSTANCE;
            std::unordered_map <EnumTextures, sf::Texture*> mapTextures;

        private:
            void loadAll();
            void loadTexture(std::string strAddress, EnumTextures ETag); 

        public:
            sf::Texture* getTexture(EnumTextures ETag);


        //SINGLETON STUFF

        private:
            TextureManager(){this->loadAll();};
            TextureManager(const TextureManager&) = delete;
            TextureManager& operator = (const TextureManager&) = delete;

        public:
            static TextureManager* getInstance();
    };
}