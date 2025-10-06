#include "fft_post_comp.h"
#include "cpx_op.h"
#include <math.h>

void scale(double *data, int lenf, double valu){
  int iter;
  for(iter=0; iter<2*lenf; iter++)
    data[iter] /= valu;
}

void nyquist_arrange(double *data, int lenf){
  double temp[2];
  int iter;
  for(iter=0; iter<lenf/2; iter++){
    asn(temp, data+2*iter);
    asn(data+2*iter, data+2*iter+lenf);
    asn(data+2*iter+lenf, temp);
  }
}

void modulus_in_real(double *data, int lenf){
  int iter;
  for(iter=0; iter<lenf; iter++){
    data[2*iter]    = sqrt(data[2*iter]*data[2*iter]+data[2*iter+1]*data[2*iter+1]);
    data[2*iter+1]  = 0.;
  }
}

void log_norm_real(double *data, int lenf, double valu){
  int iter;
  for(iter=0; iter<lenf; iter++){
   data[2*iter] = valu*log(1+data[2*iter]);
  }
}
