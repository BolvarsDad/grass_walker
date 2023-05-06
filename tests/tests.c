#include <stdio.h>

int
test_sdl_err_codes_str(void)
{
    for (int i = 0; i < SDLERR_END; ++i)
    {
        char const *selstr = sdl_err_codes_str[i];

        if (selstr == NULL)
            return 0;
        else
            puts(selstr);
    }

    return 1;
}
