#ifndef SM4_ROUND_H
#define SM4_ROUND_H

#include <stdint.h>
#include "sm4base.h"

void _sm4_round_(union sm4data *data, int round, union sm4uint32 rk);

#endif