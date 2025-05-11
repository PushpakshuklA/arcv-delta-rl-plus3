#include "rl_policy.h"

// Static Q-table: one byte per state (greedy action)
static uint8_t qtable[STATE_SPACE] = { /* ... loaded from flash ... */ };

void rl_policy_init(void) {
    // If compressed, decompress here; else NOP
}

uint8_t encode_state(uint16_t voxel, uint8_t batt, uint8_t lsi) {
    return (uint8_t)(((uint32_t)voxel * 3 + batt) * 3 + lsi);
}

uint8_t rl_policy_select(uint8_t state) {
    if (state < STATE_SPACE) return qtable[state];
    return 0;
}

macro_action_t rl_policy_get_macro(uint8_t id) {
    return MACRO_ACTIONS[id];
}
