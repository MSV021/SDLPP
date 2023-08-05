#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "Vector.h"

namespace SDLPP {
    class Game;
    /**
     * Main 2D rendering component.
     * 
     * Loads a texture and renders it to screen using owner's scene renderer, and transform properties.
    */
    class SpriteRenderer : public Component {
        friend class Game;
    public: 
        SpriteRenderer(Entity* owner = nullptr, SDL_Texture* texture = nullptr, int sortingOrder = 0, Vector pivot = pivotCenter) 
            : Component(owner), isVisible{true}, texture{texture}, sortingOrder{sortingOrder}, pivot{pivot}, flip{SDL_FLIP_NONE} {}
        SpriteRenderer(Entity* owner, const char* pathToTexture, int sortingOrder = 0, Vector pivot = pivotCenter); 
        SpriteRenderer(const SpriteRenderer&) = delete;
        SpriteRenderer(SpriteRenderer&&) = delete;  
        ~SpriteRenderer(void); 

        /**
         * Returns this SpriteRenderer's rendering priority.
        */
        int GetSortingOrder(void);
        /**
         * Sets this SpriteRenderer's rendering priority. Renderers with higher priority render their sprite over those
         * with lower priority. 
         * Rendering order of SpriteRenderer's with same sortingOrder is undefined.
         * @param sortingOrder 
        */
        void SetSortingOrder(int sortingOrder);
        /**
         * Use this to flip the sprite horizontally or vertically.
         * @param flipX determines horizontal flipping
         * @param flipY determines vertical flipping
        */
        void SetFlip(bool flipX, bool flipY);
        
        /**
         * Makes this sprite visible. Every sprite is visible by default.
        */
        void Show() { isVisible = true; }
        /**
         * Stops rendering sprite.
        */
        void Hide() { isVisible = false; }

        /**
         * Returns a string representation of the component's type.
        */
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
        /**
         * Actual rendering call. Renders specified texture to screen using transform properties.
         * Called by Game::Update if this SpriteRenderer is in the active scene's rendering queue.
        */
        void Render(void);

        void Update() {} 

        bool isVisible; 
        SDL_Texture* texture; 
        int sortingOrder;
        SDL_RendererFlip flip; 
        Vector pivot;
    }; 
}

#endif