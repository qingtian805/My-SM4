/* sm4base.h
   my-sm4基础库，包含一些基本操作的实现 */

#ifndef SM4_BASE
#define SM4_BASE

#include <stdint.h>

//sm4封装的uint32类型方便进行分割
//
union sm4uint32{
    uint32_t u32;
    uint8_t u8[4];
};

extern const uint8_t _SM4_SBOX_[256];
extern const uint32_t _SM4_SBOX_T0_[256];
extern const uint32_t _SM4_SBOX_T1_[256];
extern const uint32_t _SM4_SBOX_T2_[256];
extern const uint32_t _SM4_SBOX_T3_[256];

//sbox函数
inline uint8_t sbox(uint8_t data){
    return _SM4_SBOX_[data];
}

//对x86汇编ror循环左移指令的封装
inline uint32_t _sm4_asm_rol_(uint32_t data, uint32_t bits)
{
    asm ("rol %1, %0;\n\t"
    : "+r" (data)
    : "cI" (bits));

    return data;
}

inline uint32_t sm4_t(union sm4uint32 data)
{
    return _SM4_SBOX_T0_[data.u8[0]] ^ _SM4_SBOX_T1_[data.u8[1]] ^ \
            _SM4_SBOX_T2_[data.u8[2]] ^ _SM4_SBOX_T3_[data.u8[3]];
}

#endif