#ifndef ENUM_ASSET_TYPE_HPP
#define ENUM_ASSET_TYPE_HPP

enum class AssetType : int {
    NONE = -1,

    TEST_BG,
    TEST_S,
    TEST_M,
    TEST_L,

    BACKGROUND,
    BUTTON_START,
    LOADING_SCREEN_BG,
    
    BULLET,
    HEART,

    INVENTORY_1,
    INVENTORY_2,
    INVENTORY_3,

    HEALTH_BOOST,
    DAMAGE_BOOST,
    PIERCING_AMMO,
    INFINITY_AMMO,
    INSTANT_KILL,

    CROSSHAIR,

    SLIME,
    BAT,
    GHOST,

    BOULDER_ROUND,
    CAGE_BODY,
    CAGE_CHAIN,
    CHEST,
    WISP,
    PLANE,
    CLOUD,
};

#endif

