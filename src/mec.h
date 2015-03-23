#ifndef MEC_H_
#define MEC_H_


#include <stdint.h>

typedef unsigned char uchar_t;

void missy_elliott_crypto(uchar_t *str, int len);
void missy_elliott_decrypto(uchar_t *str, uint32_t len);
void print_bits_of_str(uchar_t *str, uint32_t len);


#endif
