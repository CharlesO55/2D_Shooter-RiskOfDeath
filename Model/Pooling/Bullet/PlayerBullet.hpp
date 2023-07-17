#ifndef MODELS_PLAYER_BULLET_HPP
#define MODELS_PLAYER_BULLET_HPP

#include "../../Enum/EnumPoolTag.hpp"
#include "../../Enum/EnumSFXType.hpp"
#include "../../AnimatedTexture.hpp"
#include "../../GameObject.hpp"

#include "../../Component/Script/PlayerBulletMovement.hpp"
#include "../../Component/Renderer/Renderer.hpp"
#include "../../Component/Physics/Collider.hpp"
#include "../../Component/Physics/Interface/CollisionListener.hpp"

#include "../PoolableObject.hpp"

#include "../../../Controller/Singleton/SFXManager.hpp"
#include "../../../Controller/System/ObjectPoolManager.hpp"
#include "../../../Controller/System/PhysicsManager.hpp"

namespace models {
    class Ship;
}

namespace models {
    using namespace components;
    using namespace listeners;
    using namespace systems;
    
    class PlayerBullet : public PoolableObject, public CollisionListener {
        private:
            Ship* pShip;
            Collider* pCollider;
            float fSpeed;

        public:
            PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip);
            
        public:
            void initialize();
            void onActivate();
            void onRelease(); 

            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

            PoolableObject* clone();
    };
}

#endif