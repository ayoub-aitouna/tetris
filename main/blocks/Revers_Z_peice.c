#include "../../includes/blocks.h"
/*
 * 255,0,0,255 => RED
 */
t_list *Revers_Z_peice(float x, float y, SDL_Renderer *renderer)
{
    t_list *list = NULL;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    block(x, y, renderer);
    block(x + BLOCK_SIZE, y, renderer);
    block(x, y + BLOCK_SIZE, renderer);
    block(x - BLOCK_SIZE, y + BLOCK_SIZE, renderer);
    return (list);
}