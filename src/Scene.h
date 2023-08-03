#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"

#include <SDL2/SDL.h>
#include <vector> 

namespace SDLPP {
    class Scene {
    public: 
        Scene(SDL_Window* window, SDL_Renderer* renderer) : window{window}, renderer{renderer} {}
        Scene(const Scene&) = delete;
        Scene(Scene&&) = delete;

        void AddEntity(Entity* entity);

        SDL_Window* window;
        SDL_Renderer* renderer;
    private: 
        std::vector<Entity*> entities; 
    };
}

#endif