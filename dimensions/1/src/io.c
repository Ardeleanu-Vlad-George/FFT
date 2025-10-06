#include "io.h"
#include <stdio.h>
#include <stdlib.h>

double* read(char *src, int *L){
    double *data;
    FILE *in;
    int it;
    in = fopen(src, "r");
    fscanf(in, "%d", L);
    data = (double*) calloc(*L, 2*sizeof(double));
    for(it=0; it < *L; it++){
        fscanf(in, "%lf", data+2*it);
        data[2*it+1]=0;
    }
    fclose(in);
    return data;
}

void write(char *dst, int L, double *dft){
    FILE* out;
    int it;
    out = fopen(dst, "w");
    fprintf(out, "%d\n", L);
    for(it=0; it < L; it++)
        fprintf(out, "(%lf,%lf)\n", dft[2*it], dft[2*it+1]);
    fclose(out);
}
