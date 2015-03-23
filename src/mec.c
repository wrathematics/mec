/* 
 * Copyright (c) 2015, Schmidt
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer. 
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice, 
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// https://github.com/tom-lord/missy_elliott

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


#define PRINTFUN Rprintf


static inline void shift_yo_bits_down(unsigned char *arr, uint32_t len)
{
  int i;
  
  for (i=0; i<len; i++)
    arr[i] <<= 1;
}



static inline void shift_yo_bits_up(unsigned char *arr, uint32_t len)
{
  int i;
  
  for (i=0; i<len; i++)
    arr[i] >>= 1;
}



static inline void flip_it(unsigned char *arr, uint32_t len)
{
  int c;
  
  for (c=0; c<len; c++)
    arr[c] = ~arr[c];
}



static void and_reverse_it(unsigned char *arr, uint32_t len)
{
  uint32_t rev;
  int c, bit;
  
  for (c=0; c<len; c++)
  {
    rev = 0;
    for (bit=0; bit<8; bit++)
    {
      if ((arr[c] & (1 << bit)))
        rev |= 1 << (8 - 1 - bit);
    }
    
    arr[c] = rev;
  }
}



void missy_elliott_crypto(unsigned char *str, int len)
{
  shift_yo_bits_down(str, len);
  flip_it(str, len);
  and_reverse_it(str, len);
}



void missy_elliott_decrypto(unsigned char *str, uint32_t len)
{
  and_reverse_it(str, len);
  flip_it(str, len);
  shift_yo_bits_up(str, len);
}



void print_bits_of_str(unsigned char *str, uint32_t len)
{
  int c, bit;
  
  for (c=0; c<len; c++)
  {
    for (bit=0; bit<8; bit++)
      PRINTFUN("%d", !!((str[c] << bit) & 0x80));
    
    PRINTFUN("\n");
  }
}


/*
int main()
{
  char *str_literal = "asdf qwerty";
  uint32_t len = strlen(str_literal);
  unsigned char *str;
  
  str = malloc(len);
  
  // input
  strncpy(str, str_literal, len);
  PRINTFUN("%s\n", str);
  
  // encoded
  missy_elliott_crypto(str, len);
  PRINTFUN("%s\n", str);
  
  // decoded
  missy_elliott_decrypto(str, len);
  PRINTFUN("%s\n", str);
  
  free(str);
  
  return 0;
}
*/


