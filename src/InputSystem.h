#ifndef INPUT_H
#define INPUT_H 

#include <SDL2/SDL.h>
#include <map> 

namespace SDLPP {
    class Game; 
    /**
     * Static class that handles Input 
    */
    class InputSystem {
        friend class Game; 
    public: 
        /**
         * Returns 1 if the key represented by code is pressed and 0 otherwise.
         * This simply returns code's value in the keyMap if it is already registered, otherwise
         * it first registers the code into keyMap and returns its value after calling Update() 
         * @param code SDL_Scancode representing a key 
        */
        static int GetKey(SDL_Scancode code);
    private:
        /**
         * Checks for key presses and uses UpdateMap to update pressed key value in keyMap 
         * if it's registered
        */
        static void Update(void); 
        /**
         * Checks if the passed keyboard event's code is registered in keyMap, and updates it value if it is 
         * @param event SDL_KeyboardEvent to process
         * @param value the new value for the key if it exists in the keyMap    
        */
        static void UpdateMap(SDL_KeyboardEvent* event, int value); 
        
        static std::map<SDL_Scancode, int> keyMap; 
    };
}

#endif