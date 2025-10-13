#ifndef _BTR_FLY_HPP_
#define _BTR_FLY_HPP_

//Apply the butterfly schema to a pair or a sequence, 
//the numbers are expected to be complex, 
//that is achieved in the current project by using 
//two consecutive elements in an array of doubles
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
void comp_pair(double*, double*, double*, double*);

void comp_seqn(int, double*, int, double*, int, double*, int, double*, int);

#endif//_BTR_FLY_HPP_
