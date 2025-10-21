#include "io.h"
#include "fft_comp.h"
#include "fft_prep_cpx_fn.h"
#include "fft_prep_bit.h"
/*#include "fft_post_comp.h"*/
#include "fft_prep_cpx_nr.h"
#include <stdlib.h>
#include <math.h>

int main(){
  int LEN, PWR;
  double *VCT, *RTS, LOG_SCALER;
  
  VCT = read("data/in", &LEN);
  PWR = getexp(LEN);
  RTS = every_rou(LEN);

  fft_order(LEN, PWR, VCT);
  fft_apply(LEN, PWR, VCT, RTS);

  /*modulus_in_real(VCT, LEN);*/
  /**/
  /*LOG_SCALER = TARGET_VALUE/log(1+VCT[0]);//access the real part of the nyquist*/
  /**/
  /*nyquist_arrange(VCT, LEN);*/
  /**/
  /*log_norm_real(VCT, LEN, LOG_SCALER);*/
  
  write("data/out", LEN, VCT);

  free(VCT);
  free(RTS);
  return 0;
}
