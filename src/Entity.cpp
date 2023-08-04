#include "Entity.h"
#include "Scene.h"
#include "Transform.h"

SDLPP::Entity::Entity(Scene* scene, Vector position, double rotation, Vector scale) : scene{scene} {
    transform = AddComponent<Transform>(position, rotation, scale);
    scene->AddEntity(this);
} 

SDLPP::Entity::~Entity() {
    for(auto c : components) 
        delete c; 
}

SDLPP::Scene* SDLPP::Entity::GetScene() {
    return scene;
}

void SDLPP::Entity::UpdateComponents() {
    for(auto* c : components) 
        c->Update();
}