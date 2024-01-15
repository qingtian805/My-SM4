/* sm4base.h
   my-sm4基础库，包含一些基本操作的实现 */

#ifndef SM4_BASE
#define SM4_BASE

#include <stdint.h>

//sm4封装的uint32类型方便进行分割
union sm4uint32{
    uint32_t u32;
    uint8_t u8[4];
};

//sm4基本数据类型,方便进行各种步骤的分割
union sm4data{
    uint32_t u32[4];
    union sm4uint32 sm4u32[4];
};

//sbox函数
uint8_t sbox(uint8_t data);

//对x86汇编ror循环左移指令的封装
inline uint32_t _sm4_asm_rol_(uint32_t data, uint32_t bits)
{
    asm ("rol %1, %0;\n\t"
    : "+a" (data)
    : "cI" (bits));

    return data;
}

#endif