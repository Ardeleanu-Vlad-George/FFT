#include "io.h"
#include "fft_comp.h"
#include "fft_prep_cpx.h"
#include "fft_prep_bit.h"
#include <stdlib.h>

int main(){
    int LEN, PWR;
    double *VCT, *RTS;
    
    VCT = read("data/in", &LEN);
    PWR = getexp(LEN);
    RTS = every_rou(LEN);

    fft_order(LEN, PWR, VCT);
    fft_apply(LEN, PWR, VCT, RTS);

    write("data/out", LEN, VCT);

    free(VCT);
    free(RTS);
    return 0;
}
