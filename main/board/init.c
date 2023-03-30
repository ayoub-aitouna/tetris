#include "board.h"

char **init_board()
{
    int h_blocks = (HEIGHT / BLOCK_SIZE);
    int w_blocks = (WIDTH / BLOCK_SIZE);

    char **board = malloc(sizeof(char *) * (h_blocks + 1));
    int i = 0;
    int j = 0;
    char *line;

    while (i <= h_blocks)
    {
        j = 0;
        line = malloc((w_blocks + 1) * sizeof(char));
        while (j <= w_blocks + 1)
            line[j++] = '0';
        line[j] = 0;
        board[i++] = line;
    }
    board[i] = NULL;
    return (board);
}

void display_board(char **board, SDL_Renderer *renderer)
{
    int i = 0;
    int j = 0;
    int H_BZ = BLOCK_SIZE / 2;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    while (board[i])
    {
        j = 0;
        while (board[i][j])
        {
            // printf("%c", board[i][j]);
            if (board[i][j] == '1')
                block((j * BLOCK_SIZE) - H_BZ, (i * BLOCK_SIZE) - H_BZ, renderer);
            j++;
        }
        // printf("\n");
        i++;
    }
    // printf(";\n\n");
}

char **add_shape(char **board, t_list *list)
{
    possition_t *pos;
    float H_BZ;
    int i;
    int j;
    t_list *tmp;

    tmp = list;

    H_BZ = BLOCK_SIZE / 2;
    while (list)
    {
        pos = (possition_t *)list->content;

        i = (int)((pos->y + H_BZ) / BLOCK_SIZE);
        j = (int)((pos->x + H_BZ) / BLOCK_SIZE);
        board[i][j] = '1';
        list = list->next;
    }
    return (board);
}

int check_pos_in_board(char **board, float x, float y)
{
    float H_BZ;

    H_BZ = BLOCK_SIZE / 2;

    int i = (int)((y + H_BZ) / BLOCK_SIZE) + 1;
    int j = (int)((x + H_BZ) / BLOCK_SIZE);
    if (i > (HEIGHT / BLOCK_SIZE))
        i = (HEIGHT / BLOCK_SIZE);
    printf("{.x %d , .y = %d} => <%c>\n", i, j, board[i][j]);
    if (board[i][j] == '1')
    {

        return (1);
    }
    return (0);
}
char **check_collision(t_list *list, char **board, float x, float y, int *is_collision)
{
    possition_t *pos;
    float H_BZ;

    H_BZ = BLOCK_SIZE / 2;
    t_list *tmp = list;
    while (list)
    {
        pos = (possition_t *)list->content;
        if (check_pos_in_board(board, pos->x, pos->y) || pos->y == HEIGHT - H_BZ)
        {
            *is_collision = 1;
            return (add_shape(board, tmp));
        }
        list = list->next;
    }
    printf("\n\n");
    return (board);
}