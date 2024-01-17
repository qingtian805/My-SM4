#include "sm4.h"
#include "sm4round.h"
#include "sm4kdf.h"

union sm4data sm4(union sm4data data, union sm4data key)
{
    int i;

    _sm4kdf_xorfx_(&key);

    for(i = 0; i < 32; i++){
        _sm4_round_(&data, i, sm4kdf(&key, i));
    }

    return data;
}