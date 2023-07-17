#ifndef MODELS_MR_ALIEN_HPP
#define MODELS_MR_ALIEN_HPP

#include "../../GameObject.hpp"
#include "../../Component/Component.hpp"
#include "../../Component/Physics/Collider.hpp"
#include "../../Component/Physics/Interface/CollisionListener.hpp"
#include "../../Component/Script/Blinker.hpp"
#include "../../Component/Script/Interface/Blinkable.hpp"

#include "../../../Controller/Singleton/SFXManager.hpp"
#include "../../../Controller/System/PhysicsManager.hpp"

#include "../../../Controller/System/ViewManager.hpp"
#include "../../../View/Screen/MenuBar.hpp"

namespace models {
    using namespace components;
    using namespace systems;
    using namespace views;
    
    class MrAlien : public GameObject, public CollisionListener, public Blinkable {
        private:
            Blinker* pBlinker;
            sf::Color CNormalColor;
            sf::Color CBlinkColor;

        public:
            MrAlien(std::string strName, AnimatedTexture* pTexture);
            ~MrAlien();

        public:
            void initialize();
            void blink();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);
    };
}

#endif