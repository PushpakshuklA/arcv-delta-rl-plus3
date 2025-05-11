#include "ia_fht.h"
#include <math.h>

void ia_fht_init(void) {
    // Pre-compute anchor geometry, thresholds, etc.
}

void ia_fht_localize(
    const fixed32_t rssi[NUM_ANCHORS],
    const fixed32_t tdoa[NUM_ANCHORS][NUM_ANCHORS],
    const fixed32_t aoa[NUM_ANCHORS],
    vec2_t *pos_out
) {
    // 1) Vet anchors by LSI & RSSI outliers
    // 2) Solve 3-anchor RSSI WLS (closed-form)
    // 3) Solve TDOA hyperbola (Cayley-Menger)
    // 4) BLUE fusion of two estimates
    // (Full implementation omitted for brevity)
    pos_out->x = to_fixed(0.0f);
    pos_out->y = to_fixed(0.0f);
}
