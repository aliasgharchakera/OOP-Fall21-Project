#include "Traffic.hpp"

    Traffic::Traffic(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        int p = rand () % 3 + 1;
        switch(p){
            case 1: src = {188, 94, 80, 45};
            break;
            case 2: src = {188, 141, 80, 45};
            break;
            case 3: src = {188, 188, 80, 45};
            break;
            // case 2: src = {1559, 2, 632, 640};
        } 
    }
// drawing animations when the bullet hits the right edge
    void Traffic::draw(){
        if (mover.y == 300){
            if (n == 10)
                n = 0;
            else{
                mover.w += 2; mover.h += 2;
                n++;
            }
        }
        mover.y += 1;
        Unit::draw(src, mover);
    }
// defining the animation function
    void Traffic::animation(int n){
        switch (n){
        case 0: src = {1559, 1, 632, 640};
        mover.w = 50; mover.h = 50;
        mover.x = 1000;
        mover.y = 50;
        break;
        case 1: mover.w += 2; mover.h += 2;
        break;
        }
    }