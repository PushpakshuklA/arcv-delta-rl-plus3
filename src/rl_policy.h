#ifndef RL_POLICY_H
#define RL_POLICY_H

#include <stdint.h>
#include "macro_actions.h"

#define STATE_SPACE 2700
#define ACTION_SPACE 256

void     rl_policy_init(void);
uint8_t  encode_state(uint16_t voxel, uint8_t batt, uint8_t lsi);
uint8_t  rl_policy_select(uint8_t state);
macro_action_t rl_policy_get_macro(uint8_t id);

#endif // RL_POLICY_H
