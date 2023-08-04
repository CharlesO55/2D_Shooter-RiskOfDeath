#ifndef COMPONENTS_SCRIPT_BLOCKER_HPP
#define COMPONENTS_SCRIPT_BLOCKER_HPP

#include "../Component.hpp"
#include "../../Enum/EnumBlockerType.hpp"

namespace components{
    class ScriptBlocker : public Component{
        private:
            int nMoveHorizontal;
            int nMoveVertical;

            float fLowerBound;
            float fUpperBound;

            sf::Time CTime;
            float fSpeed;
        public:
            ScriptBlocker(std::string strName, models::GameObject* pOwner, EnumBlockerType EBlockerType);

        public:
            void perform();
            void assignOnUpdate(sf::Time CTime) {this->CTime = CTime;};


    };
}

#endif