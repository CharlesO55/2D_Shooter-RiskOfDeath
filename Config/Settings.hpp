#ifndef CONFIGS_SETTINGS_HPP
#define CONFIGS_SETTINGS_HPP

//DEBUG ASSISTANTS. Comment out to disable effects
#define DISABLE_INTELLISENSE_INCLUDES
#define DISABLE_POOLABLE_WARNINGS
//#define RENDER_HITBOXES
//#define DISABLE_PLAYER_DEATH



//SCREEN PROPERTIES
const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;
const float FRAME_RATE_LIMIT = 60.0f;

//GAME SPEED
const float DEFAULT_GAME_SPEED        = 1.f;    //Starting normal speed
const float DEFAULT_SPEEDUP_TIMEFRAME = 5.f;   //Game speed increases every x seconds

//
const int           DEFAULT_TEXT_SIZE = 24;
const std::string   DEFAULT_PLAYER_NAME = "PLAYER";
const int           MAX_PLAYER_HEALTH = 5;

//SPAWNER DEFAULTS
const float     SPAWN_TIME = 8.f;
const int       DEFAULT_WAVE_AMOUNT = 1;

#endif