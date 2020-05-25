#ifndef _FUNCS_H_
#define _FUNCS_H_

#include "game_state.h"

void game_start(GameState &gameState);
void main_game_loop(GameState &gameState);
void process_location_events(GameState &gameState);
void gaul_loc_events(GameState &gameState);
void move_loc(GameState &gameState);
void iberia_loc_events(GameState &gameState);
void briain_loc_events(GameState &gameState);
void danube_loc_events(GameState &gameState);
void italy_loc_events(GameState &gameState);
void game_end(GameState &gameState);
void scene_break(int length);

#endif