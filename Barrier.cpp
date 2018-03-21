#include "Barrier.h"

Barrier::Barrier(SDL_Renderer *renderer, int bx, int by, int bw, int bh)
{
    spriteRect.x = bx;
    spriteRect.y = by;
    spriteRect.w = bw;
    spriteRect.h = bh;
}

