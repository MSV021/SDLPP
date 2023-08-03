#include "Utility.h"
#include <stdexcept>

SDL_Window* SDLPP::CreateWindow(const char* title, int x, int y, int w, int h, unsigned flags) {
    SDL_Window* result = SDL_CreateWindow(title, x, y, w, h, flags); 
    if(!result) 
        throw new std::runtime_error("SDL failed to create window!"); 
    
    return result;
}

SDL_Renderer* SDLPP::CreateRenderer(SDL_Window* window, int index, unsigned flags) {
    SDL_Renderer* result = SDL_CreateRenderer(window, index, flags); 
    if(!result) 
        throw new std::runtime_error("SDL failed to create renderer"); 

    return result;
}

SDL_Texture* SDLPP::LoadTextureToScene(const char* path, Scene* scene) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "loading %s", path);
    return IMG_LoadTexture(scene->renderer, path);   
}

const SDLPP::ColorRGBA SDLPP::ColorRGBA::black   =   {0, 0, 0, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::gray    =   {128, 128, 128, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::silver  =   {192, 192, 192, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::white   =   {255, 255, 255, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::navy    =   {0, 0, 128, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::blue    =   {0, 0, 255, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::teal    =   {0, 128, 128, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::aqua    =   {0, 255, 255, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::green   =   {0, 128, 0, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::lime    =   {0, 255, 0, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::olive   =   {128, 128, 0, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::yellow  =   {255, 255, 0, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::maroon  =   {128, 0, 0, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::red     =   {255, 0, 0, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::purple  =   {128, 0, 128, 255};
const SDLPP::ColorRGBA SDLPP::ColorRGBA::fuchsia =   {255, 0, 255, 255};