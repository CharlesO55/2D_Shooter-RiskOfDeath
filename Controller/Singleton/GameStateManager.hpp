#ifndef CONTROLLERS_GAME_STATE_MANAGER_HPP
#define CONTROLLERS_GAME_STATE_MANAGER_HPP

#include "../../Config/Settings.hpp"

#include "../../Model/Enum/EnumGameState.hpp"
#include "../../View/View.hpp"

namespace controllers {
    using namespace models;
    using namespace views;
    
    class GameStateManager {
        private:
            GameState EState = GameState::RUNNING;
            float fGameSpeed = DEFAULT_GAME_SPEED;

        public:
            void pause();
            void resume();
            void closeGame();

            void reset();
            
            bool isPaused();
            bool isGameClose();

            float getGameSpeed();
            void setGameSpeed(float fSpeed);

        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static GameStateManager* P_SHARED_INSTANCE;

        private:
            GameStateManager();
            GameStateManager(const GameStateManager&);
            GameStateManager& operator = (const GameStateManager&);

        public:
            static GameStateManager* getInstance();
        /* * * * * * * * * * * * * * * * * * * * */
    };
}

#endif