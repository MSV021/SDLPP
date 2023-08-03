#include "Component.h"

namespace SDLPP {
    class Sprite : public Component {
    public: 
        Sprite(Entity* owner = nullptr, SDL_Texture* texture = nullptr) : Component(owner), texture{texture}, flip{SDL_FLIP_NONE} {}  
        Sprite(Entity* owner, const char* pathToTexture); 
        Sprite(const Sprite&) = delete;
        Sprite(Sprite&&) = delete;  
        ~Sprite(void); 

        void SetFlip(bool flipX, bool flipY);

        void Show(void); 

        void Update() { Show(); }
        const char* GetType() { return "Sprite"; }
    private: 
        SDL_Texture* texture; 
        SDL_RendererFlip flip; 
    }; 
}