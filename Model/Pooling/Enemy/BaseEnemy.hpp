#ifndef MODELS_BASE_ENEMY_HPP
#define MODELS_BASE_ENEMY_HPP

#include "../../AnimatedTexture.hpp"
#include "../../GameObject.hpp"

#include "../../Component/Renderer/Renderer.hpp"
#include "../../Component/Renderer/RendererSpawnable.hpp"
#include "../../Component/Renderer/ScenePosInterpreter.hpp"
#include "../../Component/Script/Killable.hpp"
#include "../../Component/Script/MoveForward.hpp"

#include "../PoolableObject.hpp"

#include "../../../View/Text.hpp"

#include "../../../Controller/System/ObjectPoolManager.hpp"
#include "../../../Controller/System/PhysicsManager.hpp"
#include "../../../Controller/System/EnemyManager.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace models {
    using namespace components;
    using namespace systems;

    class BaseEnemy : public PoolableObject {
        protected:
            int nHealth;
            float fSpeed;
            float fKillableSpeed;
            
            float fDefaultScale;        //DEFAULT SCALE IS BASED ON THE NORMAL SIZE AS SEEN FROM SIDE VIEW
            sf::Vector3f vecScenePos;   //TRUE POSITION IN THE GAME WORLD. vecPos will be display pos dependent on Screen/Renderer
            //z = 0 is at player; z = 100 is away from player

        public:
            BaseEnemy(std::string strName, AnimatedTexture* pTexture, PoolTag ETag, int nHealth = 1, float fScale = 1.f, float fSpeed = 1.f, float fKillableSpeed = 0.1f);

        public:
            virtual void initialize();
            void onActivate();
            void onRelease();
            virtual PoolableObject* clone() = 0;

        protected:
            void randomizePosition();

        public:
            float getSpeed();
            int getHealth();
            void setHealth(int nHealth);

            float getDefaultScale();
            sf::Vector3f getScenePos();
            void setZPos(float fZ);
    };
}

#endif