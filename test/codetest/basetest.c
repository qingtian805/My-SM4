#include <stdint.h>
#include <stdio.h>
#include "sm4base.h"

//测试基础函数的结果是否正常
//预期输出 ：7 e

int main(void)
{
    uint32_t a = 0x07;
    union sm4uint32 b;

    b.u32 = 0x01020304;

    printf("左移测试,预期输出:7 e\n");
    printf("%x", a);

    a = _sm4_asm_rol_(a, 1);
    
    printf(" %x\n", a);
    
    printf("联合类型测试\n");
    printf("%d %d %d %d\n", b.u8[0], b.u8[1], b.u8[2], b.u8[3]);

    return 0;
}