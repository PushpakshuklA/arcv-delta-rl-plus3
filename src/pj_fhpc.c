#include "pj_fhpc.h"

void pj_fhpc_init(void) {
    // Initialize jammer predictor state
}

uint8_t pj_fhpc_update_and_get_lsi(void) {
    // Update Markov predictor, return 0–2 bins
    return 0;
}

void pj_fhpc_apply_tx(uint8_t level) {
    // Hook into radio driver to set Tx power
}
