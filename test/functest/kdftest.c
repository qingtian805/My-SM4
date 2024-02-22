#define __SM4_KDF_TEST_

#include <stdio.h>
#include "sm4kdf.h"

//预期输出: 
//说明:这段数据是rk第28-31,中间缺一个0

int main(void)
{
    union sm4uint32 key[4] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    union sm4uint32 rk[32];
    int i;

    sm4kdf(key, rk);

    for(i = 0; i < 32; i++){
        printf("rk%d = %x\n", i, rk[i].u32);
    }

    return 0;
}