#include "fft_post_comp.hpp"
#include <math.h>
#include "cpx_op.hpp"

void scale(long double *data, int size, long double valu){
  int iter;
  for(iter=0; iter<6*size*size; iter++)
    data[iter] /= valu;
}

void nyquist_arrange_one(int type, long double *data, int size){
  long double temp[2];
  int iter;
  for(iter=0; iter<size/2; iter++){
    asn(temp, data+6*iter*(type?size:1));
    asn(data+6*iter*(type?size:1), data+(6*iter+3*size)*(type?size:1));
    asn(data+(6*iter+3*size)*(type?size:1), temp);
  }
}

void nyquist_arrange_rgb(int comp, long double *data, int size){
  int iter;
  data+=2*comp;

  for(iter=0; iter<size; iter++)
    nyquist_arrange_one(0, data+6*iter*size, size);

  for(iter=0; iter<size; iter++)
    nyquist_arrange_one(1, data+6*iter, size);
}

void nyquist_arrange(long double *data, int size){
  nyquist_arrange_rgb(0, data, size);
  nyquist_arrange_rgb(1, data, size);
  nyquist_arrange_rgb(2, data, size);
}

void set_max_vals(long double *data, int size, long double *vals){
  vals[0] = data[0];
  vals[1] = data[2];
  vals[2] = data[4];
}

void const_from_max(long double target, long double *vals){
  vals[0] = target/log(1+vals[0]);
  vals[1] = target/log(1+vals[1]);
  vals[2] = target/log(1+vals[2]);
}

void modulus_in_real(long double *data, int lenf){
  int iter;
  for(iter=0; iter<3*lenf*lenf; iter++){
    data[2*iter]    = sqrt(data[2*iter]*data[2*iter]+data[2*iter+1]*data[2*iter+1]);
    data[2*iter+1]  = 0.;
  }
}

void log_norm_real_rgb(int comp, long double *data, int lenf, long double valu){
  int iter;
  data+=2*comp;
  for(iter=0; iter<lenf*lenf; iter++){
    data[6*iter] = valu*log(1+data[6*iter]);
  }
}

void log_norm_real(long double *data, int lenf, long double *valu){
  log_norm_real_rgb(0, data, lenf, valu[0]);
  log_norm_real_rgb(1, data, lenf, valu[1]);
  log_norm_real_rgb(2, data, lenf, valu[2]);
}
