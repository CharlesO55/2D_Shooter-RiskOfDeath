#include <iostream>

#include "Controller/Game.cpp"

#include "Model/GameObject.cpp"
#include "Model/Entity/Monster.cpp"

#include "View/UI/TextButton.cpp"

#include "Model/Component/Component.cpp"
#include "Model/Component/CompRenderer.cpp"
#include "Model/Component/InputBase.cpp"
#include "Model/Component/InputButton.cpp"
#include "Model/Component/ScriptIdle.cpp"
#include "Model/Component/ScriptBlocker.cpp"


#include "Controller/Singleton/TextureManager.cpp"
#include "Controller/Singleton/GameObjectManager.cpp"


int main(){
    std::srand(time(NULL));

    controllers::Game CGame;
    CGame.run();
}