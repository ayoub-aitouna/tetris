#include "../../includes/blocks.h"
/*
 * 255,255,0,255 => yellow
 */
t_list *Cube(float x, float y, SDL_Renderer *renderer)
{
    t_list *list = NULL;
    float h_b_z = BLOCK_SIZE / 2;
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    ft_lstadd_back(&list, block(x - h_b_z, y - h_b_z, renderer));
    ft_lstadd_back(&list, block(x + h_b_z, y - h_b_z, renderer));
    ft_lstadd_back(&list, block(x + h_b_z, y + h_b_z, renderer));
    ft_lstadd_back(&list, block(x - h_b_z, y + h_b_z, renderer));
    return (list);
}