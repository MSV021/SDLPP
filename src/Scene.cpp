#include "Game.h"
#include "Scene.h"

#include <algorithm>
#include <functional> 

void SDLPP::Scene::AddEntity(Entity* entity) {
    if(entity != nullptr) 
        entities.push_back(entity);
}

void SDLPP::Scene::RemoveEntity(Entity* entity) {
    auto iter = std::find(entities.begin(), entities.end(), entity); 
    if(iter != entities.end()) 
        entities.erase(iter);
}

void SDLPP::Scene::AddToRenderingQueue(SpriteRenderer* sprite) {
    if(sprite != nullptr) {
        renderingQueue.push_back(sprite);
        UpdateRenderingQueue();
    }
}

void SDLPP::Scene::UpdateRenderingQueue() {
    std::sort(renderingQueue.begin(), renderingQueue.end(), [](SpriteRenderer* a, SpriteRenderer* b){ return a->GetSortingOrder() < b->GetSortingOrder(); }); 
}

void SDLPP::Scene::RemoveFromRenderingQueue(SpriteRenderer* sprite) {
    auto iter = std::find(renderingQueue.begin(), renderingQueue.end(), sprite); 
    if(iter != renderingQueue.end()) 
        renderingQueue.erase(iter); 
}



