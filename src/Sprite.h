#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "Vector.h"

namespace SDLPP {
    class Game;
    class Sprite : public Component {
        friend class Game;
    public: 
        Sprite(Entity* owner = nullptr, SDL_Texture* texture = nullptr, int sortingOrder = 0, Vector pivot = pivotCenter) 
            : Component(owner), isVisible{true}, texture{texture}, sortingOrder{sortingOrder}, pivot{pivot}, flip{SDL_FLIP_NONE} {}
        Sprite(Entity* owner, const char* pathToTexture, int sortingOrder = 0, Vector pivot = pivotCenter); 
        Sprite(const Sprite&) = delete;
        Sprite(Sprite&&) = delete;  
        ~Sprite(void); 

        int GetSortingOrder(void);
        void SetSortingOrder(int sortingOrder);
        void SetFlip(bool flipX, bool flipY);
        
        void Show() { isVisible = true; }
        void Hide() { isVisible = false; }

        void Update() {}
        const char* GetType() { return "Sprite"; }

        const static Vector pivotUpLeft;    
        const static Vector pivotUp;    
        const static Vector pivotUpRight;    
        const static Vector pivotLeft;    
        const static Vector pivotCenter;    
        const static Vector pivotRight;    
        const static Vector pivotDownLeft;    
        const static Vector pivotDown;    
        const static Vector pivotDownRight;    
    private: 
        void Render(void); 

        bool isVisible; 
        SDL_Texture* texture; 
        int sortingOrder;
        SDL_RendererFlip flip; 
        Vector pivot;
    }; 
}

#endif