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
    
    BULLET_LOGO,
    BULLET_TICK,
    HEART,

    SHIP,
    BULLET,
    
    MR_ALIEN_BASE,
    MR_ALIEN_TOP_STAMEN,
    MR_ALIEN_BOTTOM_STAMEN,
    MR_ALIEN_TOP_TENTACLE,
    MR_ALIEN_BOTTOM_TENTACLE
};

#endif

