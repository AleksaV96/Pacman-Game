#include "Line.h"

Line::Line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2)
{

}

void Line::draw(SDL_Renderer* renderer){
  SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Line::move(int dx, int dy){
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
}
