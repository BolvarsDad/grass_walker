#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <SDL2/SDL.h>

#include "../includes/event_handler.h"
#include "../includes/error_handler.h"

#define WINWIDTH 1920
#define WINLEN   1080

int
main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Unable to initialize SDL Video Instance");
        return 1;
    }

    bool win_sentinel = false;
    SDL_Event event;
    const uint8_t *keyboard_state = SDL_GetKeyboardState(NULL);
 
    SDL_Window  *window  = SDL_CreateWindow("Grass walker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINWIDTH, WINLEN, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Surface *image   = SDL_LoadBMP("../resources/textures/thing.bmp");

    enum sdl_err_codes res = validate_sdl_components(window, surface, image);
    if (res != SDLERR_OK)
    {
        printf("%s\n", sdl_err_codes_str[res]);
        return 1;
    }

    while (!win_sentinel && SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                win_sentinel = true;
                break;

            case SDL_KEYDOWN:
                // TODO: Implement actual function pointer lookup for keypress handler.
                // Currently does jack shit
                win_sentinel = true;
                break;
        }

        SDL_BlitSurface(image, NULL, surface, NULL);
        SDL_UpdateWindowSurface(window);
    }

    return 0;
}
