#ifndef CONFIGS_SETTINGS_HPP
#define CONFIGS_SETTINGS_HPP

//CODING/DEBUG ASSISTANT
#define DISABLE_INTELLISENSE_INCLUDES
#define DISABLE_POOLABLE_WARNINGS

//SCREEN PROPERTIES
const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;
const float FRAME_RATE_LIMIT = 60.0f;

//GAME SPEED
const float DEFAULT_GAME_SPEED = 1.f;

const int           DEFAULT_TEXT_SIZE = 24;
const std::string   DEFAULT_PLAYER_NAME = "PLAYER";

const bool          RENDER_HITBOXES = true;

bool bCloseGame = false;


//SPAWNER DEFAULTS
const float     SPAWN_TIME = 5.f;
const int       DEFAULT_WAVE_AMOUNT = 1;

#endif