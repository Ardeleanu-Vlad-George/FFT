# Just some words in the README.md
Trying to stich together different FFT projects for better code organization.
Files marked for 'common':
```
Files dimensions/1/src/btr_fly.c and dimensions/2/src/btr_fly.c are identical
Files dimensions/1/src/fft_prep_bit.c and dimensions/2/src/fft_prep_bit.c are identical
Files dimensions/1/src/fft_prep_cpx.c and dimensions/2/src/fft_prep_cpx.c are identical
Files dimensions/1/src/cpx_op.c and dimensions/2/src/cpx_op.c are identical
Files dimensions/1/inc/cpx_op.h and dimensions/2/inc/cpx_op.h are identical
Files dimensions/1/inc/fft_prep_bit.h and dimensions/2/inc/fft_prep_bit.h are identical
Files dimensions/1/inc/fft_prep_cpx.h and dimensions/2/inc/fft_prep_cpx.h are identical
8,18d7
< /**
<  * Consider the next equations making up the butterfly schema:
<  * a <- a+b*x
<  * b <- a+b*y
<  * The 'a' term doesn't have it's own coeficients, it is uniform.
<  * The 'b' term does have them so let's call ne-uniform.
<  * The two equations have similar names based on the variable to which
<  * they are assigned, the coeficients have similar names
<  * In order to have notations easy to align, this program uses
<  * 'oonn' for 'UNiform' and 'neun' for 'ne-uniform'
< */
Decided to keep file from one-dimensional
