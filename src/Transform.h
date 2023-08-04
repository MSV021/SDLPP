#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Entity.h"
#include "Component.h"
#include "Vector.h"

namespace SDLPP {
    class Transform : public Component {
    public: 
        Transform(Entity* owner = nullptr, Vector position = Vector::zero, double rotation = 0.0, Vector scale = Vector::one) 
            : Component(owner), position{position}, rotation{rotation}, scale{scale} {} 

        void Move(Vector move);
        void Rotate(double angle);

        void SetPosition(double x, double y); 
        void SetRotation(double angle); 
        void SetScale(double widthMultiplier, double heightMultiplier); 

        Vector GetPosition(void); 
        double GetRotation(void);
        Vector GetScale(void);
        
        void Update() {} 
        const char* GetType() { return "Transform"; } 
    private: 
        Vector position;
        double rotation; 
        Vector scale;
    };
}

#endif