#ifndef MODELS_SHIP_HPP
#define MODELS_SHIP_HPP

#include "../GameObject.hpp"
#include "../Component/Component.hpp"
#include "../Component/Input/ShipInput.hpp"
#include "../Component/Script/ShipControls.hpp"
#include "../Component/Script/Blinker.hpp"
#include "../Component/Physics/Collider.hpp"

#include "../Component/Script/Interface/Blinkable.hpp"
#include "../Component/Physics/Interface/CollisionListener.hpp"

#include "../../Controller/System/PhysicsManager.hpp"
#include "../../Controller/System/ViewManager.hpp"
#include "../../View/Screen/MenuBar.hpp"

namespace models {
    using namespace components;
    using namespace systems;
    
    class Ship : public GameObject, public CollisionListener, public Blinkable {
        private:
            Blinker* pBlinker;
            sf::Color CNormalColor;
            sf::Color CBlinkColor;
            bool bTopBounds;
            bool bLeftBounds;
            bool bBottomBounds;
            bool bRightBounds;

        public:
            Ship(std::string strName, AnimatedTexture* pTexture);
            ~Ship();

        public:
            void initialize();
            void blink();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

        public:
            bool isTopBounds();
            bool isLeftBounds();
            bool isBottomBounds();
            bool isRightBounds();
    };
}

#endif