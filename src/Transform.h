#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Entity.h"
#include "Component.h"
#include "Vector.h"

namespace SDLPP {
    class Transform : public Component {
    public: 
        Transform(Entity* owner = nullptr, Vector position = {0, 0}, double rotation = 0.0) : Component(owner), position{position}, rotation{rotation} {} 

        void Move(Vector move);
        void Rotate(double angle);

        void SetPosition(double x, double y); 
        void SetRotation(double angle); 

        SDLPP::Vector GetPosition(void); 
        double GetRotation(void);

        const char* GetType() { return "Transform"; } 
    private: 
        Vector position;
        double rotation; 
    };
}

#endif