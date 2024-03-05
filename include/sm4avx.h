#include <unitypes.h>
#ifndef SM4_AVX
#define SM4_AVX

//应用avx2的sm4加密函数，同时处理8道数据。即一次处理32个uint32_t
void sm4_enc(uint32_t *data_in, uint32_t *data_out, uint32_t *rk);

//应用avx2的sm4解密函数，同时处理8道数据。即一次处理32个uint32_t
void sm4_dec(uint32_t *data_in, uint32_t *data_out, uint32_t *rk);

//sm4kdf函数需要32个uint32_t存储轮密钥rk
void sm4kdf(uint32_t *keys, uint32_t *rk);

#endif