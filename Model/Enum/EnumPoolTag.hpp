#ifndef ENUM_POOL_TAG_HPP
#define ENUM_POOL_TAG_HPP

enum class PoolTag : int {
    NONE = -1,
    PLAYER_BULLET,

    //Temporary, can replace sprites at any time
    SLIME,
    BAT,
    GHOST,

    HEALTH_BOOST,
    DAMAGE_BOOST,
    PIERCING_SHOT,
    INFINITY_AMMO,
    INSTANT_KILL
};

#endif

