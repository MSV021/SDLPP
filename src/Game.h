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

        static void SetTitle(const char* title);
        static void SetScreenDimensions(int width, int height);
        static void SetBackgroundColor(ColorRGBA color);
        static void AddInitCallback(std::function<void()> callback); 
        static void AddUpdateCallback(std::function<void()> callback); 

        static Scene* GetActiveScene(void);
    private: 
        static std::string title;
        static int screenWidth; 
        static int screenHeight; 
        static ColorRGBA backgroundColor;
        static std::vector<std::function<void()>> initCallbacks; 
        static std::vector<std::function<void()>> updateCallbacks;

        static Scene* activeScene; 
    };
}

#endif