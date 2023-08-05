#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include "Vector.h"

#include <SDL2/SDL.h>
#include <vector> 

namespace SDLPP {
    class Scene;
    class Transform;
    /**
     * Entities represent any sort of objects that reside in SDLPP Scenes.  
     * 
     * Every Entity is its components. It's a blank slate to hold different 
     * combination of components that define its behaviour. 
     * Every Entity must be constructed in a scene, and has a Transform component by default.
    */
    class Entity {
        friend class Game;
    public: 
        Entity(Scene* scene = nullptr, Vector position = Vector::zero, double rotation = 0.0, Vector scale = Vector::one);
        Entity(const Entity&) = delete;
        Entity(Entity&&) = delete;
        ~Entity(void);
        
        /**
         * Returns a pointer to a component of type T from entity, or nullptr if entity doesn't have the component.  
        */
        template<typename T> 
        T* GetComponent() {
            T* target; 
            for(auto& c : components) {
                if((target = dynamic_cast<T*>(c)) != nullptr) 
                    return target;
            }

            return nullptr;
        }

        /**
         * Creates and adds a new component of type T to the entity and returns a pointer to it. Every component can be added once 
         * to every entity. Multiple attempts to add the same component will be ignored.
         * @param args arguments used to construct the component
        */
        template<typename T, typename ...Args> 
        T* AddComponent(Args... args) {
            T* newComponent = new T(this, args...); 
            components.push_back(newComponent);
            return newComponent; 
        }

        /**
         * Set the scene this entity belongs to. This will remove this entity from the previous scene and adds it to the targetScene.
         * @param targetScene a pointer to the Scene to add this entity to
        */
        void SetScene(Scene* targetScene);
        /**
         * Returns a pointer to the current scene this entity belongs to
        */
        Scene* GetScene(void); 

        void Clear(void); 

        Transform* transform; 
    private: 
        /**
         * Calls every components Update() method. It is itself called from Game::Update if entity is part of an active Scene. 
        */
        void UpdateComponents(); 

        Scene* scene; 
        std::vector<Component*> components;
    }; 
}
#endif