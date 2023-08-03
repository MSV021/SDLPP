#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <vector> 

#include "Component.h"

namespace SDLPP {
    class Scene;
    class Entity {
    public: 
        Entity(Scene* scene = nullptr);
        Entity(const Entity&) = delete;
        Entity(Entity&&) = delete;
        ~Entity(void);
        
        template<typename T> 
        T* GetComponent() {
            T* target; 
            for(auto& c : components) {
                if((target = dynamic_cast<T*>(c)) != nullptr) 
                    return target;
            }

            return nullptr;
        }

        
        template<typename T, typename ...Args> 
        T* AddComponent(Args... args) {
            T* newComponent = new T(this, args...); 
            components.push_back(newComponent);
            return newComponent; 
        }

        void SetScene(Scene* targetScene) { scene = targetScene; }
        Scene* GetScene(void); 
    private: 
        Scene* scene; 
        std::vector<Component*> components;
    }; 
}
#endif