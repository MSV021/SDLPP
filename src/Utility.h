#ifndef UTILITY_H
#define UTILITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Scene.h"

namespace SDLPP {
    /**
     * Wrapper around `SDL_CreateWindow` which throws a runtime_error in case of failure.
     * @param title the title of the window
     * @param x the x position of the window, `SDL_WINDOWPOS_UNDEFINED` or `SDL_WINDOWPOS_CENTERED`
     * @param y the y position of the window, `SDL_WINDOWPOS_UNDEFINED` or `SDL_WINDOWPOS_CENTERED` 
     * @param w the width of the window 
     * @param h the height of the window 
     * @param flags 0, or one or more SDL_WindowFlags OR'd together
    */
    SDL_Window* CreateWindow(const char* title, int x, int y, int w, int h, unsigned flags);
    /**
     * Wrapper around `SDL_CreateRenderer` which throws a runtime_error in case of failure.
     * @param window the window where rendering is displayed
     * @param index the index of the rendering driver to initialize, or -1 to initialize the first one supporting the requested flags
     * @param flags 0, or one or more SDL_RendererFlags OR'd together
    */
    SDL_Renderer* CreateRenderer(SDL_Window* window, int index, unsigned flags);
    /**
     * Wrapper aroung `IMG_LoadTexture` which uses a specified Scene's renderer.
     * @param path path to the texture 
     * @param scene Scene to use its renderer for loading the texture 
    */
    SDL_Texture* LoadTextureToScene(const char* path, Scene* scene);

    /**
     * Represents a color value with red, green, blue and alpha.
     * Holds static properties for common colors.
    */
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