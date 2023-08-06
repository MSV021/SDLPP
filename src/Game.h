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
    /**
     * Static class used to initializes SDLPP and start the main loop.
     * 
     * Game has useful properties to configure game's settings (e.g., Title, ScreenWidth, ScreenHeight, ...) and 
     * also provides the possiblity to register custom functions to be called on game's initialization and/or every frame.
     * It also has a Scene that provides it with information about what is presented on the screen. This Scene can be accessed 
     * with Game::GetActiveScene.
    */
    class Game {
    public: 
        /**
         * Initializes SDLPP by creating main window, renderer and Scene.
         * Calls all functions registered by Game::AddInitCallback. Multiple calls are ignored.
        */
        static void Initialize(void);
        /**
         * Starts game's main loop with a specified framerate. 
         * Calls all functions registered by Game::AddUpdateCallback. Multiple calls are ignored.
         * @param rate main loop's framerate
        */
        static void Update(int rate); 

        /**
         * Registers a function to be called at initialization.
         * @param callback function to be registered 
        */
        static void AddInitCallback(std::function<void()> callback); 
        /** 
         * Registers a function to be called every frame.
         * @param callback function to be registered
        */
        static void AddUpdateCallback(std::function<void()> callback); 
        
        /**
         * Returns current active scene.
        */
        static Scene* GetActiveScene(void);
        /**
         * Returns main renderer.
        */
        static SDL_Renderer* GetRenderer() { return renderer; } 

        /**
         * Utility function that loads an image directly into a render texture and returns it.
         * @param path path to target image
        */
        static SDL_Texture* LoadTexture(const char* path);

        static std::string Title;
        static bool Fullscreen; 
        static int ScreenWidth; 
        static int ScreenHeight; 
        static ColorRGBA BackgroundColor;
    private: 
        static int windowFlags;
        static int rendererFlags;
        static SDL_Window* window; 
        static SDL_Renderer* renderer;
        static std::vector<std::function<void()>> initCallbacks; 
        static std::vector<std::function<void()>> updateCallbacks;

        static bool initialized; 
        static bool started;

        static Scene* activeScene; 
    };
}

#endif