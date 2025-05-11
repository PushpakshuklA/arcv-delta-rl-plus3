#include <stdint.h>
#include "hal.h"
#include "ia_fht.h"
#include "rl_policy.h"
#include "vcqbf.h"
#include "pj_fhpc.h"
#include "macro_actions.h"
#include "vec4.h"

#define TICK_PERIOD_MS 500

int main(void) {
    hal_init();
    ia_fht_init();
    rl_policy_init();
    vcqbf_init();
    pj_fhpc_init();

    while (1) {
        fixed32_t rssi[NUM_ANCHORS];
        fixed32_t tdoa[NUM_ANCHORS][NUM_ANCHORS];
        fixed32_t aoa[NUM_ANCHORS];
        uint8_t   lsi = pj_fhpc_update_and_get_lsi();

        hal_read_rssi(rssi);
        hal_read_tdoa(tdoa);
        hal_read_aoa(aoa);

        vec2_t user_pos;
        ia_fht_localize(rssi, tdoa, aoa, &user_pos);

        uint16_t voxel   = hal_compute_voxel(user_pos);
        uint8_t  batt    = hal_compute_battery_bin(hal_read_battery());
        uint8_t  state   = encode_state(voxel, batt, lsi);

        uint8_t macro_id = rl_policy_select(state);
        macro_action_t action = rl_policy_get_macro(macro_id);

        vec4_t desired = { action.x, action.y, action.h, action.pwr };
        vec4_t safe    = vcqbf_project(&user_pos, &desired);

        hal_move_uav(safe.x, safe.y, safe.h);
        pj_fhpc_apply_tx(safe.pwr);

        hal_delay_ms(TICK_PERIOD_MS);
    }
    return 0;
}
