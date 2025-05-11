#ifndef IA_FHT_H
#define IA_FHT_H

#include "fixed_point.h"
#include "vec2.h"

#define NUM_ANCHORS 4

// Interference-Aware Fusioned Hyperbolic Trilateration
void ia_fht_init(void);
void ia_fht_localize(
    const fixed32_t rssi[NUM_ANCHORS],
    const fixed32_t tdoa[NUM_ANCHORS][NUM_ANCHORS],
    const fixed32_t aoa[NUM_ANCHORS],
    vec2_t *pos_out
);

#endif // IA_FHT_H
