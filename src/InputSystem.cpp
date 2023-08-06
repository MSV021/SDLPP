#include "InputSystem.h"
#include <algorithm>

std::map<SDL_Scancode, int> SDLPP::InputSystem::keyMap; 
std::vector<void(*)(SDL_Scancode)> SDLPP::InputSystem::keyDownCallbacks;
std::vector<void(*)(SDL_Scancode)> SDLPP::InputSystem::keyUpCallbacks;


int SDLPP::InputSystem::GetKey(SDL_Scancode code) {
    auto iter = keyMap.find(code); 
    if(iter == keyMap.end()) {
        iter = keyMap.insert({code, 0}).first;
        Update();  
    }
    
    return iter->second;    
}

void SDLPP::InputSystem::AddKeyDownCallback(void(*callback)(SDL_Scancode)) {
    keyDownCallbacks.push_back(callback); 
}

void SDLPP::InputSystem::RemoveKeyDownCallback(void(*callback)(SDL_Scancode)) {
    auto iter = std::find(keyDownCallbacks.begin(), keyDownCallbacks.end(), callback); 
    if(iter != keyDownCallbacks.end()) 
        keyDownCallbacks.erase(iter); 
}

void SDLPP::InputSystem::AddKeyUpCallback(void(*callback)(SDL_Scancode)) {
    keyUpCallbacks.push_back(callback); 
}

void SDLPP::InputSystem::RemoveKeyUpCallback(void(*callback)(SDL_Scancode)) {
    auto iter = std::find(keyUpCallbacks.begin(), keyUpCallbacks.end(), callback); 
    if(iter != keyUpCallbacks.end()) 
        keyUpCallbacks.erase(iter); 
}

void SDLPP::InputSystem::UpdateMap(SDL_KeyboardEvent* event, int value) {
    if(!event->repeat) {
        for(auto& key : keyMap) {
            if(event->keysym.scancode == key.first) 
                key.second = value;
        }
    }
}

void SDLPP::InputSystem::Update() {
    SDL_Event event; 

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
        case SDL_QUIT: 
            exit(0); 
            break;
        case SDL_KEYDOWN: 
            for(auto callback : keyDownCallbacks) callback(event.key.keysym.scancode);
            UpdateMap(&event.key, 1); 
            break; 
        case SDL_KEYUP: 
            for(auto callback : keyUpCallbacks) callback(event.key.keysym.scancode);
            UpdateMap(&event.key, 0); 
            break; 
        default: 
            break;
        }
    }
}