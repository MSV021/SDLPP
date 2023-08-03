#ifndef GAME_H
#define GAME_H 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string> 
#include <functional> 

#include "Utility.h"
#include "Scene.h"

namespace SDLPP {
    class Game {
    public: 
        static void Initialize(int windowFlags, int rendererFlags);
        static void Update(int rate); 

        static void SetTitle(const char* title);
        static void SetScreenDimensions(int width, int height);
        static void SetBackgroundColor(ColorRGBA color);
        static void SetInitCallback(std::function<void()> callback); 
        static void SetUpdateCallback(std::function<void()> callback); 

        static Scene* GetActiveScene(void);
    private: 
        static std::string title;
        static int screenWidth; 
        static int screenHeight; 
        static ColorRGBA backgroundColor;
        static std::function<void()> initCallback; 
        static std::function<void()> updateCallback;

        static Scene* activeScene; 
    };
}

#endif