#include "blocks.h"
/*
 * 255,255,0,255 => yellow
 */
t_list *Line_peice(float x, float y, SDL_Renderer *renderer)
{
    float h_b_z = BLOCK_SIZE / 2;
    float y_pos = y - h_b_z;
    t_list *list = NULL;

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    ft_lstadd_back(&list, block(x - h_b_z, y_pos, renderer));
    ft_lstadd_back(&list, block(x + h_b_z, y_pos, renderer));
    ft_lstadd_back(&list, block(x + BLOCK_SIZE + h_b_z, y_pos, renderer));
    ft_lstadd_back(&list, block(x - BLOCK_SIZE - h_b_z, y_pos, renderer));
    return (list);
}