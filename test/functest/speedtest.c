#include "sm4.h"
#include <time.h>
#include <stdio.h>

int main(void)
{
    clock_t start, end;
    double gbps;
    int i;
    uint32_t key[4] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    uint32_t data[4] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    uint32_t data_out[4];

    start = clock();
    
    for(i = 0; i < 8388608; i++)
        sm4_enc(data, data_out, key);

    end = clock();

    start = end - start;
    gbps = (double)start / (double)CLOCKS_PER_SEC;

    printf("%ld\n", start);
    
    printf("%f\n", gbps);

    return 0;
}