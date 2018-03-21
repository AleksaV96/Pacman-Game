#include <SDL2/SDL.h>
#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

class Line{
    public:
        int x1;
        int y1;
        int x2;
        int y2;
        Line(int, int, int, int);
        void draw(SDL_Renderer*);
        void move(int dx, int dy);
};

#endif // LINE_H_INCLUDED
