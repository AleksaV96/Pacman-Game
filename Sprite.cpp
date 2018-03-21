#include "Sprite.h"

Sprite::Sprite(const string &imagePath, SDL_Renderer *renderer)
{
    SDL_Surface *surface = IMG_Load(imagePath.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    spriteRect.x = 0;
    spriteRect.y = 0;
    spriteRect.w = surface->w;
    spriteRect.h = surface->h;

    SDL_FreeSurface(surface);
}

void Sprite::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, texture, NULL, &spriteRect);
}

void Sprite::move(int dx, int dy)
{
    spriteRect.x += dx;
    spriteRect.y += dy;
}
