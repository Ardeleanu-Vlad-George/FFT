#include "fft_post_comp.h"

void scale(double *data, int lenf, double valu){
  int iter;
  for(iter=0; iter<lenf; iter++)
    data[iter] /= valu;
}

void nyquist_arrange(double *data, int lenf){
  double temp;
  int iter;
  for(iter=0; iter<lenf/2; iter++){
    temp              = data[iter];
    data[iter]        = data[iter+lenf/2];
    data[iter+lenf/2] = temp;
  }
}
