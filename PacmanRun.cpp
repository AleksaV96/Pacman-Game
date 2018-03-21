#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Line.h"
#include "Pacman.h"


using namespace std;

class Engine {
    public:
        Engine();
        Engine(const string &gameTitle);
        void init();
        bool run();
        virtual ~Engine();
    private:
        float frameRateCap = 16;
        string gameTitle;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

Engine::Engine()
{
    gameTitle = "";
}

Engine::Engine(const string &gameTitle): gameTitle(gameTitle)
{
}


void Engine::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(gameTitle.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

bool Engine::run()
{
    Packman *s = new Packman("resources/pacman.png", 16, 16, renderer);


    s->spriteRect.x = 50;
    s->spriteRect.y = 150;

    int dx = 0;
    int dy = 0;
    string side = "";

    bool running = true;
    SDL_Event event;
    uint32_t frameStart = 0;
    uint32_t frameEnd = 0;
    while(running) {
        SDL_Delay(20);
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_UP:
                            break;
                        case SDLK_DOWN:
                            break;
                        case SDLK_LEFT:
                            dx -= 5;
                            side = "left";
                            break;
                        case SDLK_RIGHT:
                            dx += 5;
                            side = "right";
                            break;
                        case SDLK_SPACE:
                            dy -= 50;
                            break;
                    }
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);




        s->move(dx, dy);
        s->draw(renderer, dx, dy);

        if(s->spriteRect.y < 10){
            dy += 50;
        }
        if(s->spriteRect.y >= 150){
            dy = 0;
        }


        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();

        if(frameEnd - frameStart < frameRateCap) {
            SDL_Delay(frameRateCap - (frameEnd - frameStart));
        }
    }

    return true;
}

Engine::~Engine()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argv, char** args)
{
    Engine *engine = new Engine("DomaciSprite");
    engine->init();
    engine->run();
    delete engine;
    return 0;
}
