#define __SM4_KDF_TEST_

#include <stdio.h>
#include "sm4kdf.h"

//预期输出: 428d3654622934961cf72e59124a012
//说明:这段数据是rk第28-31,中间缺一个0

int main(void)
{
    union sm4data key = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};

    printf("%x%x%x%x\n",key.u32[0], key.u32[1], key.u32[2], key.u32[3]);

    key = sm4kdf(key);

    printf("%x%x%x%x\n",key.u32[0], key.u32[1], key.u32[2], key.u32[3]);

    return 0;
}