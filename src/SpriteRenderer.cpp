#include "SpriteRenderer.h"
#include "Game.h"
#include "Transform.h"
#include "Entity.h"
#include "Utility.h"

SDLPP::SpriteRenderer::SpriteRenderer(SDLPP::Entity* owner, const char* path, int sortingOrder, Vector pivot) 
    : Component(owner), isVisible{true}, sortingOrder{sortingOrder}, pivot{pivot}, flip{SDL_FLIP_NONE} {
    texture = Game::LoadTexture(path); 
    owner->GetScene()->AddToRenderingQueue(this);
}

SDLPP::SpriteRenderer::~SpriteRenderer() {
    SDL_DestroyTexture(texture);
}

int SDLPP::SpriteRenderer::GetSortingOrder() {
    return sortingOrder; 
}

void SDLPP::SpriteRenderer::SetSortingOrder(int sortingOrder) {
    this->sortingOrder = sortingOrder; 
    owner->GetScene()->UpdateRenderingQueue();
}

void SDLPP::SpriteRenderer::SetFlip(bool flipX, bool flipY) {
    if(flipX && flipY) 
        flip = static_cast<SDL_RendererFlip>(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL); 
    else if(flipX) 
        flip = SDL_FLIP_HORIZONTAL; 
    else if(flipY) 
        flip = SDL_FLIP_VERTICAL; 
    else 
        flip = SDL_FLIP_NONE; 
}

void SDLPP::SpriteRenderer::Render() {
    Transform* transform = owner->GetComponent<Transform>(); 

    SDL_Rect dest; 
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h); 
    dest.w *= transform->GetScale().x;
    dest.h *= transform->GetScale().y;
    dest.x = transform->GetPosition().x - (pivot.x * dest.w); 
    dest.y = transform->GetPosition().y - (pivot.y * dest.h);

    SDL_RenderCopyEx(Game::GetRenderer(), texture, NULL, &dest, transform->GetRotation(), NULL, flip); 
}

const SDLPP::Vector SDLPP::SpriteRenderer::pivotUpLeft    = {0, 0};
const SDLPP::Vector SDLPP::SpriteRenderer::pivotUp        = {0.5, 0};
const SDLPP::Vector SDLPP::SpriteRenderer::pivotUpRight   = {1, 0};
const SDLPP::Vector SDLPP::SpriteRenderer::pivotLeft      = {0, 0.5};
const SDLPP::Vector SDLPP::SpriteRenderer::pivotCenter    = {0.5, 0.5};
const SDLPP::Vector SDLPP::SpriteRenderer::pivotRight     = {1, 0.5};
const SDLPP::Vector SDLPP::SpriteRenderer::pivotDownLeft  = {0, 1};
const SDLPP::Vector SDLPP::SpriteRenderer::pivotDown      = {0.5, 1};
const SDLPP::Vector SDLPP::SpriteRenderer::pivotDownRight = {1, 1};
