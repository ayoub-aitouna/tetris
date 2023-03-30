#ifndef BOARD_H
#define BOARD_H

#include "../../includes/types.h"
#include "../../includes/tetris.h"
char **init_board();
void display_board(char **board, SDL_Renderer *renderer);
char **check_collision(t_list *list, char **board, float x, float y, int *is_collision);
#endif