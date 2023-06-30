#pragma once

#include "../GameObject.hpp"
#include "../Enum/EnumComponentType.hpp"

namespace models{
    class GameObject;
}

namespace components{
    class Component{
        protected:
            models::GameObject* pOwner;
            EnumComponentType EType;
            std::string strName;

        public:
            Component(std::string strName, EnumComponentType EType, models::GameObject* pOwner);
            virtual ~Component();

        public:
            virtual void perform() = 0;


        public:
            EnumComponentType getType() {return this->EType;};
            std::string getName() {return this->strName;};
            models::GameObject* getOwner();
    };
}