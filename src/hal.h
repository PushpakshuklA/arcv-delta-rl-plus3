#ifndef HAL_H
#define HAL_H

#include <stdint.h>
#include "fixed_point.h"
#include "vec2.h"

// Number of anchors used by IA-FHT
#define NUM_ANCHORS 4

// Hardware Abstraction Layer (stubs)
void hal_init(void);
void hal_read_rssi(fixed32_t rssi[NUM_ANCHORS]);
void hal_read_tdoa(fixed32_t tdoa[NUM_ANCHORS][NUM_ANCHORS]);
void hal_read_aoa(fixed32_t aoa[NUM_ANCHORS]);
uint16_t hal_compute_voxel(vec2_t pos);
uint8_t  hal_compute_battery_bin(uint16_t battery_mv);
uint16_t hal_read_battery(void);
void     hal_move_uav(fixed32_t dx, fixed32_t dy, fixed32_t dh);
void     hal_delay_ms(uint32_t ms);

#endif // HAL_H
