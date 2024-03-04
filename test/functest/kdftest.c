#define __SM4_KDF_TEST_

#include <stdio.h>
#include "sm4kdf.h"


//预期输出: 
//说明:这段数据是rk第28-31,中间缺一个0

int main(void)
{
    uint32_t key[4] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    uint32_t rk[32];
    int i;

    sm4kdf(key, rk);

    for(i = 0; i < 32; i++){
        printf("rk%d = %x\n", i, rk[i]);
    }

    return 0;
}