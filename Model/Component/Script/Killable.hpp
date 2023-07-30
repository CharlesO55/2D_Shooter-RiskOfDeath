#ifndef COMPONENTS_KILLABLE_HPP
#define COMPONENTS_KILLABLE_HPP

#include "../../../Controller/Singleton/TextureManager.hpp"

#include "../../Enum/EnumAssetType.hpp"
#include "../../Enum/EnumComponentType.hpp"
#include "../../Pooling/PoolableObject.hpp"
#include "../../AnimatedTexture.hpp"

#include "../Component.hpp"

namespace models {
    class PlayerBullet;
}

namespace components {
    using namespace controllers;
    using namespace models;

    class Killable : public Component {
        private:
            float fFrameInterval;
            float fTicks;
            bool bKilled;

        public:
            Killable(std::string strName, float fFrameInterval);

        public:
            void perform();
            void damage();

        public:
            bool isKilled();
            void setKilled(bool bKilled);

            int getCurrentHealth();
    };
}

#endif