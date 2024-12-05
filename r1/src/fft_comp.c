#include "fft_comp.h"
#include "fft_prep_bit.h"
#include "fft_prep_cpx.h"
#include "cpx_op.h"

void fft_order(int nr, int pwr, double *vct){
  int it;
  double buff[2*nr];

  for(it=0; it < nr; it++)
    asn(buff+2*it, vct+2*it);

  for(it=0; it < nr; it++)
    asn(vct+2*it, buff+2*revidx(it, pwr));
}
/**
 * The simpliest way to imagine the butterfly schema is like this: let there be two variables, 
 * a and b, a gets assigned a+b and b get assigned a+b. And that's it! Yes, this is to simple
 * so the next variant is where the second member is multiplied by two different numbers, one 
 * for the equation that get's assigned to a and another for the one gets assigned to b.
 * This is the more common, non uniform version of the butterfly schema:
 * a <- a+b*x, and
 * b <- a+b*y, where x and y are already chosen numbers
 * Let's call the first term even and the scond one uneven
 * And let's call the coeficients just the same, the one involved in the equation assigned to even
 * is 'even's coeficient', the other one is uneven coeficient
*/

void butterfly(double *even, double *uneven, double *even_coef, double *uneven_coef){
  //first two belong to the even number, second two to the uneven one
  //last two to the term obtained by multiplying the uneven number 
  double cache[6];
  asn(cache, even);
  asn(cache+2, uneven);
  add(
    even, cache, tms(
      cache+4, cache+2, even_coef
    )
  );
  add(
    uneven, cache, tms(
      cache+4, cache+2, uneven_coef
    )
  );
}
/**
    __OBS__:
    This is the most important function in the whole program, the namesake of the project.
    It's paramount that the explanation is clear and thoughtful.
    
    __Variables__:
    @nr <-> the length of the complex vector
    @pwr <-> the logarithm of 2 of 'nr'
    @vct <-> the complex vector

    __Implement__:
    There are two aspects of it that should be clarified:
    1. the layer structure,
    2. the BFS (ButterFly Schema).
    
    Both are explained in the following subsections.  
    
    __Layers__:
    The FFT could be seen as applying the BFS multiple times, until we reach the desired result. 
    A classic BFS has inputs and outputs, here multiple BFSs will be grouped in a _layer_, it's compounded outputs being fed into the inputs of a similar _layer_.
    This gives the algorithm's layered aspect, the input of the first layer being 'vct' and the output of the final layer being the computed FFT.
    Each layer of schemas (SL - Schema Layer) has a corresponding layer of numbers at input (NL - Number Layer), forming together a WL (Whole Layer).
    Each NL will be  
    


    The following explanation for the layer structure is inspired by the one found in 'docu/link/FAST_FOURIER_TRANSFORM.pdf', especially the schema 
    Layer structure: 
    - the computations can be viewed as a process that feeds information from one layer to the next, each layer having 'nr'
    
    , the butterfly computations
    
    , explained 
*/

void fft_apply(int nr, int pwr, double *vct, double *rts){
  double *rtEvn, *rtOdd;
        
  int layer, seqLn, pwStp;
  int elmId, seqId;
  double *oddOut, *evnOut,
         oddInp[2], evnInp[2],
         temp[2];
  int oddId, evnId;

  for(
    layer=0, seqLn=1, pwStp=nr/2;
    layer < pwr;
    layer++, seqLn*=2, pwStp/=2
  )for(seqId=0; seqId < nr/seqLn; seqId+=2)
    for(elmId=0; elmId < seqLn; elmId++){
      evnId = seqId*seqLn+elmId;
      asn(evnInp, vct+2*evnId);
      evnOut = vct+2*evnId;
      rtEvn = rts+((evnId*pwStp)%nr)*2;

      oddId = evnId+seqLn;
      asn(oddInp, vct+2*oddId);
      oddOut = vct+2*oddId;
      rtOdd = rts+((oddId*pwStp)%nr)*2;

      add( evnOut, evnInp,
        tms( temp, oddInp, rtEvn)
      );

      add( oddOut, evnInp,
        tms( temp, oddInp, rtOdd)
      );
    }
}
