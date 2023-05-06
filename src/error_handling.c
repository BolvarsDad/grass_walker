#include <stdio.h>

#include "../includes/error_handling.h"

enum err_codes
validate_sdl_components(SDL_Window *window, SDL_Surface *surface, SDL_Surface *image)
{
    if (window == NULL)
        return SDLERR_WINDOW;

    if (surface == NULL)
        return SDLERR_SURFACE;

    if (image == NULL)
        return SDLERR_IMAGE;

    return SDLERR_OK;
}
