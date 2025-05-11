#ifndef PJ_FHPC_H
#define PJ_FHPC_H

#include <stdint.h>

// Predictive Jammer-aware Frequency-Hop & Power Control
void    pj_fhpc_init(void);
uint8_t pj_fhpc_update_and_get_lsi(void);
void    pj_fhpc_apply_tx(uint8_t level);

#endif // PJ_FHPC_H
