/**
    \file io.h
    \brief Module is responsible for program's specific I/O operations
    No checks are performed testing the file's existence or not, it's assumed to be
    true.
    There are 2 functions: one for reading the input vector and one for writing the 
    resulting DFT.
*/

#ifndef _IO_H_
#define _IO_H_

/**
    \brief Read from file the input vector, give back vector of complex doubles
    In this project a complex double is made from two consecutive doubles in an
    array.
    @param file [in] - the name of the input file
    @param length [out] - the address at which the size of the vector will be saved
    \return array of read values as 'complex doubles', needs to be freed by the user
*/
double* read(char*, int*);

/**
    \brief Write vector of complex doubles representing the DFT
    In this project a complex double is made from two consecutive doubles in an
    array.
    @param file [in] - the name of the output file
    @param size [in] - length of the result to be printed
    @param result [in] - result to be printed
*/
void write(char*, int, double*);

#endif//_IO_H_
