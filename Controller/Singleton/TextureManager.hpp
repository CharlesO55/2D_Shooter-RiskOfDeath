#ifndef CONTROLLERS_TEXTURE_MANAGER_HPP
#define CONTROLLERS_TEXTURE_MANAGER_HPP

#include "../../Model/Enum/EnumAssetType.hpp"

#include <unordered_map>
#include <SFML/Graphics.hpp>

namespace controllers {
    class TextureManager {
        private:
            SceneTag EScene = SceneTag::MAIN_MENU;
            std::unordered_map<AssetType, std::vector<sf::Texture*>> mapTexture;

        public:
            void loadAll(SceneTag EScene);
            void unloadAll();
            std::vector<sf::Texture*> getTexture(AssetType EType, int nStart = -1, int nEnd = -1);

        private:
            void loadTexture(AssetType ETag, std::string strAddress);
            void loadBackgroundFolder();
            void loadUIFolder();
            void loadPlayerFolder();
            void loadMrAlienFolder();

        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static TextureManager* P_SHARED_INSTANCE;

        private:
            TextureManager();
            TextureManager(const TextureManager&);
            TextureManager& operator = (const TextureManager&);

        public:
            static TextureManager* getInstance();
        /* * * * * * * * * * * * * * * * * * * * */
    };
}

#endif