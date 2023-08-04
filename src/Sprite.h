#include "Component.h"
#include "Vector.h"

namespace SDLPP {
    class Sprite : public Component {
    public: 
        Sprite(Entity* owner = nullptr, SDL_Texture* texture = nullptr, Vector pivot = pivotCenter) 
            : Component(owner), isVisible{true}, texture{texture}, flip{SDL_FLIP_NONE} {}
        Sprite(Entity* owner, const char* pathToTexture, Vector pivot = pivotCenter); 
        Sprite(const Sprite&) = delete;
        Sprite(Sprite&&) = delete;  
        ~Sprite(void); 

        
        void SetFlip(bool flipX, bool flipY);
        
        void Show() { isVisible = true; }
        void Hide() { isVisible = false; }

        void Update() { if(isVisible) Render(); }
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
        SDL_RendererFlip flip; 
        Vector pivot;
    }; 
}