#ifndef _TEMP_DEFS_H
#define _TEMP_DEFS_H

/*#define PI            3.1415926535*/
//#define PI 3.14
#define PI 3.1415926535897932385

#define SIGN 1

#endif//_TEMP_DEFS
/**
  * \file
  * \brief Just define some constants that the whole program needs
    Define the following constants:
    - PI    - the value of the constant pi
    - SIGN  - it influences what kind of definition is used for the
    first root of unity, which influences the order in which the 
    roots appear. To be more explicit, some complex roots don't 
    appear all by themselves, their conjugate (number with the 
    same real part but opposite sign for the imaginary part)
    appears also.
    If C is (1, 2), conjugate of C is (1, -2). 
    Changing the SIGN, than changes the definition, which 
    switches the conjugates among themselves.
    - TARGET_VALUE - is the value obtained for Nyquist after 
    applying the logarithmic normalization
*/

#ifndef _DEFS_H_
#define _DEFS_H_


#define SIGN          1

#define TARGET_VALUE  255.

#endif//_DEFS_H_
