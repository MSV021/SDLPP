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
    */
    class Game {
    public: 
        /**
         * Initializes SDLPP and creates a new Scene with specified window and renderer flags.
         * Assigns the scene as the active scene. Calls InitCallbacks. 
         * @param windowFlags SDL_WindowFlags used to create game's main window
         * @param rendererFlags SDL_RendererFlags used to create game's main renderer 
        */
        static void Initialize(int windowFlags, int rendererFlags);
        /**
         * Starts SDLPP main loop with a specified framerate. Calls UpdateCallbacks.
         * @param rate main loop's framerate
        */
        static void Update(int rate); 

        /**
         * Registers a function to be called at SDLPP initialization with Game::Initialize. Use this to set up your Entities and 
         * Components. 
         * @param callback function to be registered 
        */
        static void AddInitCallback(std::function<void()> callback); 
        /** 
         * Registers a function to be called every frame after Game::Update is called.
         * @param callback function to be registered
        */
        static void AddUpdateCallback(std::function<void()> callback); 
        
        /**
         * Returns current active scene which is rendered on screen. 
        */
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