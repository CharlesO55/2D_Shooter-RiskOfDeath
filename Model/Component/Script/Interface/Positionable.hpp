#pragma once

namespace interfaces {
    class Positionable {
        protected:        
            float fDefaultScale = 1;        //DEFAULT SCALE IS BASED ON THE NORMAL SIZE AS SEEN FROM SIDE VIEW
            sf::Vector3f vecScenePos;   //TRUE POSITION IN THE GAME WORLD. vecPos will be display pos dependent on Screen/Renderer
            //z = 0 is at player; z = 100 is away from player

        public:
            ~Positionable() {}

        public:
            float getDefaultScale()     {return this->fDefaultScale;};
            sf::Vector3f getScenePos()  {return this->vecScenePos;};
            void setZPos(float fZ)      {this->vecScenePos.z = fZ;};
            void setScenePos(sf::Vector3f vec3)      {this->vecScenePos = vec3;};
    };
}