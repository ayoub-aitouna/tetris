#include "blocks.h"

possition_t *get_possition(float x, float y)
{
    possition_t *pos = malloc(sizeof(possition_t));
    pos->x = x;
    pos->y = y;
    return (pos);
}
