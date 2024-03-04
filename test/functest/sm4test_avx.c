#include "sm4avx.h"
#include <unitypes.h>
#include <stdio.h>

//sm4基础功能测试，测试sm4没有任何模式下的功能是否正常。
//受限制于程序编写，只能输出最后四个结果，即X[28-31]
//X28 = 536e4246
//X29 = 86b3e94f
//X30 = d206965e
//X31 = 681edf34

int main(void)
{
    uint32_t key[4] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    uint32_t data[32] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210,\
                         0x05234567, 0x59ABCDEF, 0x5EDCBA98, 0x56543210,\
                         0x05234567, 0x59ABCDEF, 0x5EDCBA98, 0x56543210,\
                         0x05234567, 0x59ABCDEF, 0x5EDCBA98, 0x56543210,\
                         0x05234567, 0x59ABCDEF, 0x5EDCBA98, 0x56543210,\
                         0x05234567, 0x59ABCDEF, 0x5EDCBA98, 0x56543210,\
                         0x05234567, 0x59ABCDEF, 0x5EDCBA98, 0x56543210,\
                         0x05234567, 0x59ABCDEF, 0x5EDCBA98, 0x56543210};
    uint32_t data_out[32];
    uint32_t rk[32];
    int i;
    
    sm4kdf(key, rk);

    sm4_enc(data, data_out, rk);

    for(i = 0; i < 4; i++){
        printf("X%d = %x\n",i + 28 , data_out[i]);
    }
    printf("----Printing All Data in data_out----\n");
    for(i = 0; i < 32; i++)
        printf("X%d = %x\n",i , data_out[i]);
        
    return 0;
    
    
}