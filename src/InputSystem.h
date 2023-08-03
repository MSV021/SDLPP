#ifndef INPUT_H
#define INPUT_H 

#include <SDL2/SDL.h>
#include <map> 

namespace SDLPP {
    class InputSystem {
    public: 
        static void Update(void); 
        static int GetKey(SDL_Scancode);
    private:
        static void UpdateMap(SDL_KeyboardEvent*, int); 
        
        static std::map<SDL_Scancode, int> keyMap; 
    };
}

#endif