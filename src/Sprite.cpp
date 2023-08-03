#include "Sprite.h"
#include "Transform.h"
#include "Entity.h"
#include "Utility.h"

SDLPP::Sprite::Sprite(SDLPP::Entity* owner, const char* path) : Component(owner), flip{SDL_FLIP_NONE} {
    texture = SDLPP::LoadTextureToScene(path, owner->GetScene()); 
}

SDLPP::Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void SDLPP::Sprite::SetFlip(bool flipX, bool flipY) {
    if(flipX && flipY) 
        flip = static_cast<SDL_RendererFlip>(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL); 
    else if(flipX) 
        flip = SDL_FLIP_HORIZONTAL; 
    else if(flipY) 
        flip = SDL_FLIP_VERTICAL; 
    else 
        flip = SDL_FLIP_NONE; 
}

void SDLPP::Sprite::Show() {
    Transform* transform = owner->GetComponent<Transform>(); 

    SDL_Rect dest;
    dest.x = transform->GetPosition().x; 
    dest.y = transform->GetPosition().y; 

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h); 
    SDL_RenderCopyEx(owner->GetScene()->renderer, texture, NULL, &dest, transform->GetRotation(), NULL, flip); 
}
