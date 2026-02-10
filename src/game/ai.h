#pragma once

#include <stdbool.h>

#include "game/game.h"

void ai_init(pong_game_t *g);
void ai_step(pong_game_t *g, float dt, bool ai_left, bool ai_right);
