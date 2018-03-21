#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Line.h"
#include "Pacman.h"
#include "Barrier.h"

using namespace std;

class Engine {
    public:
        Engine();
        Engine(const string &gameTitle);
        void init();
        bool run();
        void colisionObjectsInit(vector <Barrier*> b);
        void mapcolision(Packman *player, Sprite *obst);
        void colision(Packman *pac, Barrier *bar);
        virtual ~Engine();
    private:
        float frameRateCap = 16;
        string gameTitle;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

#endif // ENGINE_H_INCLUDED



