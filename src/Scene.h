#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "Sprite.h"

#include <SDL2/SDL.h>
#include <vector> 

namespace SDLPP {
    class Game;
    class Scene {
        friend class Game;
    public: 
        Scene(SDL_Window* window, SDL_Renderer* renderer) : window{window}, renderer{renderer} {}
        Scene(const Scene&) = delete;
        Scene(Scene&&) = delete;

        void AddEntity(Entity* entity);
        void AddToRenderingQueue(SDLPP::Sprite* sprite);
        void UpdateRenderingQueue(void);

        SDL_Window* window;
        SDL_Renderer* renderer;
    private: 
        std::vector<Entity*> entities; 
        std::vector<Sprite*> renderingQueue;
    };
}

#endif