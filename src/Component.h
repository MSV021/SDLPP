#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h> 

namespace SDLPP {
    class Game;
    class Entity;
    /**
     * The class that every component derives from.
     * 
     * Components are used to give entities unique behaviour. 
     * Derive custom components from this class to be able to add them to entities.
     * Components can only be created through Entity::AddComponent, and if the Entity they are
     * part of is associated to an avtive scene their Update() method is called every frame.
     * Every component has a pointer to the Entity owning them.
    */
    class Component {
        friend class Game;
        friend class Entity;
    public: 
        /**
         * Returns a string representation of the Component's type.
        */
        virtual const char* GetType(void) = 0; 
    protected: 
        Component(Entity* owner = nullptr) : owner{owner} {} 
        /**
         * This function is called every frame if owner is part of an active Scene.
        */
        virtual void Update(void) = 0; 

        Entity* owner; 
    };
}

#endif