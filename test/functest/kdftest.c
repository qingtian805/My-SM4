#define __SM4_KDF_TEST_

#include <stdio.h>
#include "sm4kdf.h"

//预期输出: 
//说明:这段数据是rk第28-31,中间缺一个0

int main(void)
{
    union sm4data key = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    union sm4uint32 rk;
    int i;

    _sm4kdf_xorfx_(&key);

    for(i = 0; i < 32; i++){
        rk = sm4kdf(&key, i);
        printf("rk%2d = %x\n",i , rk.u32);
    }

    return 0;
}