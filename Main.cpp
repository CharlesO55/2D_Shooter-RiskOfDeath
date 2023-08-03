/* * * * * * * [NEW CONTENT] * * * * * * *
    [INSTRUCTIONS]
        Look for the [NEW CONTENT] comments in the
        following classes for the Lecture notes. Make
        sure to check for any [IMPORTANT] tags as
        well.

        Note that for new classes, the comments are
        written in the .cpp file as opposed to the
        .hpp file.

    [PRACTICE EXERCISE]
        This is an INCOMPLETE Template. You are tasked
        to integrate the [MainMenu] [View] to the final
        output by completing or altering the following
        classes :
            [1] [MainMenu]
            [2] [MainMenuScene]
            [3] [Game] 

        [NOTE] : Look for the [PRACTICAL EXERCISE]
        comments in the given classes above.

    [NEW CLASSES]
        [>] Model/Scene.cpp + .hpp
        [>] Controller/System/SceneManager.cpp + .hpp
        [>] Model/Enum/EnumSceneTag.hpp
        [>] Model/Scene/MainMenuScene.cpp + .hpp
        [>] Model/Scene/GameScene.cpp + .hpp
        [>] View/Screen/MainMenu.cpp + .hpp

    [ALTERED CLASSES]
        [>] Controller/Singleton/GameObjectManager.cpp + .hpp
        [>] Controller/Game.cpp + .hpp
 * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Controller/Game.cpp"

#include "Controller/Singleton/GameObjectManager.cpp"
#include "Controller/Singleton/GameStateManager.cpp"
#include "Controller/Singleton/MusicManager.cpp"
#include "Controller/Singleton/SFXManager.cpp"
#include "Controller/Singleton/TextureManager.cpp"
#include "Controller/Singleton/FontManager.cpp"

#include "Controller/System/BlockerManager.cpp"
#include "Controller/System/EnemyManager.cpp"
#include "Controller/System/ItemManager.cpp"
#include "Controller/System/ObjectPoolManager.cpp"
#include "Controller/System/PhysicsManager.cpp"
#include "Controller/System/SceneManager.cpp"
#include "Controller/System/ScoreManager.cpp"
#include "Controller/System/ViewManager.cpp"
#include "Controller/Pooling/GameObjectPool.cpp"

#include "Model/AnimatedTexture.cpp"
#include "Model/EmptyGameObject.cpp"
#include "Model/GameObject.cpp"
#include "Model/Scene.cpp"
#include "Model/Hitbox.cpp"

#include "Model/Entity/Background.cpp"
#include "Model/Entity/Ship.cpp"
#include "Model/Entity/Mr. Alien/MrAlien.cpp"
#include "Model/Entity/Mr. Alien/Part/BottomStamen.cpp"
#include "Model/Entity/Mr. Alien/Part/BottomTentacle.cpp"
#include "Model/Entity/Mr. Alien/Part/TopStamen.cpp"
#include "Model/Entity/Mr. Alien/Part/TopTentacle.cpp"
#include "Model/Entity/Border/Border.cpp"
#include "Model/Entity/Crosshair.cpp"

#include "Model/Entity/Blocker/BaseBlocker.cpp"
#include "Model/Entity/Blocker/BoulderBlocker.cpp"
#include "Model/Entity/Blocker/WispBlocker.cpp"
#include "Model/Entity/Blocker/ScrollBlocker.cpp"
#include "Model/Entity/Blocker/PlaneBlocker.cpp"
#include "Model/Entity/Blocker/CloudBlocker.cpp"


#include "Model/Scene/MainMenuScene.cpp"
#include "Model/Scene/GameScene.cpp"
#include "Model/Scene/GameProper.cpp"
#include "Model/Scene/LeaderboardScene.cpp"

#include "Model/Pooling/PoolableObject.cpp"
#include "Model/Pooling/Bullet/PlayerBullet.cpp"

#include "Model/Pooling/Enemy/BaseEnemy.cpp"
#include "Model/Pooling/Enemy/EnemySlime.cpp"
#include "Model/Pooling/Enemy/EnemyBat.cpp"
#include "Model/Pooling/Enemy/EnemyGhost.cpp"

#include "Model/Pooling/Items/BaseItem.cpp"
#include "Model/Pooling/Items/DamageBoost.cpp"
#include "Model/Pooling/Items/HealthBoost.cpp"
#include "Model/Pooling/Items/PiercingShot.cpp"
#include "Model/Pooling/Items/InfinityAmmo.cpp"
#include "Model/Pooling/Items/InstantKill.cpp"

#include "Model/Component/Component.cpp"

#include "Model/Component/Input/ButtonInput.cpp"
#include "Model/Component/Input/CrosshairMouseInput.cpp"
#include "Model/Component/Input/CrosshairMovement.cpp"
#include "Model/Component/Input/GeneralInput.cpp"
#include "Model/Component/Input/PlayerInput.cpp"
#include "Model/Component/Input/ShipInput.cpp"
#include "Model/Component/Input/GameNavigationInput.cpp"

#include "Model/Component/Script/Blinker.cpp"
#include "Model/Component/Script/IdleMovement.cpp"
#include "Model/Component/Script/MoveForward.cpp"
#include "Model/Component/Script/MoveScroll.cpp"
#include "Model/Component/Script/MoveXY.cpp"
#include "Model/Component/Script/Killable.cpp"
#include "Model/Component/Script/Obtainable.cpp"
#include "Model/Component/Script/PlayerBulletMovement.cpp"
#include "Model/Component/Script/ShipControls.cpp"
#include "Model/Component/Script/ScriptBlocker.cpp"
#include "Model/Component/Script/GameScreenNavigation.cpp"

#include "Model/Component/Renderer/Renderer.cpp"
#include "Model/Component/Renderer/RendererSpawnable.cpp"
#include "Model/Component/Renderer/Animator.cpp"
#include "Model/Component/Renderer/ScenePosInterpreter.cpp"
#include "Model/Component/Physics/Collider.cpp"

#include "View/Button.cpp"
#include "View/Image.cpp"
#include "View/Text.cpp"
#include "View/View.cpp"
#include "View/Screen/MainMenu.cpp"
#include "View/Screen/MenuBar.cpp"
#include "View/Screen/Leaderboard.cpp"
#include "View/Screen/PlayerUI.cpp"
#include "View/Screen/FrontViewScreen.cpp"
#include "View/Screen/SideViewScreen.cpp"

using namespace controllers;

int main() {
    Game CGame;
    CGame.run();

    return 0;
}
