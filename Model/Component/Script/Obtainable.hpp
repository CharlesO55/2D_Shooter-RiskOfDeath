#ifndef COMPONENTS_OBTAINABLE_HPP
#define COMPONENTS_OBTAINABLE_HPP

#include "../../../Controller/Singleton/TextureManager.hpp"

#include "../../Enum/EnumAssetType.hpp"
#include "../../Enum/EnumComponentType.hpp"
#include "../../Pooling/PoolableObject.hpp"

#include "../Component.hpp"

namespace components {
    using namespace controllers;
    using namespace models;

    class Obtainable : public Component {
        private:
            float fTicks;
            bool bObtained;

        public:
            Obtainable(std::string strName);

        public:
            void perform();
            void activate(PoolTag ETag);

        public:
            bool isObtained();
            void setObtained(bool bObtained);
    };
}

#endif