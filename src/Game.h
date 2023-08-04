#ifndef GAME_H
#define GAME_H 

#include "Scene.h"
#include "Utility.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector> 
#include <string> 
#include <functional> 


namespace SDLPP {
    class Scene;
    class Game {
    public: 
        static void Initialize(int windowFlags, int rendererFlags);
        static void Update(int rate); 

        static void AddInitCallback(std::function<void()> callback); 
        static void AddUpdateCallback(std::function<void()> callback); 

        static Scene* GetActiveScene(void);

        static std::string Title;
        static int ScreenWidth; 
        static int ScreenHeight; 
        static ColorRGBA BackgroundColor;
    private: 
        static std::vector<std::function<void()>> initCallbacks; 
        static std::vector<std::function<void()>> updateCallbacks;

        static Scene* activeScene; 
    };
}

#endif