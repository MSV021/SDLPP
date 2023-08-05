#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "SpriteRenderer.h"

#include <SDL2/SDL.h>
#include <vector> 

namespace SDLPP {
    class Game;
    class SpriteRenderer; 
    /**
     * A Scene is a container for entities, that can be loaded into the game. 
     * 
     * One Scene can be active at a time. If active, a Scene determines what is rendered and updated every frame. 
    */
    class Scene {
        friend class Game;
        friend class Entity; 
        friend class SpriteRenderer;
    public: 
        Scene() {}
        Scene(const Scene&) = delete;
        Scene(Scene&&) = delete;

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
    private: 
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

        std::vector<Entity*> entities; 
        std::vector<SpriteRenderer*> renderingQueue;
    };
}

#endif