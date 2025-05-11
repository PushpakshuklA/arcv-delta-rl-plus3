#ifndef MACRO_ACTIONS_H
#define MACRO_ACTIONS_H

#include "vec4.h"

typedef struct {
    fixed32_t x, y, h;
    uint8_t   pwr;
} macro_action_t;

// Pre-computed macro-actions (256 entries)
extern const macro_action_t MACRO_ACTIONS[256];

#endif // MACRO_ACTIONS_H
