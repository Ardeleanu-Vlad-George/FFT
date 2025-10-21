#include <cstdio>
#include <cstdlib>
#include "io.hpp"
#include "fft_prep_cpx_nr.hpp"
#include "fft_comp.hpp"
#include "fft_prep_bit.hpp"
#include "fft_prep_cpx_fn.hpp"
#include "fft_post_comp.hpp"


int main(int argc, char* argv[]){
  double *data;
  double log_const[3];
  double *ruts;
  int size, powr;
  char *name; //this one will point to the name of the file
  data = read(argv[1], &size, &name);
  ruts = every_rou(size);
  powr = getexp(size);
  fft_order(size, powr, data);
  fft_apply(size, powr, data, ruts);
  modulus_in_real(data, size);
  set_max_vals(data, size, log_const);
  const_from_max(TARGET_VALUE, log_const);
  nyquist_arrange(data, size);
  log_norm_real(data, size, log_const);

  write("FFT_of_", name, size, data);

  free(ruts);
  free(data);
  return 0;
}
