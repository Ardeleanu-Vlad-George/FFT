#include "cpx_op.h"

long double* tms(long double* trgt, long double* src1, long double* src2){
  trgt[0]=src1[0]*src2[0]-src1[1]*src2[1];
  trgt[1]=src1[1]*src2[0]+src1[0]*src2[1];
  return trgt;
}

long double* add(long double* trgt, long double* src1, long double* src2){
  trgt[0]=src1[0]+src2[0];
  trgt[1]=src1[1]+src2[1];
  return trgt;
}

long double* asn(long double* trgt, long double* src){
  trgt[0]=src[0]; trgt[1]=src[1];
  return trgt;
}
