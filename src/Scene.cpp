#include "Game.h"
#include "Scene.h"

#include <algorithm>
#include <functional> 

void SDLPP::Scene::AddEntity(Entity* entity) {
    if(entity != nullptr) {
        entities.push_back(entity);
        auto fp = std::bind(&Entity::UpdateComponents, entity);  
        Game::AddUpdateCallback(fp);
    }
}

void SDLPP::Scene::AddToRenderingQueue(Sprite* sprite) {
    if(sprite != nullptr) {
        renderingQueue.push_back(sprite);
        UpdateRenderingQueue();
    }
}

void SDLPP::Scene::UpdateRenderingQueue() {
    std::sort(renderingQueue.begin(), renderingQueue.end(), [](Sprite* a, Sprite* b){ return a->GetSortingOrder() < b->GetSortingOrder(); }); 
}



