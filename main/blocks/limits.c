#include "blocks.h"

float get_start(int p_num)
{
    if (p_num == 0)
        return (2 * BLOCK_SIZE);
    if (p_num == 2)
        return (BLOCK_SIZE / 2);
    if (p_num == 6)
        return (BLOCK_SIZE);
    return (BLOCK_SIZE + (BLOCK_SIZE / 2));
}

float get_end(int p_num)
{
    if (p_num == 0)
        return (2 * BLOCK_SIZE);
    if (p_num == 1)
        return (BLOCK_SIZE / 2);
    if (p_num == 6)
        return (BLOCK_SIZE);
    return (BLOCK_SIZE + (BLOCK_SIZE / 2));
}