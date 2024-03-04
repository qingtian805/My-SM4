#include "sm4.h"
#include "sm4kdf.h"
#include "sm4base.h"

void sm4_enc(uint32_t *data_in, uint32_t *data_out, uint32_t *rk)
{
    int i;
    union sm4uint32 d[4];
    union sm4uint32 xor;

    d[0].u32 = data_in[0];
    d[1].u32 = data_in[1];
    d[2].u32 = data_in[2];
    d[3].u32 = data_in[3];

    for(i = 0; i < 32; i += 4){
        xor.u32 = d[1].u32 ^ d[2].u32 ^ d[3].u32 ^ rk[i    ];
        d[0].u32 ^= sm4_t(xor);

        xor.u32 = d[2].u32 ^ d[3].u32 ^ d[0].u32 ^ rk[i + 1];
        d[1].u32 ^= sm4_t(xor);

        xor.u32 = d[3].u32 ^ d[0].u32 ^ d[1].u32 ^ rk[i + 2];
        d[2].u32 ^= sm4_t(xor);

        xor.u32 = d[0].u32 ^ d[1].u32 ^ d[2].u32 ^ rk[i + 3];
        d[3].u32 ^= sm4_t(xor);
    }
    data_out[0] = d[0].u32;
    data_out[1] = d[1].u32;
    data_out[2] = d[2].u32;
    data_out[3] = d[3].u32;
}

void sm4_dec(uint32_t *data_in, uint32_t *data_out, uint32_t *key)
{

}