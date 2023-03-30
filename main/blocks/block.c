#include "../../includes/blocks.h"

t_list *block(float x, float y, SDL_Renderer *renderer)
{
    int i, s_v, l_v, j, s_h, l_h;
    int h_w = BLOCK_SIZE / 2, h_h = BLOCK_SIZE / 2;
    s_v = x - h_w;
    l_v = x + h_w;
    s_h = y - h_h;
    l_h = y + h_h;

    i = s_v;
    j = s_h;

    while (i < l_v - 1)
    {
        j = s_h;
        while (j < l_h - 1)
            SDL_RenderDrawPoint(renderer, i, j++);
        i++;
    }
    return ft_lstnew(get_possition(x, y));
}