#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"

#include <SDL2/SDL.h>
#include <vector> 

namespace SDLPP {
    class Entity; 
    class Scene {
    public: 
        Scene(SDL_Window*, SDL_Renderer*);
        Scene(const Scene&) = delete;
        Scene(Scene&&) = delete;

        SDL_Window* window;
        SDL_Renderer* renderer;
    private: 
        std::vector<Entity*> entities; 
    };
}

#endif