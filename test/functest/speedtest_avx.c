#include "sm4avx.h"
#include "unitypes.h"
#include <time.h>
#include <stdio.h>

int main(void)
{
    clock_t start, end;
    double gbps;
    int i;
    uint32_t key[4] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    uint32_t counter[32] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x0,\
                            0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x1,\
                            0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x2,\
                            0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x3,\
                            0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x4,\
                            0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x5,\
                            0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x6,\
                            0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x7};
    uint32_t data[32] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210,\
                         0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210,\
                         0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210,\
                         0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210,\
                         0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210,\
                         0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210,\
                         0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210,\
                         0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    uint32_t data_out[32];
    uint32_t rk[32];

    start = clock();

    sm4kdf(key, rk);
    
    for(i = 0; i < 1048576; i++)
        sm4_enc(counter, data_out, rk);
        counter[3]++;
        counter[7]++;
        counter[11]++;
        counter[15]++;
        counter[19]++;
        counter[23]++;
        counter[27]++;
        counter[31]++;

    end = clock();

    start = end - start;
    gbps = (double)start / (double)CLOCKS_PER_SEC;

    printf("%ld\n", start);
    
    printf("%f\n", gbps);

    return 0;
}