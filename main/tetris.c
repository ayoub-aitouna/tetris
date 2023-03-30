
#include "../includes/tetris.h"

void clear(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void print_list(t_list *list)
{
	possition_t *pos;
	float H_BZ;

	H_BZ = BLOCK_SIZE / 2;
	printf("\n\n start_list\n");
	while (list)
	{
		pos = (possition_t *)list->content;
		printf("{.x= %f, .y= %f}\n", pos->x + H_BZ, pos->y);
		list = list->next;
	}
	printf("\nend_list\n");
}

int collision(t_list *list)
{
	possition_t *pos;
	float H_BZ;

	H_BZ = BLOCK_SIZE / 2;
	while (list)
	{
		pos = (possition_t *)list->content;
		if (pos->x - BLOCK_SIZE <= 0)
			return (1);
		if (pos->x + H_BZ >= WIDTH)
			return (2);
		list = list->next;
	}
	return (0);
}

int main(int ac, char **av)
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	t_list *list;
	int random_num;
	int x_p;
	float y_p;
	char **board = init_board();
	Peice peices[7] = {Line_peice, Revers_L_peice, L_peice, Z_peice, T_peice,
					   Revers_Z_peice, Cube};
	random_num = ac == 2 ? atoi(av[1]) : 0;
	x_p = BLOCK_SIZE * 6;
	y_p = 200;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("TETRIS", SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	int is_collision = 0;
	while (1)
	{
		is_collision = 0;
		clear(renderer);
		display_board(board, renderer);
		list = peices[random_num](x_p, y_p, renderer);
		SDL_RenderPresent(renderer);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				exit(0);
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					x_p = collision(peices[random_num](x_p - BLOCK_SIZE, y_p, renderer)) != 1
							  ? x_p - BLOCK_SIZE
							  : get_start(random_num);
				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					x_p = collision(peices[random_num](x_p + BLOCK_SIZE, y_p, renderer)) != 2
							  ? x_p + BLOCK_SIZE
							  : WIDTH - get_end(random_num);
			}
		}
		board = check_collision(list, board, x_p, y_p, &is_collision);
		if (is_collision)
		{
			y_p = 0;
			random_num = random_num < 6 ? random_num + 1 : 0;
		}
		else
			y_p = y_p >= HEIGHT ? 0 : y_p + 1;
		SDL_Delay(1000 / FRAME_RATE);
	}
}
