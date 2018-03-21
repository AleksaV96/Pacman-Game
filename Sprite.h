#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Sprite{
    public:
        Sprite(const string &path, SDL_Renderer* renderer);
        virtual void move(int dx, int dy);
        virtual void draw(SDL_Renderer *renderer);
        SDL_Rect spriteRect;

    protected:
        SDL_Texture *texture;
};

#endif // SPRITE_H_INCLUDED
