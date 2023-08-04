#ifndef ENUM_SFX_TYPE_HPP
#define ENUM_SFX_TYPE_HPP

enum class SFXType : int {
    PLAYER_BULLET = 0,

    SHOOT,
    RELOAD,

    ITEM_TAKEN,
    ITEM_ACTIVATE,

    HEAL_PLAYER,
    KILL_ALL,

    ENEMY_HIT,
    PLAYER_HIT,

    NO_AMMO,
    V_NO_AMMO
};

#endif

