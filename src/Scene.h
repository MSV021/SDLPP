#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "SpriteRenderer.h"

#include <SDL2/SDL.h>
#include <vector> 

namespace SDLPP {
    class Game;
    /**
     * A Scene is used to hold window and renderer contexts for entities
    */
    class Scene {
        friend class Game;
        friend class Entity;
        friend class SpriteRenderer;
        friend SDL_Texture* LoadTextureToScene(const char*, Scene*);
    public: 
        Scene(SDL_Window* window, SDL_Renderer* renderer) : window{window}, renderer{renderer} {}
        Scene(const Scene&) = delete;
        Scene(Scene&&) = delete;
    private: 
        /**
         * Adds entity to this scene. Every Entity must be added to an active scene in order to be processed.
         * @param entity a pointer to the Entity to be added to this scene. Note that a Scene takes ownership of its entities
        */
        void AddEntity(Entity* entity);
        /**
         * Removes entity from this scene. Note that this will not remove entity's Sprite from renderingQueue if present.
         * @param entity a pointer to the Entity to be removed from this scene
        */
        void RemoveEntity(Entity* entity); 
        /**
         * Adds sprite to the this scene's rendering queue. Calls UpdateRenderingQueue() after to retain rendering queue's order.
         * @param sprite a pointer to the Sprite to be added to the rendering queue
        */
        void AddToRenderingQueue(SDLPP::SpriteRenderer* sprite);
        /**
         * Sorts Sprites in the rendering queue based on their sortingOrder.
        */
        void UpdateRenderingQueue(void);
        /**
         * Removes sprite from this scene's rendering queue. Calls UpdateRenderingQueue() after to retain rendering queue's order.
         * @param sprite a pointer to the Sprite to be removed from rendering queue
        */
        void RemoveFromRenderingQueue(SDLPP::SpriteRenderer* sprite);

        SDL_Window* window;
        SDL_Renderer* renderer;
        std::vector<Entity*> entities; 
        std::vector<SpriteRenderer*> renderingQueue;
    };
}

#endif