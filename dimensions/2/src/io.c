#include "io.h"
#include <stdio.h>
#include <stdlib.h>

long double** read(char *src, int *L){
  long double **data;
  FILE *in;
  int it;
  in = fopen(src, "r");
  fscanf(in, "%d", L);
  data = (long double**) calloc(*L, sizeof(long double*));
  *data = (long double*) calloc(*L**L, 2*sizeof(long double));
  for(it=0; it < *L**L; it++){
    fscanf(in, "%Lf", *data+2*it);
    data[0][2*it+1]=0;
  }
  fclose(in);
  for(it=1; it < *L; it++)
    data[it]=data[it-1]+*L*2*sizeof(long double);
  return data;
}

void write(char *dst, int L, long double **dft){
  FILE* out;
  int it;
  out = fopen(dst, "w");
  fprintf(out, "%d\n", L);
  for(it=0; it < 2*L*L; it+=2)
    fprintf(out, "(%6.2Lf, %6.2Lf)%c", it[*dft], (it+1)[*dft], it/2%L==L-1 ? '\n' : ' ');
  fclose(out);
}
