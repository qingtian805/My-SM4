#include <stdint.h>
#include <stdio.h>
#include "sm4base.h"

//测试基础函数的结果是否正常
//预期输出 ：7 e

int main(void)
{
    uint32_t a = 0x07;

    printf("%x", a);

    a = _sm4_asm_rol_(a, 1);
    
    printf(" %x\n", a);
    return 0;
}