#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Entity.h"
#include "Component.h"
#include "Vector.h"

namespace SDLPP {
    class Game;
    /**
     * Component determining an entity's position, rotation and scale in the scene. 
     * Every entity has a Transform component by default that can't be removed, and can be accessed through Entity::transform.
    */
    class Transform : public Component {
        friend class Game;
    public: 
        Transform(Entity* owner = nullptr, Vector position = Vector::zero, double rotation = 0.0, Vector scale = Vector::one) 
            : Component(owner), position{position}, rotation{rotation}, scale{scale} {} 

        /** 
         * Adds the specified vector to position.
         */
        void Move(Vector move);
        /**
         * Adds the specified angle to rotation.
        */
        void Rotate(double angle);

        void SetPosition(double x, double y); 
        void SetPosition(Vector newPosition); 
        void SetRotation(double angle); 
        void SetScale(double widthMultiplier, double heightMultiplier); 
        void SetScale(Vector newScale); 

        Vector GetPosition(void); 
        double GetRotation(void);
        Vector GetScale(void);
        
        /**
         * Returns a string representation of the Component's type.
        */
        const char* GetType() { return "Transform"; } 
    private: 
        /**
         * This function is called every frame by Game::Update if owner Entity is attached to an active Scene.
        */
        void Update() {} 

        Vector position;
        double rotation; 
        Vector scale;
    };
}

#endif