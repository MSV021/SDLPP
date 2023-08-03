#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h> 

namespace SDLPP {
    class Entity;
    class Component {
    public: 
        Component(Entity* owner = nullptr) : owner{owner} {} 

        virtual void Update(void) = 0; 
        virtual const char* GetType(void) = 0; 
    protected: 
        Entity* owner; 
    };
}

#endif