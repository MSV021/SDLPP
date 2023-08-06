#include "Game.h"
#include "InputSystem.h"

#include <stdexcept> 

std::string SDLPP::Game::Title = "Main"; 
bool SDLPP::Game::Fullscreen = false; 
int SDLPP::Game::ScreenWidth = 1280; 
int SDLPP::Game::ScreenHeight = 720; 
SDLPP::ColorRGBA SDLPP::Game::BackgroundColor = SDLPP::ColorRGBA::white;

int SDLPP::Game::windowFlags = 0;
int SDLPP::Game::rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
SDL_Window* SDLPP::Game::window = nullptr;
SDL_Renderer* SDLPP::Game::renderer = nullptr;

std::vector<std::function<void()>> SDLPP::Game::initCallbacks; 
std::vector<std::function<void()>> SDLPP::Game::updateCallbacks; 

bool SDLPP::Game::initialized = false;
bool SDLPP::Game::started = false; 

SDLPP::Scene* SDLPP::Game::activeScene = nullptr;

void SDLPP::Game::Initialize() {
    if(initialized) return; 
    initialized = true; 

    if(Fullscreen) 
        windowFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        throw new std::runtime_error("SDL failed to initialize!"); 
    if(!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) 
        throw new std::runtime_error("SDL_image failed to initialize!");

    window = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenWidth, ScreenHeight, windowFlags);
    if(!window) 
        throw new std::runtime_error("SDL failed to create window!"); 
    renderer = SDL_CreateRenderer(window, -1, rendererFlags);
    if(!renderer) 
        throw new std::runtime_error("SDL failed to create renderer!");

    if(Fullscreen) 
        SDL_GetRendererOutputSize(renderer, &ScreenWidth, &ScreenHeight);

    activeScene = new Scene();

    for(auto callback : initCallbacks) 
        callback();
}

void SDLPP::Game::Update(int rate) {
    static long then; 
    static float remainder;

    if(started) return; 
    started = true; 

    while(1) {
        SDL_SetRenderDrawColor(renderer, BackgroundColor.r, BackgroundColor.g, BackgroundColor.b, BackgroundColor.a); 
        SDL_RenderClear(renderer); 

        for(auto sprite : activeScene->renderingQueue) {
            if(sprite->isVisible)
                sprite->Render();
        }

        for(auto entity : activeScene->entities) 
            entity->UpdateComponents();

        InputSystem::Update();

        for(auto callback : updateCallbacks) 
            callback();

        SDL_RenderPresent(renderer);

        long wait, frameTime;

        wait = 16 + remainder;

        remainder -= (int)remainder;

        frameTime = SDL_GetTicks() - then;

        wait -= frameTime;

        if (wait < 1)
        {
            wait = 1;
        }

        SDL_Delay(wait);

        remainder += 0.667;

        then = SDL_GetTicks();
    }
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

SDL_Texture* SDLPP::Game::LoadTexture(const char* path) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "loading %s", path);
    return IMG_LoadTexture(renderer, path);   
}