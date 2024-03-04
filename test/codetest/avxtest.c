#include <immintrin.h>
#include <unitypes.h>
#include <stdio.h>

int main(void)
{
    __m256i a, b;
    uint32_t beload[8] = {0x00010203, 0x04050607, 0x08090A0B, 0x0C0D0E0F, 0x10111213, 0x14151617, 0x18191A1B, 0x1C1D1E1F};
    int i;

    a = _mm256_loadu_si256((__m256i*)beload);

    b = _mm256_set_epi32(1,2,3,4,5,6,7,8);

    b = _mm256_xor_si256(a,b);

    //_mm256_store_si256((void *)beload, b);

    for(i = 0; i < 8; i++){
        printf("%x ", b[i]);
    }
    printf("\n");

    return 0;
}