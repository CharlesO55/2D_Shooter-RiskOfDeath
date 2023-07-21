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
    
    BULLET,
    BULLET_CASE,
    HEART,
    HEART_CASE,

    SHIP,
    CROSSHAIR,
    //BULLET,

    //The slimes are simply a placeholder. Replace sprites when possible
    SLIME_1,
    SLIME_2,
    SLIME_3,
    
    MR_ALIEN_BASE,
    MR_ALIEN_TOP_STAMEN,
    MR_ALIEN_BOTTOM_STAMEN,
    MR_ALIEN_TOP_TENTACLE,
    MR_ALIEN_BOTTOM_TENTACLE
};

#endif

