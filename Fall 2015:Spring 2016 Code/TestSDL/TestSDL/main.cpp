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
    SDL_Surface *windowsurface = nullptr;
    SDL_Surface *imagesurface = nullptr;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        cout << "Video Initialization Error: " << SDL_GetError() <<endl; //GETS ERRORS
    else
    {
        window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
        if(window == NULL)
            cout << "Window Creation Error: "<< SDL_GetError() << endl;
        else{
            
           windowsurface = SDL_GetWindowSurface(window);
           imagesurface = SDL_LoadBMP("test.bmp");
            
           if (imagesurface== NULL)
                cout << "Error Loading Image: " << SDL_GetError() << endl;
           else{
                SDL_BlitSurface(imagesurface, NULL, windowsurface, NULL);
                SDL_UpdateWindowSurface(window);
                SDL_Delay(2000);
           }
            
        }
    }
    SDL_FreeSurface(imagesurface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    
}
