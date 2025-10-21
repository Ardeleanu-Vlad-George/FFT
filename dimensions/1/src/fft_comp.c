#include "fft_comp.h"
#include "fft_prep_bit.h"
#include "fft_prep_cpx_fn.h"
#include "cpx_op.h"
#include "btr_fly.h"

void fft_order(int nr, int pwr, double *vct){
  int it; double buff[2*nr];

  for(it=0; it < nr; it++)
    asn(buff+2*it, vct+2*it);

  for(it=0; it < nr; it++)
    asn(vct+2*it, buff+2*revidx(it, pwr));
}

void fft_apply(int nr, int pwr, double *vct, double *rts){
  double *seqn_pair, *vect_stop;
  vect_stop = vct+2*nr;
  int seqn_lenf, layer_cnt, powr_step; 

  for(
    layer_cnt=0, seqn_lenf=1, powr_step=nr/2;
    layer_cnt < pwr;
    layer_cnt++, seqn_lenf*=2, powr_step/=2
  )for(seqn_pair=vct; seqn_pair < vect_stop; seqn_pair+=4*seqn_lenf)
    comp_seqn(seqn_lenf, seqn_pair, 1, seqn_pair+2*seqn_lenf, 1, rts, powr_step, rts+2*seqn_lenf*powr_step, powr_step);
}
