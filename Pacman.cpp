#include "Pacman.h"

Packman::Packman(const string &imagePath,
                               int frameWidth,
                               int frameHeight,
                               SDL_Renderer *renderer) : Sprite(imagePath, renderer)
{

    for(int i = 0; i < spriteRect.h/frameHeight; i++)
    {
        Frames f;
        for(int j = 0; j < spriteRect.w/frameWidth; j++)
        {
            SDL_Rect r = {j*frameWidth,i*frameHeight,frameWidth,frameHeight};
            f.push_back(r);
        }
        rows.push_back(f);
    }

    spriteRect.w = frameWidth;
    spriteRect.h = frameHeight;
}

void Packman::draw(SDL_Renderer *renderer, int pdx, int pdy)
{
    SDL_RenderCopy(renderer, texture, &rows[currentRow][currentFrame], &spriteRect);
    if(pdx > 0){ //Desno
    currentRow = 0;
    currentFrame++;
    if(currentFrame >= rows[currentRow].size()){
        currentFrame = 0;
    }

    }
    else if(pdx < 0){ //Levo
        currentRow = 1;
        currentFrame++;
        if(currentFrame >= rows[currentRow].size()){
        currentFrame = 0;
        }
    }
    else if(pdy < 0){ //Gore
        currentRow = 2;
        currentFrame++;
        if(currentFrame >= rows[currentRow].size()){
        currentFrame = 0;
        }
    }
    else if(pdy > 0){ //Dole
        currentRow = 3;
        currentFrame++;
        if(currentFrame >= rows[currentRow].size()){
        currentFrame = 0;
        }
    }

}
