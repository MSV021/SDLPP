#include "Game.h"
#include "InputSystem.h"

#include <stdexcept> 

std::string SDLPP::Game::title = "Main"; 
int SDLPP::Game::screenWidth = 1280; 
int SDLPP::Game::screenHeight = 720; 
SDLPP::ColorRGBA SDLPP::Game::backgroundColor = SDLPP::ColorRGBA::white;
std::vector<std::function<void()>> SDLPP::Game::initCallbacks; 
std::vector<std::function<void()>> SDLPP::Game::updateCallbacks; 
SDLPP::Scene* SDLPP::Game::activeScene = nullptr;

void SDLPP::Game::Initialize(int windowFlags, int rendererFlags) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        throw new std::runtime_error("SDL failed to initialize!"); 
    if(!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) 
        throw new std::runtime_error("SDL_image failed to initialize!");

    SDL_Window* window = SDLPP::CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, windowFlags);
    SDL_Renderer* renderer = SDLPP::CreateRenderer(window, -1, rendererFlags);
    activeScene = new Scene(window, renderer);

    updateCallbacks.push_back(InputSystem::Update); 
    for(auto callback : initCallbacks) 
        callback();
}

void SDLPP::Game::Update(int rate) {
    while(1) {
        SDL_SetRenderDrawColor(activeScene->renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a); 
        SDL_RenderClear(activeScene->renderer); 

        for(auto callback : updateCallbacks) 
            callback();

        SDL_RenderPresent(activeScene->renderer);
        SDL_Delay(1000/rate);
    }
}

void SDLPP::Game::SetTitle(const char* title) {
    Game::title = std::string(title);
}

void SDLPP::Game::SetScreenDimensions(int width, int height) {
    screenWidth = width; 
    screenHeight = height;
}

void SDLPP::Game::SetBackgroundColor(ColorRGBA color) {
    backgroundColor = color;
}

void SDLPP::Game::AddInitCallback(std::function<void()> callback) { 
    initCallbacks.push_back(callback);
}

void SDLPP::Game::AddUpdateCallback(std::function<void()> callback) { 
    updateCallbacks.push_back(callback);
}

SDLPP::Scene* SDLPP::Game::GetActiveScene() {
    return activeScene; 
}