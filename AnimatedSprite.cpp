#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite(const string &imagePath,
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

void AnimatedSprite::draw(SDL_Renderer *renderer, int dx, string side)
{
    SDL_RenderCopy(renderer, texture, &rows[currentRow][currentFrame], &spriteRect);
    if(dx == 0){
        if(side == "left"){
            currentRow = 0;  //Zaustavljanje iz leve strane
            currentFrame = 0;
        }
        else if(side == "right"){
            currentRow = 1;     //Zaustavljanje iz desne strane
            currentFrame = 7;
        }
    }
    if(dx > 0){ //Desna strana kretanja
    currentRow = 0;
    currentFrame++;
    if(currentFrame >= rows[currentRow].size()){
        currentFrame = 0;
    }
    }
    else if(dx < 0){ //Leva strana kretanja
        currentRow = 1;
        currentFrame++;
        if(currentFrame >= rows[currentRow].size()){
        currentFrame = 0;
        }
    }

}
