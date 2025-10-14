#ifndef _BTR_FLY_H_
#define _BTR_FLY_H_

//Apply the butterfly schema to a pair or a sequence, 
//the numbers are expected to be complex, 
//that is achieved in the current project by using 
//two consecutive elements in an array of long doubles
/**
 * Consider the next equations making up the butterfly schema:
 * a <- a+b*x
 * b <- a+b*y
 * The 'a' term doesn't have it's own coeficients, it is uniform.
 * The 'b' term does have them so let's call ne-uniform.
 * The two equations have similar names based on the variable to which
 * they are assigned, the coeficients have similar names
 * In order to have notations easy to align, this program uses
 * 'oonn' for 'UNiform' and 'neun' for 'ne-uniform'
*/
void comp_pair(long double*, long double*, long double*, long double*);

void comp_seqn(int, long double*, int, long double*, int, long double*, int, long double*, int);

#endif//_BTR_FLY_H_
