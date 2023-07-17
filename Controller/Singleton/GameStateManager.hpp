#ifndef CONTROLLERS_GAME_STATE_MANAGER_HPP
#define CONTROLLERS_GAME_STATE_MANAGER_HPP

#include "../../Model/Enum/EnumGameState.hpp"
#include "../../View/View.hpp"

namespace controllers {
    using namespace models;
    using namespace views;
    
    class GameStateManager {
        private:
            GameState EState;

        public:
            void pause();
            void resume();
            bool isPaused();

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