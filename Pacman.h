#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#include <vector>
#include "Sprite.h"

using namespace std;

typedef vector<SDL_Rect> Frames;
typedef vector<Frames> Rows;

class Packman : public Sprite{
    public:
        Packman(const string &imagePath, int frameWidth, int frameHeight, SDL_Renderer *renderer);
        void draw(SDL_Renderer *renderer, int pdx, int pdy);
        int pdx = 0;
        int pdy = 0;
    private:
        Rows rows;
        int currentFrame = 0;
        int currentRow = 0;
};

#endif // PACMAN_H_INCLUDED
