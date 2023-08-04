#include "Transform.h"

void SDLPP::Transform::Move(Vector move) {
    position.x += move.x; 
    position.y += move.y;
}

void SDLPP::Transform::Rotate(double angle) {
    rotation += angle;
}

void SDLPP::Transform::SetPosition(double x, double y) {
    position.x = x; 
    position.y = y; 
}

void SDLPP::Transform::SetRotation(double angle) {
    rotation = angle; 
}

void SDLPP::Transform::SetScale(double wm, double hm) {
    scale.x = wm; 
    scale.y = hm; 
}

SDLPP::Vector SDLPP::Transform::GetPosition() {
    return {position.x, position.y};
}

double SDLPP::Transform::GetRotation() {
    return rotation;
}

SDLPP::Vector SDLPP::Transform::GetScale() {
    return {scale.x, scale.y};
}
