#include "sm4.h"
#include <time.h>
#include <stdio.h>

int main(void)
{
    clock_t start, end;
    double gbps;
    int i;
    union sm4data key = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    union sm4data data = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};

    start = clock();
    
    for(i = 0; i < 8388608; i++)
        sm4(data, key);

    end = clock();

    start = end - start;
    gbps = (double)start / (double)CLOCKS_PER_SEC;

    printf("%ld\n", start);
    
    printf("%f\n", gbps);

    return 0;
}