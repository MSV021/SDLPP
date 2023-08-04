#include "Sprite.h"
#include "Transform.h"
#include "Entity.h"
#include "Utility.h"

SDLPP::Sprite::Sprite(SDLPP::Entity* owner, const char* path, int sortingOrder, Vector pivot) 
    : Component(owner), isVisible{true}, sortingOrder{sortingOrder}, pivot{pivot}, flip{SDL_FLIP_NONE} {
    texture = SDLPP::LoadTextureToScene(path, owner->GetScene()); 
    owner->GetScene()->AddToRenderingQueue(this);
}

SDLPP::Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

int SDLPP::Sprite::GetSortingOrder() {
    return sortingOrder; 
}

void SDLPP::Sprite::SetSortingOrder(int sortingOrder) {
    this->sortingOrder = sortingOrder; 
    owner->GetScene()->UpdateRenderingQueue();
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

void SDLPP::Sprite::Render() {
    Transform* transform = owner->GetComponent<Transform>(); 

    SDL_Rect dest; 
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h); 
    dest.w *= transform->GetScale().x;
    dest.h *= transform->GetScale().y;
    dest.x = transform->GetPosition().x - (pivot.x * dest.w); 
    dest.y = transform->GetPosition().y - (pivot.y * dest.h);

    SDL_RenderCopyEx(owner->GetScene()->renderer, texture, NULL, &dest, transform->GetRotation(), NULL, flip); 
}

const SDLPP::Vector SDLPP::Sprite::pivotUpLeft    = {0, 0};
const SDLPP::Vector SDLPP::Sprite::pivotUp        = {0.5, 0};
const SDLPP::Vector SDLPP::Sprite::pivotUpRight   = {1, 0};
const SDLPP::Vector SDLPP::Sprite::pivotLeft      = {0, 0.5};
const SDLPP::Vector SDLPP::Sprite::pivotCenter    = {0.5, 0.5};
const SDLPP::Vector SDLPP::Sprite::pivotRight     = {1, 0.5};
const SDLPP::Vector SDLPP::Sprite::pivotDownLeft  = {0, 1};
const SDLPP::Vector SDLPP::Sprite::pivotDown      = {0.5, 1};
const SDLPP::Vector SDLPP::Sprite::pivotDownRight = {1, 1};
