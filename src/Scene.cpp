#include "Game.h"
#include "Scene.h"

#include <functional> 

 void SDLPP::Scene::AddEntity(Entity* entity) {
    if(entity != NULL) {
        entities.push_back(entity);
        auto fp = std::bind(&Entity::UpdateComponents, entity);  
        Game::AddUpdateCallback(fp);
    }
}