#ifndef VEC4_H
#define VEC4_H

#include "fixed_point.h"

typedef struct {
    fixed32_t x, y, h;
    uint8_t   pwr;
} vec4_t;

#endif // VEC4_H
