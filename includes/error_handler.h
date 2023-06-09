#ifndef GRASS_WALKER_INCLUDES_ERROR_HANDLER_H_
#define GRASS_WALKER_INCLUDES_ERROR_HANDLER_H_

#include <SDL2/SDL.h>

enum sdl_err_codes {
    SDLERR_OK,
    SDLERR_WINDOW,
    SDLERR_SURFACE,
    SDLERR_IMAGE,
    SDLERR_END
};

static char const *sdl_err_codes_str[SDLERR_END] = {
    "Ok",
    "Unable to initialize SDL Window",
    "Unable to initialize SDL Surface",
    "Unable to initialize SDL Bitmap Image",
};

enum sdl_err_codes validate_sdl_components(SDL_Window   *window,
                                           SDL_Surface  *surface,
                                           SDL_Surface  *image);

#endif
