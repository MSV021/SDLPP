#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include "Vector.h"

#include <SDL2/SDL.h>
#include <vector> 

namespace SDLPP {
    class Scene;
    class Transform;
    class Entity {
        friend class Scene;
    public: 
        Entity(Scene* scene = nullptr, Vector position = Vector::zero, double rotation = 0.0, Vector scale = Vector::one);
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

        Transform* transform; 
    private: 
        void UpdateComponents(); 

        Scene* scene; 
        std::vector<Component*> components;
    }; 
}
#endif