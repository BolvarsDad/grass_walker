#ifndef GRASS_WALKER_INCLUDES_EVENT_HANDLER_H_
#define GRASS_WALKER_INCLUDES_EVENT_HANDLER_H_

#include <stdint.h>
#include <SDL2/SDL.h>

void (*keyboard_state)(uint8_t) = SDL_GetKeyboardState;



#endif
