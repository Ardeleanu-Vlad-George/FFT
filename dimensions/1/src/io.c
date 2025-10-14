#include "io.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long double* read(char *src, int *L){
    long double *data;
    FILE *in;
    int it;
    in = fopen(src, "r");
    fscanf(in, "%d", L);
    data = (long double*) calloc(*L, 2*sizeof(long double));
    for(it=0; it < *L; it++){
        fscanf(in, "%Lf", data+2*it);
        data[2*it+1]=0;
    }
    fclose(in);
    return data;
}

void write(char *dst, int L, long double *dft){
    FILE* out;
    int it;
    out = fopen(dst, "w");
    fprintf(out, "%d\n", L);
    for(it=0; it < L; it++)
        fprintf(out, "(%Lf,%Lf)\n", roundl(dft[2*it]), roundl(dft[2*it+1]));
    fclose(out);
}
