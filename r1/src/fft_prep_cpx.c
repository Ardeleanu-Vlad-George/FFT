#include "fft_prep_cpx.h"
#include "cpx_op.h"
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535

void first_rou(int grade, double *data){
  data[0]=cos(-2*PI/grade);
  data[1]=sin(-2*PI/grade);
}

double* every_rou(int grade){
    double *roots=(double*)calloc(grade, 2*sizeof(double));
    int it;
    roots[0]=1.; 
    roots[1]=0.;
    first_rou(grade, roots+2);
    for(it=4; it<2*grade; it+=2)
        tms(roots+it, roots+it-2, roots+2);
    return roots;
}
