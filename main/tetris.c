
#include "../includes/tetris.h"

void clear(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void print_list(t_list *list)
{
	possition_t *pos;
	float H_BZ = BLOCK_SIZE / 2;
	printf("\n\n start_list\n");
	while (list)
	{
		pos = (possition_t *)list->content;
		printf("{.x= %f, .y= %f}\n", pos->x + H_BZ, pos->y);
		list = list->next;
	}
	printf("\nend_list\n");
}
float get_start(int p_num)
{
	if (p_num == 0)
		return (2 * BLOCK_SIZE);
	if (p_num == 6)
		return (BLOCK_SIZE);
	return (BLOCK_SIZE + (BLOCK_SIZE / 2));
}
float get_end(int p_num)
{
	if (p_num == 0)
		return (2 * BLOCK_SIZE);
	if (p_num == 2)
		return (BLOCK_SIZE / 2);
	if (p_num == 6)
		return (BLOCK_SIZE);
	return (BLOCK_SIZE + (BLOCK_SIZE / 2));
}
int collision(t_list *list)
{
	possition_t *pos;
	float H_BZ = BLOCK_SIZE / 2;
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

int main(void)
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	t_list *list;
	srand(time(NULL));
	Peice peices[7] = {Line_peice, Revers_L_peice, L_peice, Z_peice, T_peice, Revers_Z_peice, Cube};
	int random_num = 1;
	int x_p = WIDTH / 2;
	float y_p = 0;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("draw_line", SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);

	while (1)
	{
		clear(renderer);
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
		SDL_Delay(1000 / FRAME_RATE);
		y_p = y_p >= HEIGHT ? 0 : y_p + 1;
	}
}
