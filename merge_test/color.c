#include <math.h>
#include <stdio.h>
#include <util.h>

#include "color.h"

// 'spp' is samples per pixel
int Color_fprintln(FILE* stream, const t_color* c) {
    // divide color by sample size
    double scale = 1.0;
    double r = sqrt(c->x * scale);
    double g = sqrt(c->y * scale);
    double b = sqrt(c->z * scale);

    return fprintf(stream, "%i %i %i\n", 
                   (int)(256 * clamp(r, 0, 0.999)),
                   (int)(256 * clamp(g, 0, 0.999)),
                   (int)(256 * clamp(b, 0, 0.999))
           );
}
