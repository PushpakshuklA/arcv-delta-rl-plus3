#include "hal.h"

void hal_init(void) {
    // Initialize clocks, peripherals, radio, etc.
}

void hal_read_rssi(fixed32_t rssi[NUM_ANCHORS]) {
    for (int i = 0; i < NUM_ANCHORS; i++) {
        rssi[i] = to_fixed(-50.0f);  // Dummy placeholder
    }
}

void hal_read_tdoa(fixed32_t tdoa[NUM_ANCHORS][NUM_ANCHORS]) {
    for (int i = 0; i < NUM_ANCHORS; i++)
        for (int j = 0; j < NUM_ANCHORS; j++)
            tdoa[i][j] = to_fixed(0.0f);
}

void hal_read_aoa(fixed32_t aoa[NUM_ANCHORS]) {
    for (int i = 0; i < NUM_ANCHORS; i++) {
        aoa[i] = to_fixed(0.0f);
    }
}

uint16_t hal_compute_voxel(vec2_t pos) {
    // Map (x,y) to a grid index
    return 0;
}

uint8_t hal_compute_battery_bin(uint16_t battery_mv) {
    // Simple thresholds into 3 bins
    return (battery_mv > 3700) ? 2 : (battery_mv > 3400 ? 1 : 0);
}

uint16_t hal_read_battery(void) {
    return 3700;  // Dummy
}

void hal_move_uav(fixed32_t dx, fixed32_t dy, fixed32_t dh) {
    // Send commands to flight controller
}

void hal_delay_ms(uint32_t ms) {
    // Busy-wait or timer delay
}
