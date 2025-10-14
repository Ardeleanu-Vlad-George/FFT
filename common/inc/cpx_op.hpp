/**
  * \file
  * \brief Treat two consecutive values in an array of long doubles as a complex number.
    All functions implement just one operation between complex numbers.
    All functions receive as first argument the pointer in which to save the result.
    All functions return this address at the end of execution.
    Additional addresses are given as inputs, their number based on the operation itself.
    All functions represent operations simple enough that their implementation is self-evident.
    Thus, no further comments are required for explaining the code.
*/

#ifndef _CPX_OP_HPP_
#define _CPX_OP_HPP_

extern "C" long double* add(long double*, long double*, long double*);
/**
* \brief 'tms' is shorthand for 'times'
*/
extern "C" long double* tms(long double*, long double*, long double*);
/**
* \brief 'asn' is shorthand for 'assign'
*/
extern "C" long double* asn(long double*, long double*);

#endif//_CPX_OP_HPP_
