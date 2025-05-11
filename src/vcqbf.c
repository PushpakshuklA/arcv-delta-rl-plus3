#include "vcqbf.h"

void vcqbf_init(void) {
    // Set NFZs, R_min, battery threshold, etc.
}

vec4_t vcqbf_project(const vec2_t *pos, const vec4_t *desired) {
    // 1) Compute centroid drift vector
    // 2) Subtract k_j * ∇LSI gradient
    // 3) Project via closed-form QP onto h_i ≥ 0
    // (Stub: return desired)
    return *desired;
}
