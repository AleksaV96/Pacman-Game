#ifndef BARRIER_H_INCLUDED
#define BARRIER_H_INCLUDED

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Barrier {
    public:
        Barrier(SDL_Renderer *renderer, int bx, int by, int bw, int bh);
        SDL_Rect spriteRect;
};

#endif // BARRIER_H_INCLUDED
