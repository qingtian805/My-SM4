#include "sm4.h"
#include <stdio.h>
#include <unitypes.h>

//sm4基础功能测试，测试sm4没有任何模式下的功能是否正常。
//受限制于程序编写，只能输出最后四个结果，即X[28-31]
//X28 = 536e4246
//X29 = 86b3e94f
//X30 = d206965e
//X31 = 681edf34

int main(void)
{
    uint32_t key[4] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    uint32_t data[4] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    int i;

    uint32_t data_out[4];

    sm4_enc(data, data_out, key);

    for(i = 0; i < 4; i++){
        printf("X%d = %x\n",i + 28 , data_out[i]);
    }

    return 0;
}