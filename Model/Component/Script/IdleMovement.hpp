#ifndef COMPONENTS_IDLE_MOVEMENT_HPP
#define COMPONENTS_IDLE_MOVEMENT_HPP

#include "../../Enum/EnumComponentType.hpp"
#include "../Component.hpp"

namespace components {
    class IdleMovement : public Component {
        private:
            float fFrameInterval;
            float fTicks;

            float fSpeed;
            float fLowerBound;
            float fUpperBound;

            bool bIdle;
            bool bUpwards;

        public:
            IdleMovement(std::string strName, float fLowerBound, float fUpperBound, bool bUpwards = true, float fSpeed = 2.0f, float fFrameInterval = 0.2f);

        public:
            void perform();
        
        private:
            float normalize(float fValue);

        public:
            bool isIdle();
            void setIdle(bool bIdle);
    };
}

#endif