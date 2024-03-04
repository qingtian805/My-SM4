#include "sm4base.h"

//sm4轮密钥生成函数，keys输入密钥，rk输入轮密钥存储区域。
//轮密钥存储区域需要4*32=128字节
void sm4kdf(uint32_t *keys, uint32_t *rk);

//sm4加密函数，在运行前需要运行sm4kdf函数，
void sm4_enc(uint32_t *data_in, uint32_t *data_out, uint32_t *key);

void sm4_dec(uint32_t *data_in, uint32_t *data_out, uint32_t *key);