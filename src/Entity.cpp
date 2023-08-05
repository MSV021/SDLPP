#include "Entity.h"
#include "Scene.h"
#include "Transform.h"
#include "SpriteRenderer.h"

SDLPP::Entity::Entity(Scene* scene, Vector position, double rotation, Vector scale) : scene{scene} {
    transform = AddComponent<Transform>(position, rotation, scale);
    scene->AddEntity(this);
} 

SDLPP::Entity::~Entity() {
    for(auto c : components) 
        delete c; 
}

void SDLPP::Entity::SetScene(Scene* targetScene) {
    SpriteRenderer* sprite = GetComponent<SpriteRenderer>();
    if(sprite != nullptr) {
        scene->RemoveFromRenderingQueue(sprite);
        targetScene->AddToRenderingQueue(sprite);
    }

    scene->RemoveEntity(this);
    targetScene->AddEntity(this);

    scene = targetScene; 
}

SDLPP::Scene* SDLPP::Entity::GetScene() {
    return scene;
}

void SDLPP::Entity::UpdateComponents() {
    for(auto* c : components) 
        c->Update();
}