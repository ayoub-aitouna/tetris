#ifndef TYPES_H
#define TYPES_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "../third-parthy/lib.h"
#define FRAME_RATE 60
#define WIDTH 250
#define HEIGHT 480
#define BLOCK_SIZE 20
typedef t_list *(*Peice)(float, float, SDL_Renderer*);
typedef struct position{
    float x;
    float y;
} possition_t;
#endif