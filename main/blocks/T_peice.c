#include "blocks.h"
/*
 * 255,0,0,255 => RED
 */
t_list *T_peice(float x, float y, SDL_Renderer *renderer)
{
    t_list *list = NULL;
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    ft_lstadd_back(&list, block(x, y, renderer));
    ft_lstadd_back(&list, block(x + BLOCK_SIZE, y, renderer));
    ft_lstadd_back(&list, block(x - BLOCK_SIZE, y, renderer));
    ft_lstadd_back(&list, block(x, y + BLOCK_SIZE, renderer));
    return (list);
}