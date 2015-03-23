#include <R.h>
#include <Rinternals.h>

#define CHARPT(x) ((char*)CHAR(STRING_ELT(x,0)))

typedef unsigned char uchar_t;

SEXP R_mec_encode(SEXP instr)
{
  SEXP ret;
  const int len = strlen(CHARPT(instr));
  uchar_t *str = malloc(len * sizeof(*str));
  
  strncpy(str, CHARPT(instr), len);
  
  missy_elliott_crypto(str, len);
  
  ret = PROTECT(allocVector(STRSXP, 1));
  SET_STRING_ELT(ret, 0, mkCharLen(str, len));
  UNPROTECT(1);
  
  free(str);
  
  return ret;
}



SEXP R_mec_decode(SEXP instr)
{
  SEXP ret;
  const int len = strlen(CHARPT(instr));
  uchar_t *str = malloc(len * sizeof(*str));
  
  strncpy(str, CHARPT(instr), len);
  
  missy_elliott_decrypto(str, len);
  
  ret = PROTECT(allocVector(STRSXP, 1));
  SET_STRING_ELT(ret, 0, mkCharLen(str, len));
  UNPROTECT(1);
  
  free(str);
  
  return ret;
}



SEXP R_mec_print(SEXP instr)
{
  const int len = strlen(CHARPT(instr));
  print_bits_of_str(CHARPT(instr), len);
  
  return R_NilValue;
}


