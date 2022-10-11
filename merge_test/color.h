#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>

#include "vector3d.h"

#define MAX_COLOR 255

typedef t_vec3 t_color;

// 'spp' is samples per pixel
int Color_fprintln(FILE* stream, const t_color* c);

#endif
