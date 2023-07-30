#ifndef CONTROLLERS_MUSIC_MANAGER_HPP
#define CONTROLLERS_MUSIC_MANAGER_HPP

#include "../../Model/Enum/EnumMusicType.hpp"

namespace controllers {
    class MusicManager {
        private:
            std::unordered_map<MusicType, sf::Music*> mapMusic;
            std::vector<sf::Music*> vecMusic;

        public:
            void loadAll();
            void unloadAll();
            sf::Music* getMusic(MusicType EType);

        private:
            void create(MusicType EType, std::string strPath);
            void add(MusicType EType, sf::Music* pMusic);

        private:
            static MusicManager* P_SHARED_INSTANCE;

        private:
            MusicManager();
            MusicManager(const MusicManager&);
            MusicManager& operator = (const MusicManager&);

        public:
            static MusicManager* getInstance();
    };
}

#endif