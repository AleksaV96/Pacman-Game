#include "Engine.h"


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
                              SDL_WINDOWPOS_UNDEFINED, 228, 248, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

bool Engine::run()
{
    vector<Barrier*> colisionObjects;
    colisionObjectsInit(colisionObjects);
    Sprite *background = new Sprite("resources/background.png", renderer);
    Packman *pac = new Packman("resources/pacman.png", 15, 15, renderer);


    pac->spriteRect.x = 5;//
    pac->spriteRect.y = 5;//Pozicioniranje pacmana


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
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                        case SDLK_LEFT:
                            break;
                        case SDLK_RIGHT:
                            break;
                        case SDLK_w:
                            pac->pdx = 0;
                            pac->pdy = -2;
                            break;
                        case SDLK_s:
                            pac->pdx = 0;
                            pac->pdy = 2;
                            break;
                        case SDLK_d:
                            pac->pdy = 0;
                            pac->pdx = 2;
                            break;
                        case SDLK_a:
                            pac->pdy = 0;
                            pac->pdx = -2;
                            break;
                    }
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        background->draw(renderer);


        pac->move(pac->pdx, pac->pdy);
        pac->draw(renderer, pac->pdx, pac->pdy);


        for(int i = 0; i < colisionObjects.size(); i++){
            colision(pac, colisionObjects[i]);
        }


        mapcolision(pac, background);



        SDL_RenderPresent(renderer);




        frameEnd = SDL_GetTicks();

        if(frameEnd - frameStart < frameRateCap) {
            SDL_Delay(frameRateCap - (frameEnd - frameStart));
        }
    }

    return true;
}

void Engine::mapcolision(Packman *player, Sprite *obst)
{
    if(player->spriteRect.y > obst->spriteRect.y + 228){
        player->pdy = 0;
    }

    if(player->spriteRect.y < obst->spriteRect.y + 6){
        player->pdy = 0;
    }

    if(player->spriteRect.x < obst->spriteRect.x + 6) {
        player->pdx = 0;
    }

    if(player->spriteRect.x > obst->spriteRect.x + 204) {
        player->pdx = 0;
    }
}

void Engine::colision(Packman *pac, Barrier *bar)
{
    if(pac->spriteRect.x < bar->spriteRect.x + bar->spriteRect.w &&
       pac->spriteRect.x + pac->spriteRect.w > bar->spriteRect.x &&
       pac->spriteRect.y < bar->spriteRect.h + bar->spriteRect.h + 5 &&
       pac->spriteRect.y + pac->spriteRect.h > bar->spriteRect.y)
    {
        pac->pdx = 0;
        pac->pdy = 0;

    }
}

void Engine::colisionObjectsInit(vector<Barrier*> b)
{
    Barrier *bar1 = new Barrier(renderer, 22, 20, 23, 15);
    b.push_back(bar1);
    Barrier *bar2 = new Barrier(renderer, 22, 52, 8, 23);
    b.push_back(bar2);
    Barrier *bar3 = new Barrier(renderer, 62, 52, 55, 7);
    b.push_back(bar3);
    Barrier *bar4 = new Barrier(renderer, 62, 76, 7, 31);
    b.push_back(bar4);
    Barrier *bar5 = new Barrier(renderer, 86, 100, 31, 55);
    b.push_back(bar5);
    Barrier *bar6 = new Barrier(renderer, 2, 76, 31, 43);
    b.push_back(bar6);
    Barrier *bar7 = new Barrier(renderer, 2, 124, 31, 44);
    b.push_back(bar7);
    Barrier *bar8 = new Barrier(renderer, 62, 125, 30, 7);
    b.push_back(bar8);
    Barrier *bar9 = new Barrier(renderer, 62, 20, 15, 31);
    b.push_back(bar9);
    Barrier *bar10 = new Barrier(renderer, 134, 20, 15, 31);
    b.push_back(bar10);
    Barrier *bar11 = new Barrier(renderer, 182, 20, 15, 23);
    b.push_back(bar11);
    Barrier *bar12 = new Barrier(renderer, 182, 52, 7, 23);
    b.push_back(bar12);
    Barrier *bar13 = new Barrier(renderer, 182, 76, 32, 43);
    b.push_back(bar13);
    Barrier *bar14 = new Barrier(renderer, 182, 124, 32, 43);
    b.push_back(bar14);
    Barrier *bar15 = new Barrier(renderer, 158, 52, 55, 7);
    b.push_back(bar15);
    Barrier *bar16 = new Barrier(renderer, 134, 76, 7, 31);
    b.push_back(bar16);
    Barrier *bar17 = new Barrier(renderer, 86, 52, 7, 55);
    b.push_back(bar17);
    Barrier *bar18 = new Barrier(renderer, 110, 52, 32, 7);
    b.push_back(bar18);
    Barrier *bar19 = new Barrier(renderer, 2, 196, 7, 19);
    b.push_back(bar19);
    Barrier *bar20 = new Barrier(renderer, 206, 196, 7, 19);
    b.push_back(bar20);
    Barrier *bar21 = new Barrier(renderer, 62, 172, 7, 31);
    b.push_back(bar21);
    Barrier *bar22 = new Barrier(renderer, 134, 172, 7, 31);
    b.push_back(bar22);
    Barrier *bar23 = new Barrier(renderer, 86, 148, 7, 55);
    b.push_back(bar23);
    Barrier *bar24 = new Barrier(renderer, 110, 148, 31, 7);
    b.push_back(bar24);
    Barrier *bar25 = new Barrier(renderer, 134, 220, 7, 71);
    b.push_back(bar25);
    Barrier *bar26 = new Barrier(renderer, 158, 196, 31, 7);
    b.push_back(bar26);
    Barrier *bar27 = new Barrier(renderer, 22, 220, 7, 71);
    b.push_back(bar27);
    Barrier *bar28 = new Barrier(renderer, 62, 196, 31, 7);
    b.push_back(bar28);
    Barrier *bar29 = new Barrier(renderer, 158, 124, 31, 7);
    b.push_back(bar29);
}

Engine::~Engine()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

