/* 
 * Copyright (c) 2015, Schmidt
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
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


#include <R.h>
#include <Rinternals.h>
#include "mec.h"

#define CHARPT(x) ((char*)CHAR(STRING_ELT(x,0)))


SEXP R_mec_encode(SEXP instr)
{
  SEXP ret;
  const int len = strlen(CHARPT(instr));
  uchar_t *str = malloc(len * sizeof(*str));
  
  strncpy((char *)str, CHARPT(instr), len);
  
  missy_elliott_crypto(str, len);
  
  ret = PROTECT(allocVector(STRSXP, 1));
  SET_STRING_ELT(ret, 0, mkCharLen((char *)str, len));
  UNPROTECT(1);
  
  free(str);
  
  return ret;
}



SEXP R_mec_decode(SEXP instr)
{
  SEXP ret;
  const int len = strlen(CHARPT(instr));
  uchar_t *str = malloc(len * sizeof(*str));
  
  strncpy((char *)str, CHARPT(instr), len);
  
  missy_elliott_decrypto(str, len);
  
  ret = PROTECT(allocVector(STRSXP, 1));
  SET_STRING_ELT(ret, 0, mkCharLen((char *)str, len));
  UNPROTECT(1);
  
  free(str);
  
  return ret;
}



SEXP R_mec_print(SEXP instr)
{
  const int len = strlen(CHARPT(instr));
  print_bits_of_str((uchar_t *)CHARPT(instr), len);
  
  return R_NilValue;
}


