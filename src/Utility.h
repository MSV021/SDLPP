#ifndef UTILITY_H
#define UTILITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Scene.h"

namespace SDLPP {
    SDL_Window* CreateWindow(const char* title, int x, int y, int w, int h, unsigned flags);
    SDL_Renderer* CreateRenderer(SDL_Window* window, int index, unsigned flags);
    SDL_Texture* LoadTextureToScene(const char* path, Scene* scene);

    struct ColorRGBA {
        unsigned short r;
        unsigned short g;
        unsigned short b;
        unsigned short a;

        const static ColorRGBA black;
        const static ColorRGBA gray;
        const static ColorRGBA silver;
        const static ColorRGBA white;
        const static ColorRGBA navy;
        const static ColorRGBA blue;
        const static ColorRGBA teal;
        const static ColorRGBA aqua;
        const static ColorRGBA green;
        const static ColorRGBA lime;
        const static ColorRGBA olive;
        const static ColorRGBA yellow;
        const static ColorRGBA maroon;
        const static ColorRGBA red;
        const static ColorRGBA purple;
        const static ColorRGBA fuchsia;
    };
}

#endif