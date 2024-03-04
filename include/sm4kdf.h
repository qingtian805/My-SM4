#include "sm4base.h"
#include <stdint.h>

//sm4轮密钥生成函数，keys输入密钥，rk输入轮密钥存储区域。
//轮密钥存储区域需要4*32=128字节
void sm4kdf(uint32_t *keys, uint32_t *rk);