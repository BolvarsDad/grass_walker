#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <SDL2/SDL.h>

#include "../includes/key_handler.h"

#define WINWIDTH 680
#define WINLEN   480

int
main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Unable to initialize SDL");
        return 1;
    }

    bool win_sentinel = false;
    const uint8_t *keyboard_state = SDL_GetKeyboardState(NULL);
 
    SDL_Window  *window  = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINWIDTH, WINLEN, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Surface *image   = SDL_LoadBMP("../resources/textures/thing.bmp");

    enum sdl_err_codes res = validate_sdl_components(window, surface, image);
    if (res != SDLERR_OK)
    {
        printf("%s\n", sdl_err_codes_str[res]);
        return 1;
    }

    while (!win_sentinel)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event) > 0)
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            win_sentinel = true;
                            break;
                    }
                break;
            }

        SDL_BlitSurface(image, NULL, surface, NULL);
        SDL_UpdateWindowSurface(window);
    }

    return 0;
}
