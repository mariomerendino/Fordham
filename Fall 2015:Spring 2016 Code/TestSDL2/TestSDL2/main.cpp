//
//  main.cpp
//  TestSDL
//
//  Created by Mario J Merendino on 11/3/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//
#include <iostream>
#include "SDL2/SDL.h"
using namespace std;

int main(int argc, char * argv[]) {
    SDL_Window *window = nullptr;

    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,SDL_WINDOW_SHOWN);
    bool isrunning = true;
    SDL_Event ev;
    while(isrunning)
    {
        while(SDL_PollEvent(&ev) != 0)
        {
            if(ev.type == SDL_QUIT)
                isrunning =false;
        }
        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    
}
