#ifndef MODELS_BASE_ITEM_HPP
#define MODELS_BASE_ITEM_HPP

#include "../../AnimatedTexture.hpp"
#include "../../GameObject.hpp"

#include "../../Component/Renderer/Renderer.hpp"
#include "../../Component/Renderer/RendererSpawnable.hpp"
#include "../../Component/Renderer/ScenePosInterpreter.hpp"
#include "../../Component/Script/Obtainable.hpp"
#include "../../Component/Script/MoveForward.hpp"

#include "../PoolableObject.hpp"

#include "../../../View/Text.hpp"

#include "../../../Controller/System/ObjectPoolManager.hpp"
#include "../../../Controller/System/ItemManager.hpp"

#include "../../Component/Script/Interface/Shootable.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace models {
    using namespace components;
    using namespace systems;

    class BaseItem : public PoolableObject , public Shootable {
        protected:
            Obtainable* pObtainable_Ref;

        public:
            BaseItem(std::string strName, AnimatedTexture* pTexture, PoolTag ETag, float fScale);

        public:
            virtual void initialize();
            void onActivate();

            void onRelease();
            virtual PoolableObject* clone() = 0;

        //INTERFACE
            virtual void onShot(int nKnockbackPower = 5);
            bool isVecInHitbox(sf::Vector2f vecLoc);

        protected:
            void randomizePosition();
    };
}

#endif