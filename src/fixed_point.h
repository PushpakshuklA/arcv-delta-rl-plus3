#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

typedef int32_t fixed32_t; // Q16.16

static inline fixed32_t to_fixed(float f)  { return (fixed32_t)(f * 65536.0f); }
static inline float     to_float(fixed32_t x) { return ((float)x) / 65536.0f; }

static inline fixed32_t fixed_mul(fixed32_t a, fixed32_t b) {
    return (fixed32_t)(((int64_t)a * b) >> 16);
}

#endif // FIXED_POINT_H
