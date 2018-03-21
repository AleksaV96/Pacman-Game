#ifndef ANIMATEDSPRITE_H_INCLUDED
#define ANIMATEDSPRITE_H_INCLUDED

#include <vector>
#include "Sprite.h"

using namespace std;

typedef vector<SDL_Rect> Frames;
typedef vector<Frames> Rows;

class AnimatedSprite : public Sprite{
    public:
        AnimatedSprite(const string &imagePath, int frameWidth, int frameHeight, SDL_Renderer *renderer);
        void draw(SDL_Renderer *renderer, int dx, string side);
    private:
        Rows rows;
        int currentFrame = 0;
        int currentRow = 0;
};

#endif // ANIMATEDSPRITE_H_INCLUDED
